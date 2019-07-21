#include "Background.h"
#include <vector>
#include "Square.h"
#include "graphics.h"

Background::Background(int squareWIDTH, int topLeftCornerX, int topLeftCornerY)
{
	topLeftCornerX_ = topLeftCornerX;
	topLeftCornerY_ = topLeftCornerY;
	bottomRightX_ = WIDTH_GAME_ARENA;
	bottomRightY_ = HEIGHT_GAME_ARENA;
	

	// initialize the array with UNOCCUPIED state, this fixed the weird problem with a black square being initialized in my stored squares
	setGameFieldtoUNOCCUPIED();
	storedRowIndex_.clear();
}
// copy constructor
Background::Background(const Background& background)
{
	topLeftCornerX_ = background.topLeftCornerX_;// position of the top right point of the game field
	topLeftCornerY_=background.topLeftCornerY_;
	bottomRightX_ = background.bottomRightX_;
	bottomRightY_ = background.bottomRightY_;

	for (int columnIndex = (WIDTH_GAME_ARENA - 2); columnIndex >= 0; columnIndex--)
	{
		for (int rowIndex = (HEIGHT_GAME_ARENA - 2); rowIndex >= 0; rowIndex--)
		{
			storedGameField_[rowIndex][columnIndex] = background.storedGameField_[rowIndex][columnIndex];
		}
	}
	
	for (int columnIndex = (WIDTH_GAME_ARENA - 2); columnIndex >= 0; columnIndex--)
	{
		for (int rowIndex = (HEIGHT_GAME_ARENA - 2); rowIndex >= 0; rowIndex--)
		{
			storedSquares_[rowIndex][columnIndex] = new Square;
			 storedSquares_[rowIndex][columnIndex] = background.storedSquares_[rowIndex][columnIndex] ;
		}
	}
}

//move constructor

Background::Background(Background&& background)
{
	topLeftCornerX_ = background.topLeftCornerX_;// position of the top right point of the game field
	topLeftCornerY_ = background.topLeftCornerY_;
	bottomRightX_ = background.bottomRightX_;
	bottomRightY_ = background.bottomRightY_;

	for (int columnIndex = (WIDTH_GAME_ARENA - 2); columnIndex >= 0; columnIndex--)
	{
		for (int rowIndex = (HEIGHT_GAME_ARENA - 2); rowIndex >= 0; rowIndex--)
		{
			storedGameField_[rowIndex][columnIndex] = background.storedGameField_[rowIndex][columnIndex];
		}
	}


	//copies over the data via shallow copy cuz both pointers are going to be 
	//pointing to the same memory location
	for (int columnIndex = (WIDTH_GAME_ARENA - 2); columnIndex >= 0; columnIndex--)
	{
		for (int rowIndex = (HEIGHT_GAME_ARENA - 2); rowIndex >= 0; rowIndex--)
		{
			storedSquares_[rowIndex][columnIndex] = background.storedSquares_[rowIndex][columnIndex];
		}
	}

	// now I want exclusive access to memory only by 'this'
	// which means that i need to invalidate pointers from background so that I cut off access from source
	for (int columnIndex = (WIDTH_GAME_ARENA - 2); columnIndex >= 0; columnIndex--)
	{
		for (int rowIndex = (HEIGHT_GAME_ARENA - 2); rowIndex >= 0; rowIndex--)
		{
			background.storedSquares_[rowIndex][columnIndex] = nullptr;
		}
	}


}




//copy assignment operator
Background& Background::operator=(const Background& background)
{

	/*like background1 = background2 this is called 
	to delete whatever was inside of background1 and reassign all
	data from background2 into background1
	*/
	// deals with the case of a=a
	if (&background != this)
	{
		// delete 'this' allocated memory
		for (int columnIndex = (WIDTH_GAME_ARENA - 2); columnIndex >= 0; columnIndex--)
		{
			for (int rowIndex = (HEIGHT_GAME_ARENA - 2); rowIndex >= 0; rowIndex--)
			{
				if (storedGameField_[rowIndex][columnIndex] == OCCUPIED)
				{
					delete storedSquares_[rowIndex][columnIndex];
				}
			}
		}

		// code from the copy constructor to copy over the new data 
		topLeftCornerX_ = background.topLeftCornerX_;// position of the top right point of the game field
		topLeftCornerY_ = background.topLeftCornerY_;
		bottomRightX_ = background.bottomRightX_;
		bottomRightY_ = background.bottomRightY_;

		for (int columnIndex = (WIDTH_GAME_ARENA - 2); columnIndex >= 0; columnIndex--)
		{
			for (int rowIndex = (HEIGHT_GAME_ARENA - 2); rowIndex >= 0; rowIndex--)
			{
				storedSquares_[rowIndex][columnIndex] = new Square;
				storedSquares_[rowIndex][columnIndex] = background.storedSquares_[rowIndex][columnIndex];
			}
		}
	}
	return *this;
}
// move assignment operator
Background& Background::operator=(Background&& background)
{
	/* when the right hand side evaluates to an Rvalue
	*/
	if (&background != this)
	{
		// delete 'this' allocated memory (DESTRUCTOR PART)
		for (int columnIndex = (WIDTH_GAME_ARENA - 2); columnIndex >= 0; columnIndex--)
		{
			for (int rowIndex = (HEIGHT_GAME_ARENA - 2); rowIndex >= 0; rowIndex--)
			{
				if (storedGameField_[rowIndex][columnIndex] == OCCUPIED)
				{
					delete storedSquares_[rowIndex][columnIndex];
				}
			}
		}


		//MOVE CONSTRUCTOR PART
		topLeftCornerX_ = background.topLeftCornerX_;// position of the top right point of the game field
		topLeftCornerY_ = background.topLeftCornerY_;
		bottomRightX_ = background.bottomRightX_;
		bottomRightY_ = background.bottomRightY_;

		for (int columnIndex = (WIDTH_GAME_ARENA - 2); columnIndex >= 0; columnIndex--)
		{
			for (int rowIndex = (HEIGHT_GAME_ARENA - 2); rowIndex >= 0; rowIndex--)
			{
				storedGameField_[rowIndex][columnIndex] = background.storedGameField_[rowIndex][columnIndex];
			}
		}

		//copies over the data via shallow copy cuz both pointers are going to be 
		//pointing to the same memory location
		for (int columnIndex = (WIDTH_GAME_ARENA - 2); columnIndex >= 0; columnIndex--)
		{
			for (int rowIndex = (HEIGHT_GAME_ARENA - 2); rowIndex >= 0; rowIndex--)
			{
				storedSquares_[rowIndex][columnIndex] = background.storedSquares_[rowIndex][columnIndex];
			}
		}

		// now I want exclusive access to memory only by 'this'
		// which means that i need to invalidate pointers from background so that I cut off access from source
		for (int columnIndex = (WIDTH_GAME_ARENA - 2); columnIndex >= 0; columnIndex--)
		{
			for (int rowIndex = (HEIGHT_GAME_ARENA - 2); rowIndex >= 0; rowIndex--)
			{
				background.storedSquares_[rowIndex][columnIndex] = nullptr;
			}
		}
	}

	return *this;
}

void Background::gameOverVisual()
{
	for (int i = 0; i < (HEIGHT_GAME_ARENA - 1); i++)
	{
		for (int j = 0; j < (WIDTH_GAME_ARENA - 1); j++)
		{
			delay(7);
			Square* deepCopy = new Square;
			*deepCopy = Square(j + 1, i + 1, BLACK, WHITE);
			setStoredSquare(i, j, deepCopy);
			getStoredSquare(i, j)->draw();
		}
	}
}

void Background::setGameFieldtoUNOCCUPIED()
{
	for (int i = 0; i < (HEIGHT_GAME_ARENA - 1); i++)
	{
		for (int j = 0; j < (WIDTH_GAME_ARENA - 1); j++)
		{
			storedGameField_[i][j] = UNOCCUPIED;
		}
	}
}

void Background::drawField() const
{
	setcolor(WHITE);
	setfillstyle(SOLID_FILL, BLUE);
	bar(topLeftCornerX_*SQUARE_WIDTH, topLeftCornerY_*SQUARE_WIDTH, bottomRightX_*SQUARE_WIDTH, bottomRightY_*SQUARE_WIDTH);
}

void Background::drawSquares() const
{
	for (int columnIndex = (WIDTH_GAME_ARENA - 2); columnIndex >= 0; columnIndex--)
	{
		for (int rowIndex = (HEIGHT_GAME_ARENA - 2); rowIndex >= 0; rowIndex--)
		{
			if (storedGameField_[rowIndex][columnIndex] == OCCUPIED) // this draws all elements in stored vectors that correspond to the field
																	// via the matching indices
			{
				storedSquares_[rowIndex][columnIndex]->draw();
			}
		}
	}
}

void Background::checkFullRows() 
{
	int occuranceCountRowWise = 0;

	for (int i = 0; i < (HEIGHT_GAME_ARENA - 1); i++) 
	{// in this scope we increment row wise

		for (int j = 0; j <(WIDTH_GAME_ARENA - 1); j++) 
		{// in this scope we increment column wise

			if (getGameFieldState(i, j) == OCCUPIED)
			{// check state of each block space. and keep count of OCCUPIED spaces for the current row
				occuranceCountRowWise++;
			}
		}

		if (occuranceCountRowWise == (WIDTH_GAME_ARENA - 1))
		{// if the count is 10 (or the whole row is occupied), then save the indexed row number for deletion. 
			setStoredRowIndex(i);
		}
		// once we finish checking the current row we 
		//reset the count to start checking the next row
		occuranceCountRowWise = 0;
	}
}
bool Background::canMoveRight(Tetrimino* tetrimino)
{
	for (int i = 0; i < SQUARES_IN_TETRIMINO; i++)
	{

		if (
			// this catches the boarders
			( tetrimino->getSquare(i)->getX() >= WIDTH_GAME_ARENA - 1) // if the square plus one square width is over the boarder

			||
			
			(getGameFieldState(tetrimino->getSquareY(i) - 1, tetrimino->getSquareX(i)) == OCCUPIED) // if the square to the right of this one is occupying the space
			// this catches the other squares, by checking the states that I am storing in GameField
			)
		{
			return false;
		}

	}
	return true;

}

bool Background::canMoveLeft(Tetrimino* tetrimino)
{
	for (int i = 0; i < SQUARES_IN_TETRIMINO; i++)
	{
		if ((tetrimino->getSquare(i)->getX() <= 1) // if the current square is at the edge of the field
			||
			(getGameFieldState(tetrimino->getSquareY(i) - 1, tetrimino->getSquareX(i) - 2) == OCCUPIED)// if there is an occupied state to the left of current square
			)
		{
			return false;
		}
	}
	return true;
}

bool Background::canMoveDown(Tetrimino* tetrimino)
{
	for (int i = 0; i < SQUARES_IN_TETRIMINO; i++)
	{
		if ((tetrimino->getSquare(i)->getY() + 1 >= HEIGHT_GAME_ARENA) // if the square plus one square width is over the boarder
			||
			(getGameFieldState(tetrimino->getSquareY(i), tetrimino->getSquareX(i) - 1) == OCCUPIED)
			)
		{
			return false;
		}
	}
	return true;
}

bool Background::rotatedOver(Tetrimino* tetrimino)
{
	for (int i = 0; i < SQUARES_IN_TETRIMINO; i++)
	{
		if (tetrimino->getSquare(i)->getX() < 1
			||
			(tetrimino->getSquare(i)->getY() + 1 >= HEIGHT_GAME_ARENA)
			||
			(tetrimino->getSquare(i)->getX() > WIDTH_GAME_ARENA - 1)
			||
			
			(getGameFieldState(tetrimino->getSquareY(i) - 1, tetrimino->getSquareX(i) - 1) == OCCUPIED)
			)
		{
			return true;
		}

	}
	return false; 

}
void Background::clearRow(int rowindex)
{
	for (int columnIndex = 0; columnIndex < (WIDTH_GAME_ARENA - 1); columnIndex++)
	{ 
		setGameField(rowindex, columnIndex, UNOCCUPIED);
		delete storedSquares_[rowindex][columnIndex];
		nullStoredSquaresSpace(rowindex, columnIndex);
	}
}

void Background::moveSquaresDown(int allAboveThisRow)
{
	for (int rowIndex = allAboveThisRow - 1; rowIndex >= 0; rowIndex--)
	{
		for (int columnIndex = 0; columnIndex < WIDTH_GAME_ARENA - 1; columnIndex++)
		{

			if (getGameFieldState(rowIndex, columnIndex) == OCCUPIED) //&& (storedRowIndex_[i] <= rowIndex))
			{

				getStoredSquare(rowIndex, columnIndex)->setY(getStoredSquare(rowIndex, columnIndex)->getY() + 1);
				setStoredSquare(rowIndex + 1, columnIndex, getStoredSquare(rowIndex, columnIndex));
				delete storedSquares_[rowIndex][columnIndex];
				nullStoredSquaresSpace(rowIndex, columnIndex);
				setGameField(rowIndex, columnIndex, UNOCCUPIED);
				setGameField(rowIndex + 1, columnIndex, OCCUPIED);
				
			}
		}
	}

}	

void Background::collisionCheck(Tetrimino* tetrimino)
{
	for (int i = 0; i < SQUARES_IN_TETRIMINO; i++)
	{
		for (int j = 0; j < (HEIGHT_GAME_ARENA - 1); j++)
		{
			for (int k = 0; k < (WIDTH_GAME_ARENA - 1); k++)
			{
				if (getGameFieldState(j, k) == OCCUPIED)
				{
					if (
						(tetrimino->getSquare(i)->getY() + 1) == (getStoredSquare(j, k)->getY())
						&&
						(tetrimino->getSquare(i)->getX() == getStoredSquare(j, k)->getX()))
					{
						tetrimino->setStateOfTetrimino(HIT);
					}
				}
				if ((tetrimino->getSquare(i)->getY() + 1) == HEIGHT_GAME_ARENA)
				{
					tetrimino->setStateOfTetrimino(HIT);
				}
			}

		}
	}
}





void Background::setStoredRowIndex(int index)
{
	storedRowIndex_.push_back(index);
}
std::vector<int> Background::getStoredRowIndexVector() const
{
	return storedRowIndex_;
}
int Background::getStoredRowIndex(int index) const
{
	return storedRowIndex_[index];
}

void Background::clearStoredRowIndex()
{
	storedRowIndex_.clear();
}
void Background::shiftIndices()
{
	for (int i = 0; i < storedRowIndex_.size(); i++)
	{
		storedRowIndex_[i] += 1;
	}
}

// goes into a vector and returns the value depending on your index
void Background::setGameField(int i, int j, GameFieldState state)
{
	storedGameField_[i][j] = state;
}
GameFieldState Background::getGameFieldState(int i, int j) const
{
	return storedGameField_[i][j];
}



void Background::setStoredSquare(int rowIndex, int columnIndex, Square* square)
{
	Square* deepCopy = new Square;
	*deepCopy = *square;
	storedSquares_[rowIndex][columnIndex] = deepCopy;


}
Square* Background::getStoredSquare(int rowIndex, int columnIndex)
{
	return storedSquares_[rowIndex][columnIndex];
}

void Background::clearStoredSquares()
{
	for (int columnIndex = (WIDTH_GAME_ARENA - 2); columnIndex >= 0; columnIndex--)
	{
		for (int rowIndex = (HEIGHT_GAME_ARENA - 2); rowIndex >= 0; rowIndex--)
		{
			
			storedSquares_[rowIndex][columnIndex] = nullptr;
		}
	}
}

void Background::nullStoredSquaresSpace(int rowIndex, int columnIndex)
{
	storedSquares_[rowIndex][columnIndex] = nullptr;
}

Background::~Background()
{
	for (int columnIndex = (WIDTH_GAME_ARENA - 2); columnIndex >= 0; columnIndex--)
	{
		for (int rowIndex = (HEIGHT_GAME_ARENA - 2); rowIndex >= 0; rowIndex--)
		{
			delete storedSquares_[rowIndex][columnIndex];
		}
	}
}