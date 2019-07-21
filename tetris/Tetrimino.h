#pragma once 
#include "Square.h"

class Tetrimino
{
public:

	virtual void rotateCW()  = 0;
	virtual void rotateCCW()  = 0;
	void draw() const;

	void moveRight();
	void moveLeft();
	void moveDown(); 

	void setOutlineColor(int outlineColor);
	int getOutlineColor() const;

	void setFillColor(int fillColor);
	int getFillColor() const; 
	
	void setOrientation(TetriminoOrientation orientation);
	TetriminoOrientation getOrientation() const;

	void setSquare(const Square& square, int index);
	Square* getSquare(int index); // returns pointer to the square object

	int getSquareX(int index) const;
	int getSquareY(int index) const;

	void setStateOfTetrimino(TetrisState state);
	TetrisState getStateOfTetrimino() const;


protected:
	Square square_[SQUARES_IN_TETRIMINO];
	TetriminoOrientation orientation_;
	TetrisState stateOfTetrimino_;
	int outlineColor_;
	int fillColor_;
};