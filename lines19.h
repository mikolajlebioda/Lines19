#pragma once
#include "board.h"

class Colors
{
public:
	Colors(float a_red, float a_green, float a_blue) { red = a_red; green = a_green; blue = a_blue; }
	float getRed() { return red; }
	float getGreen() { return green; }
	float getBlue() { return blue; }

private:
	float red;
	float green;
	float blue;
};

static Colors colors[] = 
{ 
	Colors(1.0f, 0.0f, 0.0), // red
	Colors(0.0f, 1.0f, 0.0), // green
	Colors(0.0f, 0.0f, 1.0), // blue
	Colors(1.0f, 1.0f, 0.0), // yellow
	Colors(0.5f, 0.0f, 0.0), // dark_red
	Colors(0.0f, 1.0f, 1.0), // cyan
};

static const int POS_X = 9;
static const int POS_Y = 9;
static const int INIT_BALL_COUNT = 7;

class Lines19
{


public: 
	Lines19();

	void init();
	void fillBoardWithBalls();
	void drawBalls();

private:
	void setRandomColor();
	void setColor(const int posX, const int posY);

	Board board;
};

