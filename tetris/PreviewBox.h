#pragma once 
#include "Tetrimino.h"

class PreviewBox
{
public:
	PreviewBox(int randomizedTetrimino);
	// copy constructor this is a=b
	// which means that it allocates space for the initiailization of new object
	// and deep copies the data members from preview into this
	PreviewBox(const PreviewBox& preview);
	//move constructor this is for a= b + c 
	// this happens upon initialization when RHS is a r-value to a temporary object that is to be deleted
	// this makes shallow copies the pointers into 'this' and copies over other data
	// then it sets the pointers in RHS to null to ensure that the memory is not deallocated when going out of scope
	PreviewBox(PreviewBox&& preview);

	//copy assignment operator 
	PreviewBox& operator=(const PreviewBox& preview);

	//move assignment operator 
	PreviewBox& operator=(PreviewBox&& preview);


	void drawBox() const;
	void drawNextTetrimino();
	
	void setX(int x);
	int getX() const; 

	void setY(int y);
	int getY() const;

	void setWidth(int width);
	int getWidth() const;

	void setHeight(int height);
	int getHeight() const;


	void selectNewTetrimino(int randomizedTetrimino);
	int getSelectedNewTetrimino() const; 


	//delete tetrimino
	~PreviewBox();
private:
	int x_;
	int y_;
	int width_;
	int height_;
	int selectedTetrimino_;
	Tetrimino* tetrimino_;
};