#include "Tshape.h"
#include "graphics.h"

Tshape::Tshape()
{
	stateOfTetrimino_ = FALLING;
	outlineColor_ = WHITE;
	fillColor_ = COLOR(0, 255, 255);
	orientation_ = DOWN;
	square_[0] = Square(5, 1, fillColor_, outlineColor_); //  ***  -->    *  -->    *			**
	square_[1] = Square(6, 1, fillColor_, outlineColor_); //    *		   *	   *** -->     *
	square_[2] = Square(5, 2, fillColor_, outlineColor_); //		      **			       	* 
	square_[3] = Square(4, 1, fillColor_, outlineColor_);
}
Tshape::Tshape(int x, int y)
{
	stateOfTetrimino_ = FALLING;
	outlineColor_ = WHITE;
	fillColor_ = COLOR(0, 255, 255);
	orientation_ = DOWN;
	square_[0] = Square(5+x, 1+y, fillColor_, outlineColor_); //  ***  -->    *  -->    *			**
	square_[1] = Square(6+x, 1+y, fillColor_, outlineColor_); //    *		   *	   *** -->     *
	square_[2] = Square(5+x, 2+y, fillColor_, outlineColor_); //		      **			       	* 
	square_[3] = Square(4+x, 1+y, fillColor_, outlineColor_);
}
void Tshape::rotateCW()
{
	switch (orientation_)
	{
	case UP:
		square_[1].setX(square_[0].getX());
		square_[1].setY(square_[0].getY()-1);
		square_[2].setX(square_[0].getX() + 1);
		square_[2].setY(square_[0].getY());
		square_[3].setX(square_[0].getX());
		square_[3].setY(square_[0].getY()+1);
		break;
	case RIGHT:
		square_[1].setX(square_[0].getX()+1); // if right, orient to down
		square_[1].setY(square_[0].getY() );
		square_[2].setX(square_[0].getX());
		square_[2].setY(square_[0].getY() + 1);
		square_[3].setX(square_[0].getX()-1);
		square_[3].setY(square_[0].getY() );
		break;
	case DOWN:
		square_[1].setX(square_[0].getX()); // if down, orient left
		square_[1].setY(square_[0].getY() + 1);
		square_[2].setX(square_[0].getX() - 1);
		square_[2].setY(square_[0].getY() );
		square_[3].setX(square_[0].getX());
		square_[3].setY(square_[0].getY() - 1);
		break;
	case LEFT: // if left, then a CC turn will orient it UP
		square_[1].setX(square_[0].getX()-1);
		square_[1].setY(square_[0].getY());
		square_[2].setX(square_[0].getX() );
		square_[2].setY(square_[0].getY() - 1);
		square_[3].setX(square_[0].getX()+1);
		square_[3].setY(square_[0].getY() );
		break;
	}
}
void Tshape::rotateCCW()
{
	switch (orientation_)
	{
	case UP:
		square_[1].setX(square_[0].getX());
		square_[1].setY(square_[0].getY() + 1);

		square_[2].setX(square_[0].getX() - 1);
		square_[2].setY(square_[0].getY());

		square_[3].setX(square_[0].getX());
		square_[3].setY(square_[0].getY() - 1);
		break;
	case RIGHT:
		square_[1].setX(square_[0].getX() - 1); // if right, orient to down
		square_[1].setY(square_[0].getY());

		square_[2].setX(square_[0].getX());
		square_[2].setY(square_[0].getY() - 1);

		square_[3].setX(square_[0].getX() + 1);
		square_[3].setY(square_[0].getY());
		break;
	case DOWN:
		square_[1].setX(square_[0].getX()); // if down, orient left
		square_[1].setY(square_[0].getY() - 1);

		square_[2].setX(square_[0].getX() + 1);
		square_[2].setY(square_[0].getY());

		square_[3].setX(square_[0].getX());
		square_[3].setY(square_[0].getY() + 1);
		break;
	case LEFT: // if left, then a CC turn will orient it UP
		square_[1].setX(square_[0].getX() + 1);
		square_[1].setY(square_[0].getY());

		square_[2].setX(square_[0].getX());
		square_[2].setY(square_[0].getY() + 1);

		square_[3].setX(square_[0].getX() - 1);
		square_[3].setY(square_[0].getY());
		break;
	}
}