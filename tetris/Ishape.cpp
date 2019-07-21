#include "Ishape.h"
#include "graphics.h"

Ishape::Ishape()
{
	stateOfTetrimino_ = FALLING;
	outlineColor_ = WHITE;
	fillColor_ = COLOR(255, 0, 0);
	orientation_ = LEFT;
	square_[0] = Square(5, 1, fillColor_, outlineColor_); //  ***  -->    *  -->    *			**
	square_[1] = Square(6, 1, fillColor_, outlineColor_); //    *		   *	   *** -->     *
	square_[2] = Square(4, 1, fillColor_, outlineColor_); //		      **			       	* 
	square_[3] = Square(3, 1, fillColor_, outlineColor_);
}
Ishape::Ishape(int x, int y)
{
	stateOfTetrimino_ = FALLING;
	outlineColor_ = WHITE;
	fillColor_ = COLOR(255, 0, 0);
	orientation_ = LEFT;
	square_[0] = Square(5 + x, 1 + y, fillColor_, outlineColor_); //  ***  -->    *  -->    *			**
	square_[1] = Square(6 + x, 1 + y, fillColor_, outlineColor_); //    *		   *	   *** -->     *
	square_[2] = Square(4 + x, 1 + y, fillColor_, outlineColor_); //		      **			       	* 
	square_[3] = Square(3 + x, 1 + y, fillColor_, outlineColor_);
}
void Ishape::rotateCW()
{
	switch (orientation_)
	{
	case LEFT:
		square_[1].setX(square_[0].getX()); //goes to up
		square_[1].setY(square_[0].getY()-1);
		square_[2].setX(square_[0].getX());
		square_[2].setY(square_[0].getY() + 1);
		square_[3].setX(square_[0].getX());
		square_[3].setY(square_[0].getY() + 2);
		break;
	case RIGHT:
		square_[1].setX(square_[0].getX()); //goes to up
		square_[1].setY(square_[0].getY() - 1);
		square_[2].setX(square_[0].getX());
		square_[2].setY(square_[0].getY() + 1);
		square_[3].setX(square_[0].getX());
		square_[3].setY(square_[0].getY() + 2);
		break;
	case DOWN:
		square_[1].setX(square_[0].getX()+1); // orients sideways
		square_[1].setY(square_[0].getY());
		square_[2].setX(square_[0].getX() - 1);
		square_[2].setY(square_[0].getY());
		square_[3].setX(square_[0].getX() - 2);
		square_[3].setY(square_[0].getY());
		break;
	case UP:
		square_[1].setX(square_[0].getX() + 1); // orients sideways
		square_[1].setY(square_[0].getY());
		square_[2].setX(square_[0].getX() - 1);
		square_[2].setY(square_[0].getY());
		square_[3].setX(square_[0].getX() - 2);
		square_[3].setY(square_[0].getY());
		break;
	}
}
void Ishape::rotateCCW()
{
	switch (orientation_)
	{
	case LEFT:
		square_[1].setX(square_[0].getX()); //goes to up
		square_[1].setY(square_[0].getY() - 1);
		square_[2].setX(square_[0].getX());
		square_[2].setY(square_[0].getY() + 1);
		square_[3].setX(square_[0].getX());
		square_[3].setY(square_[0].getY() + 2);
		break;
	case RIGHT:
		square_[1].setX(square_[0].getX()); //goes to up
		square_[1].setY(square_[0].getY() - 1);
		square_[2].setX(square_[0].getX());
		square_[2].setY(square_[0].getY() + 1);
		square_[3].setX(square_[0].getX());
		square_[3].setY(square_[0].getY() + 2);
		break;
	case DOWN:
		square_[1].setX(square_[0].getX() + 1); // orients sideways
		square_[1].setY(square_[0].getY());
		square_[2].setX(square_[0].getX() - 1);
		square_[2].setY(square_[0].getY());
		square_[3].setX(square_[0].getX() - 2);
		square_[3].setY(square_[0].getY());
		break;
	case UP:
		square_[1].setX(square_[0].getX() + 1); // orients sideways
		square_[1].setY(square_[0].getY());
		square_[2].setX(square_[0].getX() - 1);
		square_[2].setY(square_[0].getY());
		square_[3].setX(square_[0].getX() - 2);
		square_[3].setY(square_[0].getY());
		break;
	}
}