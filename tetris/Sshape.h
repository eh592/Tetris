#pragma once
#include "Tetrimino.h"

class Sshape : public Tetrimino
{
public:
	Sshape();
	Sshape(int x, int y);
	void rotateCW();
	void rotateCCW();
};