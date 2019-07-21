#include "Square.h"
#include "Constants.h"
#include "graphics.h"


Square::Square()
{		// 25 pixels for each side
	x_ = 5; // this 5 is the 5th column along the first row of my gamefield
	y_ = 1;// should be randomized to be anywhere along the first row on top of the boundary
	fillColor_ = BLACK;
}
Square::Square(int x, int y, int fillColor, int outlineColor)
{	
		// 25 pixels for each side
	x_ = x; // this 5 is the 5th column along the first row of my gamefield
	y_ = y;// should be randomized to be anywhere along the first row on top of the boundary
	outlineColor_ = outlineColor;
	fillColor_ = fillColor;
}

void Square::moveDOWN()
{
	y_ += 1;
}
void Square::moveLEFT()
{
	x_ -= 1;
}
void Square::moveRIGHT()
{
	x_ += 1;
}
void Square::draw() const
{
	int drawnSquare[8];
	int numberOfVertices = sizeof(drawnSquare) / sizeof(drawnSquare[1]) / 2;
	drawnSquare[0] = SQUARE_WIDTH *x_;
	drawnSquare[1] = SQUARE_WIDTH *y_;

	drawnSquare[2] = SQUARE_WIDTH * x_ + SQUARE_WIDTH;
	drawnSquare[3] = SQUARE_WIDTH *y_;

	drawnSquare[4] = SQUARE_WIDTH *x_ + SQUARE_WIDTH;
	drawnSquare[5] = SQUARE_WIDTH *y_ + SQUARE_WIDTH;

	drawnSquare[6] = SQUARE_WIDTH *x_;
	drawnSquare[7] = SQUARE_WIDTH *y_ + SQUARE_WIDTH;

	setcolor(outlineColor_);
	setfillstyle(SOLID_FILL, fillColor_);
	fillpoly(numberOfVertices, drawnSquare);
}


void Square::setX(int x)
{
	x_ = x;
}
int Square::getX() const
{
	return x_;
}

void Square::setY(int y)
{
	y_ = y;
}

int Square::getY() const
{
	return y_;
}


