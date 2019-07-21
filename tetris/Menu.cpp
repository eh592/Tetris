#include "Menu.h"
#include "graphics.h"
#include <string>

Menu::Menu()
{
	level_ = 1;
	lineCount_ = 0;
	scoreCount_ = 0;
}

void Menu::draw() const
{
	int x = 500;
	int y = 400;
	std::string level;
	std::string line;
	std::string score;

	
	level = std::to_string(level_);
	line = std::to_string(lineCount_);
	score = std::to_string(scoreCount_);

	std::string displayLevel = "Level: ";
	std::string displayLine = "Line: ";
	std::string displayScore = "Score: ";

	displayLevel += level;
	displayLine += line;
	displayScore += score;


	setcolor(WHITE);
	settextstyle(SANS_SERIF_FONT, HORIZ_DIR , 5);
	outtextxy(x, y, const_cast<char*>(displayLevel.c_str()));
	

}

void Menu::updateScore()
{
	scoreCount_ += 100;
	lineCount_ += 1;
	if (lineCount_ % 10 == 0)
	{
		level_ += 1;
	}
}