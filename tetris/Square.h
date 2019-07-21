#pragma once
#include "Constants.h"


class Square 
{
public:

	Square();
	Square(int x, int y, int fillColor, int outlineColor );

	void moveDOWN();
	void moveLEFT();
	void moveRIGHT();

	void draw() const;

	void setX(int x);
	int getX() const;

	void setY(int y);
	int getY() const;

private:
	int x_;
	int y_;// position of the top left corner
	int outlineColor_;
	int fillColor_;
};
