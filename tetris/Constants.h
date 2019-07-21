#pragma once

enum TetrisState
{
	FALLING, HIT
};

enum GameFieldState
{
	OCCUPIED, UNOCCUPIED
};
enum TetriminoOrientation
{
	UP,
	DOWN, 
	RIGHT,
	LEFT
};


const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const char ESC = 27;
const char ARROW_RIGHT = 77;
const char ARROW_LEFT = 75;
const char ARROW_UP = 72;
const char ARROW_DOWN = 80;
const char SPACE = 32;
const char Z_KEY = 122;


const int SQUARES_IN_TETRIMINO = 4;

const int TOP_LEFT_CORNER = 25; // define the position of the game arena
const int TOP_RIGHT_CORNER = 25;

const int SQUARE_WIDTH = 25; // define the size of the block
const int WIDTH_GAME_ARENA = 11;
const int HEIGHT_GAME_ARENA = 21;

const int SCORE_BOARD_X_POSITION = 350; // this is the position where I start printing out text (x direction)
const int SCORE_BOARD_Y_POSITION = 200;

//space is 32
