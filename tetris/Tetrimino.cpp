#include "Tetrimino.h"
#include "graphics.h"

void Tetrimino::draw() const
{
	for (int i = 0; i < SQUARES_IN_TETRIMINO; i++)
	{
		square_[i].draw();
	}
}

void Tetrimino::moveRight()
{
	for (int i = 0; i < SQUARES_IN_TETRIMINO; i++)
	{
		square_[i].moveRIGHT();
	}
}
void Tetrimino::moveLeft()
{
	for (int i = 0; i < SQUARES_IN_TETRIMINO; i++)
	{
		square_[i].moveLEFT();
	}
}
void Tetrimino::moveDown()
{
	for (int i = 0; i < SQUARES_IN_TETRIMINO; i++)
	{
		square_[i].moveDOWN();
	}
}
void Tetrimino::setOutlineColor(int outlineColor)
{
	outlineColor_ = outlineColor;
}
int Tetrimino::getOutlineColor() const
{
	return outlineColor_;
}

void Tetrimino::setFillColor(int fillColor)
{
	fillColor_ = fillColor;
}
int Tetrimino::getFillColor() const
{
	return fillColor_;
}
void Tetrimino::setOrientation(TetriminoOrientation orientation)
{
	orientation_ = orientation;
}
TetriminoOrientation Tetrimino::getOrientation() const
{
	return orientation_;
}

void Tetrimino::setSquare(const Square& square, int index)
{
	square_[index] = square;
}
Square* Tetrimino::getSquare(int index) 
{
	return &square_[index];
}

int Tetrimino::getSquareX(int index) const
{
	return square_[index].getX();
}
int Tetrimino::getSquareY(int index) const
{
	return square_[index].getY();
}
void Tetrimino::setStateOfTetrimino(TetrisState state)
{
	stateOfTetrimino_ = state;
}
TetrisState Tetrimino::getStateOfTetrimino() const
{
	return stateOfTetrimino_;
}