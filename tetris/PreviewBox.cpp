#include "PreviewBox.h"
#include "graphics.h"
#include "Jshape.h"
#include "Lshape.h"
#include "Zshape.h"
#include "Sshape.h"
#include "Oshape.h"
#include "Ishape.h"
#include "Tshape.h"

PreviewBox::PreviewBox(int randomizedTetrimino)
{
	x_ = WINDOW_WIDTH *0.39;
	y_ = SQUARE_WIDTH;
	width_ = SQUARE_WIDTH * 6;
	height_ = SQUARE_WIDTH * 4;
	selectedTetrimino_ = randomizedTetrimino;
	switch (selectedTetrimino_)
	{
	case 0:
		tetrimino_ = new Oshape(9, 1);
		break;
	case 1:
		tetrimino_ = new Jshape(10, 1);
		break;
	case 2:
		tetrimino_ = new Sshape(10, 1);
		break;
	case 3:
		tetrimino_ = new Ishape(10, 1);
		break;
	case 4:
		tetrimino_ = new Tshape(10, 1);
		break;
	case 5:
		tetrimino_ = new Zshape(10, 1);
		break;
	case 6:
		tetrimino_ = new Lshape(10, 1);
		break;
	}
}
// copy constructor 
PreviewBox::PreviewBox(const PreviewBox& preview)
{

	x_ = preview.x_;
	y_ = preview.y_;
	width_ = preview.width_;
	height_ = preview.height_;
	selectedTetrimino_ = preview.selectedTetrimino_;

	// dynamically allocates space for 'this' (based on source object)
	switch (selectedTetrimino_)
	{
	case 0:
		tetrimino_ = new Oshape(9, 1);
		break;
	case 1:
		tetrimino_ = new Jshape(10, 1);
		break;
	case 2:
		tetrimino_ = new Sshape(10, 1);
		break;
	case 3:
		tetrimino_ = new Ishape(10, 1);
		break;
	case 4:
		tetrimino_ = new Tshape(10, 1);
		break;
	case 5:
		tetrimino_ = new Zshape(10, 1);
		break;
	case 6:
		tetrimino_ = new Lshape(10, 1);
		break;
	}
}
// move constructor
PreviewBox::PreviewBox(PreviewBox&& preview)
{
	// suppose to take preview and shallow copy the pointer data 
	x_ = preview.x_;
	y_ = preview.y_;
	width_ = preview.width_;
	height_ = preview.height_;
	selectedTetrimino_ = preview.selectedTetrimino_;

	tetrimino_ = preview.tetrimino_;
	preview.tetrimino_ = nullptr;
}


//copy assignment operator 
PreviewBox& PreviewBox::operator=(const PreviewBox& preview)
{
	if (&preview != this)
	{
		delete tetrimino_;
		x_ = preview.x_;
		y_ = preview.y_;
		width_ = preview.width_;
		height_ = preview.height_;
		selectedTetrimino_ = preview.selectedTetrimino_;

		switch (selectedTetrimino_)
		{
		case 0:
			tetrimino_ = new Oshape(9, 1);
			break;
		case 1:
			tetrimino_ = new Jshape(10, 1);
			break;
		case 2:
			tetrimino_ = new Sshape(10, 1);
			break;
		case 3:
			tetrimino_ = new Ishape(10, 1);
			break;
		case 4:
			tetrimino_ = new Tshape(10, 1);
			break;
		case 5:
			tetrimino_ = new Zshape(10, 1);
			break;
		case 6:
			tetrimino_ = new Lshape(10, 1);
			break;
		}
	}
	return *this;
}

//move assignment operator 
PreviewBox& PreviewBox::operator=(PreviewBox&& preview)
{
	if (&preview != this)
	{
		delete tetrimino_;
		x_ = preview.x_;
		y_ = preview.y_;
		width_ = preview.width_;
		height_ = preview.height_;
		selectedTetrimino_ = preview.selectedTetrimino_;

		tetrimino_ = preview.tetrimino_;
		preview.tetrimino_ = nullptr;
	}
	return *this;
}




void PreviewBox::drawBox() const
{
	setcolor(WHITE);
	setfillstyle(DASHED_LINE, WHITE);
	bar(x_, y_, x_ + width_, y_ + height_);
}
void PreviewBox::drawNextTetrimino()
{
	tetrimino_->draw();
}


void PreviewBox::setX(int x)
{
	x_ = x;
}
int PreviewBox::getX() const
{
	return x_;
}

void PreviewBox::setY(int y)
{
	y_ = y;
}
int PreviewBox::getY() const
{
	return y_;
}

void PreviewBox::setWidth(int width)
{
	width_ = width;
}
int PreviewBox::getWidth() const
{
	return width_;
}

void PreviewBox::setHeight(int height)
{
	height_ = height;
}
int PreviewBox::getHeight() const
{
	return height_;
}


void PreviewBox::selectNewTetrimino(int randomizedTetrimino)
{
	selectedTetrimino_ = randomizedTetrimino;
	switch (randomizedTetrimino)
	{
	case 0:
		tetrimino_ = new Oshape(9, 1);
		break;
	case 1:
		tetrimino_ = new Jshape(10, 1);
		break;
	case 2:
		tetrimino_ = new Sshape(10, 1);
		break;
	case 3:
		tetrimino_ = new Ishape(10, 1);
		break;
	case 4:
		tetrimino_ = new Tshape(10, 1);
		break;
	case 5:
		tetrimino_ = new Zshape(10, 1);
		break;
	case 6:
		tetrimino_ = new Lshape(10, 1);
		break;
	}
}
int PreviewBox::getSelectedNewTetrimino() const
{
	return selectedTetrimino_;
}

PreviewBox::~PreviewBox()
{
	delete tetrimino_;
}