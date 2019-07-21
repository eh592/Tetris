#pragma once
#include "Tetrimino.h"

class Zshape : public Tetrimino
{
public:
	Zshape();
	Zshape(int x, int y);
	void rotateCW();
	void rotateCCW();

};