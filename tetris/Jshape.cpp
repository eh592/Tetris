#include "Jshape.h"
#include "Constants.h"
#include "graphics.h"

Jshape::Jshape()
{
	stateOfTetrimino_ = FALLING;
	outlineColor_ = WHITE;
	fillColor_ = COLOR(0, 0, 255);
	orientation_ = LEFT;
	square_[0] = Square(5, 1, fillColor_, outlineColor_); //  ***  -->    *  -->    *			**
	square_[1] = Square(6, 1, fillColor_, outlineColor_); //    *		   *	   *** -->     *
	square_[2] = Square(6, 2, fillColor_, outlineColor_); //		      **			       	* 
	square_[3] = Square(4, 1, fillColor_, outlineColor_);
}
Jshape::Jshape(int x, int y)
{
	stateOfTetrimino_ = FALLING;
	outlineColor_ = WHITE;
	fillColor_ = COLOR(0, 0, 255);
	orientation_ = LEFT;
	square_[0] = Square(5 + x, 1 + y, fillColor_, outlineColor_); //  ***  -->    *  -->    *			**
	square_[1] = Square(6 + x, 1 + y, fillColor_, outlineColor_); //    *		   *	   *** -->     *
	square_[2] = Square(6 + x, 2 + y, fillColor_, outlineColor_); //		      **			       	* 
	square_[3] = Square(4 + x, 1 + y, fillColor_, outlineColor_);
}


void Jshape::rotateCW()  
{
	switch (orientation_)
	{
	case UP:
		square_[1].setX(square_[0].getX() - 1);
		square_[1].setY(square_[0].getY());
		square_[2].setX(square_[0].getX() - 1);
		square_[2].setY(square_[0].getY() - 1);
		square_[3].setX(square_[0].getX() + 1);
		square_[3].setY(square_[0].getY());
		break;
	case RIGHT:
		square_[1].setX(square_[0].getX());
		square_[1].setY(square_[0].getY() - 1);
		square_[2].setX(square_[0].getX() + 1);
		square_[2].setY(square_[0].getY() - 1);
		square_[3].setX(square_[0].getX());
		square_[3].setY(square_[0].getY() + 1);

		break;
	case DOWN:
		square_[1].setX(square_[0].getX() + 1);
		square_[1].setY(square_[0].getY());
		square_[2].setX(square_[0].getX() + 1);
		square_[2].setY(square_[0].getY() + 1);
		square_[3].setX(square_[0].getX() - 1);
		square_[3].setY(square_[0].getY());

		break;
	case LEFT: // if left, then a CC turn will orient it UP
		square_[1].setX(square_[0].getX());
		square_[1].setY(square_[0].getY() + 1);
		square_[2].setX(square_[0].getX() - 1);
		square_[2].setY(square_[0].getY() + 1);
		square_[3].setX(square_[0].getX());
		square_[3].setY(square_[0].getY() - 1);
		break;
	}
}
void Jshape::rotateCCW()  // i could either manually code out my different tetrimino orientations similar to the 
							// clock wise rotation function, or I can just call the clockwise orientation three times 
							// desired orientation
{
	switch (orientation_)
	{
	case UP:
		square_[1].setX(square_[0].getX() + 1); // this sets to LEFT orientation
		square_[1].setY(square_[0].getY());
		square_[2].setX(square_[0].getX() + 1);
		square_[2].setY(square_[0].getY() + 1);
		square_[3].setX(square_[0].getX() - 1);
		square_[3].setY(square_[0].getY());

		break;
	case RIGHT:
		square_[1].setX(square_[0].getX()); //this sets to UP orientation
		square_[1].setY(square_[0].getY() + 1);
		square_[2].setX(square_[0].getX() - 1);
		square_[2].setY(square_[0].getY() + 1);
		square_[3].setX(square_[0].getX());
		square_[3].setY(square_[0].getY() - 1);


		break;
	case DOWN:
		square_[1].setX(square_[0].getX() - 1);// this sets to RIGHT orientation
		square_[1].setY(square_[0].getY());
		square_[2].setX(square_[0].getX() - 1);
		square_[2].setY(square_[0].getY() - 1);
		square_[3].setX(square_[0].getX() + 1);
		square_[3].setY(square_[0].getY());

		break;
	case LEFT: // if left, then a CC turn will orient it UP
		square_[1].setX(square_[0].getX()); // this sets to DOWN orientation
		square_[1].setY(square_[0].getY() - 1);
		square_[2].setX(square_[0].getX() + 1);
		square_[2].setY(square_[0].getY() - 1);
		square_[3].setX(square_[0].getX());
		square_[3].setY(square_[0].getY() + 1);
		break;
	}
}