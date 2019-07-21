#pragma once
#include "Constants.h"
#include "Square.h"
#include "Tetrimino.h"
#include <vector>

class Background
{
public:
	Background();
	Background(int squareWidth, int topLeftCornerX, int topRightCorner);
	
	// copy constructor to prevent shallor copies of background1 = background2; 
	Background(const Background& background);

	//move constructor 
	Background(Background&& background);
	// copy assignment operator 
	Background& operator=(const Background& background);
	// move assignement operator 
	Background& operator=(Background&& background);

	void gameOverVisual();

	void setGameFieldtoUNOCCUPIED();
	void drawField() const;
	void drawSquares() const;
	void checkFullRows();

	bool canMoveRight(Tetrimino* tetrimino);
	bool canMoveLeft(Tetrimino* tetrimino);
	bool canMoveDown(Tetrimino* tetrimino);

	bool rotatedOver(Tetrimino* tetrimino);

	void clearRow(int rowIndex);
	void moveSquaresDown(int allAboveThisRow);

	void collisionCheck(Tetrimino* tetrimino);
	

	void setStoredRowIndex(int index);
	std::vector<int> getStoredRowIndexVector() const;
	int getStoredRowIndex(int index) const;
	void clearStoredRowIndex();
	void shiftIndices();

	void setGameField(int rowIndex, int columnIndex, GameFieldState state);
	GameFieldState getGameFieldState(int i, int j) const;

	void setStoredSquare(int rowIndex, int columnIndex, Square* Square);
	Square* getStoredSquare(int rowIndex, int columnIndex);
	void clearStoredSquares(); 
	void nullStoredSquaresSpace(int rowIndex, int columnIndex);

	//releases memory allocated to these square pointers
	~Background();

protected:
	int topLeftCornerX_;// position of the top right point of the game field
	int topLeftCornerY_;
	int bottomRightX_;
	int bottomRightY_;
	
	std::vector <int> storedRowIndex_;

	Square* storedSquares_[HEIGHT_GAME_ARENA - 1][WIDTH_GAME_ARENA - 1];
	GameFieldState storedGameField_[HEIGHT_GAME_ARENA-1][WIDTH_GAME_ARENA - 1];
};