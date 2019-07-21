#pragma once
#include "Tetrimino.h"

class Ishape :public Tetrimino
{
public:
	Ishape();
	Ishape(int x, int y);
	void rotateCW();
	void rotateCCW();
};