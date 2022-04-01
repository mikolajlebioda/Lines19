#pragma once
#include "ball.h"
#include <memory>

class Pos
{
public:
	Pos(float a_transX, float a_transY) { transX = a_transX; transY = a_transY; }
	float getTransX() { return transX; }
	float getTransY() { return transY; }

private:
	float transX;
	float transY;
};

// learning purposes only!!!
// this array should be generated dynamically!!!
static Pos positions[9][9] =
{
	{Pos(2.0f, 2.0f), Pos(1.5f, 2.0f), Pos(1.0f, 2.0f), Pos(0.5f, 2.0f), Pos(0.0f, 2.0f), Pos(-0.5f, 2.0f), Pos(-1.0f, 2.0f), Pos(-1.5f, 2.0f), Pos(-2.0f, 2.0f) },
	{Pos(2.0f, 1.5f), Pos(1.5f, 1.5f), Pos(1.0f, 1.5f), Pos(0.5f, 1.5f), Pos(0.0f, 1.5f), Pos(-0.5f, 1.5f), Pos(-1.0f, 1.5f), Pos(-1.5f, 1.5f), Pos(-2.0f, 1.5f) },
	{Pos(2.0f, 1.0f), Pos(1.5f, 1.0f), Pos(1.0f, 1.0f), Pos(0.5f, 1.0f), Pos(0.0f, 1.0f), Pos(-0.5f, 1.0f), Pos(-1.0f, 1.0f), Pos(-1.5f, 1.0f), Pos(-2.0f, 1.0f) },
	{Pos(2.0f, 0.5f), Pos(1.5f, 0.5f), Pos(1.0f, 0.5f), Pos(0.5f, 0.5f), Pos(0.0f, 0.5f), Pos(-0.5f, 0.5f), Pos(-1.0f, 0.5f), Pos(-1.5f, 0.5f), Pos(-2.0f, 0.5f) },
	{Pos(2.0f, 0.0f), Pos(1.5f, 0.0f), Pos(1.0f, 0.0f), Pos(0.5f, 0.0f), Pos(0.0f, 0.0f), Pos(-0.5f, 0.0f), Pos(-1.0f, 0.0f), Pos(-1.5f, 0.0f), Pos(-2.0f, 0.0f) },
	{Pos(2.0f, -0.5f), Pos(1.5f, -0.5f), Pos(1.0f, -0.5f), Pos(0.5f, -0.5f), Pos(0.0f, -0.5f), Pos(-0.5f, -0.5f), Pos(-1.0f, -0.5f), Pos(-1.5f, -0.5f), Pos(-2.0f, -0.5f) },
	{Pos(2.0f, -1.0f), Pos(1.5f, -1.0f), Pos(1.0f, -1.0f), Pos(0.5f, -1.0f), Pos(0.0f, -1.0f), Pos(-0.5f, -1.0f), Pos(-1.0f, -1.0f), Pos(-1.5f, -1.0f), Pos(-2.0f, -1.0f) },
	{Pos(2.0f, -1.5f), Pos(1.5f, -1.5f), Pos(1.0f, -1.5f), Pos(0.5f, -1.5f), Pos(0.0f, -1.5f), Pos(-0.5f, -1.5f), Pos(-1.0f, -1.5f), Pos(-1.5f, -1.5f), Pos(-2.0f, -1.5f) },
	{Pos(2.0f, -2.0f), Pos(1.5f, -2.0f), Pos(1.0f, -2.0f), Pos(0.5f, -2.0f), Pos(0.0f, -2.0f), Pos(-0.5f, -2.0f), Pos(-1.0f, -2.0f), Pos(-1.5f, -2.0f), Pos(-2.0f, -2.0f) },
};

class Board
{
public:
	Board();
	float getTransX(const int posX) const;
	float getTransY(const int posY) const;
};

