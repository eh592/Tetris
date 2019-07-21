#pragma once
#include "Tetrimino.h"


class Jshape : public Tetrimino
{
public:
	Jshape();
	Jshape::Jshape(int x, int y);
	void rotateCW();
	void rotateCCW();

};