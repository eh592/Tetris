#pragma once 
#include "Tetrimino.h"

class Tshape : public Tetrimino
{
public:
	Tshape();
	Tshape::Tshape(int x, int y);
	void rotateCW();
	void rotateCCW();
};