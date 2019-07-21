#include "Oshape.h"
#include "graphics.h"

Oshape::Oshape()
{
	stateOfTetrimino_ = FALLING;
	outlineColor_ = WHITE;
	fillColor_ = COLOR(255, 200, 0);
	orientation_ = LEFT;
	square_[0] = Square(5, 1, fillColor_, outlineColor_); //  ***  -->    *  -->    *			**
	square_[1] = Square(6, 1, fillColor_, outlineColor_); //    *		   *	   *** -->     *
	square_[2] = Square(6, 2, fillColor_, outlineColor_); //		      **			       	* 
	square_[3] = Square(5, 2, fillColor_, outlineColor_);
}
Oshape::Oshape(int x, int y)
{
	stateOfTetrimino_ = FALLING;
	outlineColor_ = WHITE;
	fillColor_ = COLOR(255, 200, 0);
	orientation_ = LEFT;
	square_[0] = Square(5+x, 1+y, fillColor_, outlineColor_); //  ***  -->    *  -->    *			**
	square_[1] = Square(6 + x, 1 + y, fillColor_, outlineColor_); //    *		   *	   *** -->     *
	square_[2] = Square(6 + x, 2 + y, fillColor_, outlineColor_); //		      **			       	* 
	square_[3] = Square(5 + x, 2 + y, fillColor_, outlineColor_);
}
void Oshape::rotateCW()
{

}
void Oshape::rotateCCW()
{

}