#pragma once 
#include "Tetrimino.h"

class Oshape :public Tetrimino
{
public:
	Oshape();
	Oshape::Oshape(int x, int y);
	void rotateCW();
	void rotateCCW();
};