#include "ball.h"
#include <ctime>
#include <cstdlib>
Ball::Ball()
{
	colorId = std::rand() % COLOURS_NUM;
	visible = false;
	posX = -1;
	posY = -1;
}
