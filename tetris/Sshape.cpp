#include "Sshape.h"
#include "graphics.h"

Sshape::Sshape()
{
	stateOfTetrimino_ = FALLING;
	outlineColor_ = WHITE;
	fillColor_ = COLOR(255, 0, 255);
	orientation_ = LEFT;
	square_[0] = Square(5, 1, fillColor_, outlineColor_); //  ***  -->    *  -->    *			**
	square_[1] = Square(5, 2, fillColor_, outlineColor_); //    *		   *	   *** -->     *
	square_[2] = Square(4, 2, fillColor_, outlineColor_); //		      **			       	* 
	square_[3] = Square(6, 1, fillColor_, outlineColor_);
}
Sshape::Sshape(int x, int y)
{
	stateOfTetrimino_ = FALLING;
	outlineColor_ = WHITE;
	fillColor_ = COLOR(255, 0, 255);
	orientation_ = LEFT;
	square_[0] = Square(5+x, 1+y, fillColor_, outlineColor_); //  ***  -->    *  -->    *			**
	square_[1] = Square(5+x, 2+y, fillColor_, outlineColor_); //    *		   *	   *** -->     *
	square_[2] = Square(4+x, 2+y, fillColor_, outlineColor_); //		      **			       	* 
	square_[3] = Square(6+x, 1+y, fillColor_, outlineColor_);
}
void Sshape::rotateCW()
{
	switch (orientation_)
	{
	case LEFT:
		square_[1].setX(square_[0].getX() - 1); //goes to up
		square_[1].setY(square_[0].getY());
		square_[2].setX(square_[0].getX() - 1);
		square_[2].setY(square_[0].getY() - 1);
		square_[3].setX(square_[0].getX());
		square_[3].setY(square_[0].getY() + 1);
		break;
	case RIGHT:
		square_[1].setX(square_[0].getX() - 1); //goes to up
		square_[1].setY(square_[0].getY());
		square_[2].setX(square_[0].getX() - 1);
		square_[2].setY(square_[0].getY() - 1);
		square_[3].setX(square_[0].getX());
		square_[3].setY(square_[0].getY() + 1);
		break;
	case DOWN:
		square_[1].setX(square_[0].getX()); // orients sideways
		square_[1].setY(square_[0].getY() + 1);
		square_[2].setX(square_[0].getX() - 1);
		square_[2].setY(square_[0].getY() + 1);
		square_[3].setX(square_[0].getX() + 1);
		square_[3].setY(square_[0].getY());
		break;
	case UP:
		square_[1].setX(square_[0].getX()); // orients sideways
		square_[1].setY(square_[0].getY() + 1);
		square_[2].setX(square_[0].getX() - 1);
		square_[2].setY(square_[0].getY() + 1);
		square_[3].setX(square_[0].getX() + 1);
		square_[3].setY(square_[0].getY());
		break;
	}
}
void Sshape::rotateCCW()
{
	switch (orientation_)
	{
	case LEFT:
		square_[1].setX(square_[0].getX() - 1); //goes to up
		square_[1].setY(square_[0].getY());
		square_[2].setX(square_[0].getX() - 1);
		square_[2].setY(square_[0].getY() - 1);
		square_[3].setX(square_[0].getX());
		square_[3].setY(square_[0].getY() + 1);
		break;
	case RIGHT:
		square_[1].setX(square_[0].getX() - 1); //goes to up
		square_[1].setY(square_[0].getY());
		square_[2].setX(square_[0].getX() - 1);
		square_[2].setY(square_[0].getY() - 1);
		square_[3].setX(square_[0].getX());
		square_[3].setY(square_[0].getY() + 1);
		break;
	case DOWN:
		square_[1].setX(square_[0].getX()); // orients sideways
		square_[1].setY(square_[0].getY() + 1);
		square_[2].setX(square_[0].getX() - 1);
		square_[2].setY(square_[0].getY() + 1);
		square_[3].setX(square_[0].getX() + 1);
		square_[3].setY(square_[0].getY());
		break;
	case UP:
		square_[1].setX(square_[0].getX()); // orients sideways
		square_[1].setY(square_[0].getY() + 1);
		square_[2].setX(square_[0].getX() - 1);
		square_[2].setY(square_[0].getY() + 1);
		square_[3].setX(square_[0].getX() + 1);
		square_[3].setY(square_[0].getY());
		break;
	}
}