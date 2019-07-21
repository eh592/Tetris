#pragma once
#include "Tetrimino.h"

class Lshape : public Tetrimino
{
public:
	Lshape();
	Lshape(int x, int y);
	void rotateCW();
	void rotateCCW();

};