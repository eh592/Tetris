#include "graphics.h"
#include "Tetrimino.h"
#include "Timer.h"
#include "Constants.h"
#include "Background.h"
#include "Square.h"
#include "PreviewBox.h"
#include "Jshape.h"
#include "Lshape.h"
#include "Zshape.h"
#include "Sshape.h"
#include "Oshape.h"
#include "Ishape.h"
#include "Tshape.h"
#include <string>
#include "Menu.h"

using namespace std;

Tetrimino* makeTetrimino(Tetrimino* tetrimino, int randomizedTetrimino);
void userInteraction(Tetrimino* tetrimino, Background& background, char keyInput);
void storeTetriminoSquareInfo(Tetrimino* tetrimino, Background& background);
void collisionCheck(Tetrimino* tetrimino, Background& background,Timer& tetriminoTimer);
void rotationOverlapAdjustment(Tetrimino* tetrimino, Background& background, char keyInput);
void drawScoreBoard(int data[]);// I chose to do the text in main
void outGameOverText();
bool gameIsOver(Background& background);

int main()
{
	srand(GetTickCount());
	Tetrimino* tetrimino = nullptr;
	Timer currentTetriminoTimer;
	Background background(SQUARE_WIDTH, 1, 1);
	Menu menu;

	char keyInput = NULL;
	int page = 0;
	int randomizedTetrimino = 0;
	bool gameOver = false;
	double dropDelay = 1;
	int DataLines[3] = { 1, 0, 0 };

		// [0] = LEVEL
		// [1] = LINES CLEARED
		// [2] = SCORE

	randomizedTetrimino = rand() % 7;
	PreviewBox preview(randomizedTetrimino);
	tetrimino = makeTetrimino(tetrimino, randomizedTetrimino);
	background.setGameFieldtoUNOCCUPIED();
	initwindow(WINDOW_WIDTH, WINDOW_HEIGHT);

	while (keyInput != ESC && !gameOver)
	{	
		if (tetrimino->getStateOfTetrimino() == HIT)
		{
			// takes my the tetrimino in play and stores it into the background, once it hits something
			storeTetriminoSquareInfo(tetrimino, background);

			// loops thru my storedgamefield states to check for a full row of occupied
			background.checkFullRows();

			// if there is row(s) indices that are stored for deletion
			if (background.getStoredRowIndexVector().size() > 0)
			{
				for (int i = background.getStoredRowIndexVector().size() - 1; i >= 0; i--)
				{
					//move thru my stored indices to delete one row at a time and shift down one row at a time

					background.clearRow(background.getStoredRowIndex(i));
					background.moveSquaresDown(background.getStoredRowIndex(i));

					// this properly adjusts my stored indices such that after deletion and shift, 
					// the next loop will perform (deleting and shifting) correctly on the desired rows

					background.shiftIndices();
					DataLines[1] += 1;
					if (DataLines[1] % 10 == 0)
					{
						if (DataLines[2] == 0)
						{
							dropDelay -= 0.25;
						}
						if (DataLines[2] >= 1)
						{
							dropDelay -= 0.1;
						}
						DataLines[0]++;
					}
				}
				//change scores and lines cleared after row deletion
				DataLines[2] += (background.getStoredRowIndexVector().size()) * 50;
				// this sets my vector of stored indices to zero after delelting is done
				background.clearStoredRowIndex();
			}

			// make new tetrimino 
			tetrimino = makeTetrimino(tetrimino, randomizedTetrimino);
			currentTetriminoTimer.reset();
			randomizedTetrimino = rand() % 7;
		}


		keyInput = NULL;
		while (kbhit())
		{
			keyInput = getch();
			userInteraction(tetrimino, background, keyInput);
		}
		if ((currentTetriminoTimer.checkBlockTimer() >= dropDelay)
			&& (tetrimino->getStateOfTetrimino() != HIT) )

		{
			tetrimino->moveDown();
			currentTetriminoTimer.reset();
		}
		if (background.rotatedOver(tetrimino))
		{
			rotationOverlapAdjustment(tetrimino, background, keyInput);
		}
		// draws stuff

		setactivepage(page);
		cleardevice();
		background.drawField();
		background.drawSquares();
  		tetrimino->draw();
		drawScoreBoard(DataLines);
		//preview.drawBox();
		//preview.selectNewTetrimino(randomizedTetrimino);
		//preview.drawNextTetrimino();
		
		setvisualpage(page);
		page = !page;


		// after one second check if there has been a collision
		if (currentTetriminoTimer.checkBlockTimer() >= dropDelay)
		{
			background.collisionCheck(tetrimino);
		}

		if (gameIsOver(background))
		{
			gameOver = true;
		}

	}
	background.clearStoredSquares();
	delete tetrimino;
	outGameOverText();
	background.gameOverVisual();

	delay(100);
	return 0;
}

Tetrimino* makeTetrimino(Tetrimino* tetrimino, int randomizedTetrimino)
{
	delete tetrimino;
	switch (randomizedTetrimino)
	{
	case 0:
		tetrimino = new Oshape();
		break;
	case 1:
		tetrimino = new Jshape();
		break;
	case 2:
		tetrimino = new Sshape();
		break;
	case 3:
		tetrimino = new Ishape();
		break;
	case 4:
		tetrimino = new Tshape();
		break;
	case 5:
		tetrimino = new Zshape();
		break;
	case 6:
		tetrimino = new Lshape();
		break;
	}
	return tetrimino;
}

void storeTetriminoSquareInfo(Tetrimino* tetrimino, Background& background)
{
	for (int i = 0; i < SQUARES_IN_TETRIMINO; i++)
	{
		background.setGameField(tetrimino->getSquareY(i) - 1, tetrimino->getSquareX(i) - 1, OCCUPIED);
		background.setStoredSquare(tetrimino->getSquareY(i) - 1, tetrimino->getSquareX(i) - 1, tetrimino->getSquare(i));
	}
}

void userInteraction(Tetrimino* tetrimino, Background& background, char keyInput)
{
	switch (keyInput)
	{
	case SPACE:
		while ((background.canMoveDown(tetrimino)))
		{
			tetrimino->moveDown();
		}
		tetrimino->setStateOfTetrimino(HIT);
		break;
	case ARROW_DOWN:
		if (background.canMoveDown(tetrimino))
		{
			tetrimino->moveDown();
		}
		break;
	case ARROW_RIGHT:
		if (background.canMoveRight(tetrimino))
		{
			tetrimino->moveRight();
		}
	
		break;
	case ARROW_LEFT:
		if (background.canMoveLeft(tetrimino))
		{
			tetrimino->moveLeft();
		}
		break;
	case ARROW_UP: // processes the rotation according 
		//to the current rotation state, then rotates and sets the appropriate orientation
		switch (tetrimino->getOrientation())
		{
		case UP:
			tetrimino->rotateCW();
			// if the rotated tetrimino exceeds the bounds then rotate back CCW
			tetrimino->setOrientation(RIGHT);
			break;
		case DOWN:
			tetrimino->rotateCW();
			tetrimino->setOrientation(LEFT);
			break;
		case RIGHT:
			tetrimino->rotateCW();
			tetrimino->setOrientation(DOWN);
			break;
		case LEFT:
			tetrimino->rotateCW();
			tetrimino->setOrientation(UP);
			break;
		}
		break;
	case Z_KEY: // counterclockwise

		switch (tetrimino->getOrientation())
		{
		case UP:
			tetrimino->rotateCCW();
			tetrimino->setOrientation(LEFT);
			break;
		case DOWN:
			tetrimino->rotateCCW();
			tetrimino->setOrientation(RIGHT);
			break;
		case RIGHT:
			tetrimino->rotateCCW();
			tetrimino->setOrientation(UP);
			break;
		case LEFT:
			tetrimino->rotateCCW();
			tetrimino->setOrientation(DOWN);
			break;
		}
		break;
	}
}

void rotationOverlapAdjustment(Tetrimino* tetrimino, Background& background, char keyInput)
{
	if (background.rotatedOver(tetrimino))
	{
		switch (tetrimino->getOrientation())
		{
		case RIGHT:
			if (keyInput == ARROW_UP)
			{
				tetrimino->rotateCCW();
				tetrimino->setOrientation(UP);
			}
			if (keyInput == 'z' || keyInput == 'Z')
			{
				tetrimino->rotateCW();
				tetrimino->setOrientation(DOWN);
			}
			break;
		case LEFT:
			if (keyInput == ARROW_UP)
			{
				tetrimino->rotateCCW();
				tetrimino->setOrientation(DOWN);
			}
			if (keyInput == 'z' || keyInput == 'Z')
			{
				tetrimino->rotateCW();
				tetrimino->setOrientation(UP);
			}
			break;
		case UP:
			if (keyInput == ARROW_UP)
			{
				tetrimino->rotateCCW();
				tetrimino->setOrientation(LEFT);
			}
			if (keyInput == 'z' || keyInput == 'Z')
			{
				tetrimino->rotateCW();
				tetrimino->setOrientation(RIGHT);
			}
			break;
		case DOWN:
			if (keyInput == ARROW_UP)
			{
				tetrimino->rotateCCW();
				tetrimino->setOrientation(RIGHT);
			}
			if (keyInput == 'z' || keyInput == 'Z')
			{
				tetrimino->rotateCW();
				tetrimino->setOrientation(LEFT);
			}
			break;

		}
	}
}


void drawScoreBoard(int data[])
{
	int y = SCORE_BOARD_Y_POSITION;
	string MenuLines[3] = { "Level:", "Lines:", "Score:" };
	for (int i = 0; i < 3; i++)// the exit parameter is the number of elements inside of MenuLines
	{
		string temp = to_string(data[i]);
		MenuLines[i] += temp;
		settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
		outtextxy(SCORE_BOARD_X_POSITION, y, const_cast<char*>(MenuLines[i].c_str()));
		y += 50; // to write the text lines out on different lines
	}
}

void outGameOverText()
{
	string gameOver;

	int y = SCORE_BOARD_Y_POSITION;
	setcolor(RED);
	settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 10);

	y += 200; // to place ths GAMEOVER  text below the score board

	outtextxy(SCORE_BOARD_X_POSITION-75, y, "GAME OVER :(");
}
bool gameIsOver(Background& background)
{
	for (int i = 0; i < HEIGHT_GAME_ARENA - 1; i++)
	{
		if (background.getGameFieldState(0, 5) == OCCUPIED)
		{
			return true;
		}
	}
	return false;
}
