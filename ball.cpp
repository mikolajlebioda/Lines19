#include "ball.h"
#include <ctime>
#include <cstdlib>

Ball::Ball(const int posX, const int posY, const bool bigBall/* = true*/)
{
	colorId = std::rand() % COLOURS_NUM;
	this->posX = posX;
	this->posY = posY;
	this->bigBall = bigBall;
}

const bool Ball::isSamePos(const int posX, const int posY) const
{
	bool result = false;

	if ((this->posX == posX) && (this->posY == posY))
	{
		result = true;
	}

	return result;
}
