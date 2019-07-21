#pragma once 

class Menu
{
public:
	Menu();
	void draw() const;
	void updateScore();

private:
	int scoreCount_;
	int lineCount_;
	int level_;
	//std::string menuLines_[3]; // This 10 represents the number of strings (lines of text) that I am planning to print out
};