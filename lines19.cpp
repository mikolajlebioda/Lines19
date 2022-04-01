#include "lines19.h"
#include <glm/gtc/type_ptr.hpp>
#include "allmodels.h"
#include "shaderprogram.h"
#include <ctime>
#include <iterator>
Lines19::Lines19()
{
}

void Lines19::init()
{
	int posX = -1;
	int posY = -1;
	std::srand(std::time(0));
	for (int i = 0; i < INIT_BIG_BALL_COUNT; i++)
	{
		do
		{
			posX = std::rand() % POS_X;
			posY = std::rand() % POS_Y;
		} while (isOccupied(posX, posY));
		balls.push_back(std::shared_ptr<Ball>(new Ball(posX, posY)));
	}

	addSmallBalls();
}

// learning purposes only!!!
void Lines19::fillBoardWithBalls()
{
	for (int j = 0; j < POS_Y; j++)
	{
		for (int i = 0; i < POS_X; i++)
		{
			setRandomColor();
			
			glm::mat4 M = glm::mat4(1.0f);
			M = glm::translate(M, glm::vec3((2.0f - 0.5f * i), (2.0f - 0.5f * j), 0.0f));
			M = glm::scale(M, glm::vec3(0.2f, 0.2f, 0.2f));
			glUniformMatrix4fv(spLambert->u("M"), 1, false, glm::value_ptr(M));
			Models::sphere.drawSolid();
		}
	}
}

void Lines19::drawBalls()
{
	for (std::vector<std::shared_ptr<Ball>>::iterator it = std::begin(balls); it != std::end(balls); ++it)
	{
		const int posX = it->get()->getPosX();
		const int posY = it->get()->getPosY();
		const int colorId = it->get()->getColorId();

		glm::mat4 M = glm::mat4(1.0f);

		glUniform4f(spLambert->u("color"), colors[colorId].getRed(), colors[colorId].getGreen(), colors[colorId].getBlue(), 1);
		M = glm::translate(M, glm::vec3(board.getTransX(posX), board.getTransY(posY), 0.0f));
		
		if (!it->get()->isBigBall())
		{
			M = glm::scale(M, glm::vec3(0.1f, 0.1f, 0.1f));
		}
		else
		{
			M = glm::scale(M, glm::vec3(0.2f, 0.2f, 0.2f));
		}

		glUniformMatrix4fv(spLambert->u("M"), 1, false, glm::value_ptr(M));

		

		Models::sphere.drawSolid();
	}

}

void Lines19::nextTurn()
{
	for (std::vector<std::shared_ptr<Ball>>::iterator it = std::begin(balls); it != std::end(balls); ++it)
	{
		it->get()->grow();
	}
	addSmallBalls();
}

// learning purposes only!!!
void Lines19::setRandomColor()
{
	const int colorId = std::rand() % COLOURS_NUM;
	glUniform4f(spLambert->u("color"), colors[colorId].getRed(), colors[colorId].getGreen(), colors[colorId].getBlue(), 1);
}

const bool Lines19::isOccupied(const int posX, const int posY)
{
	bool result = false;

	for (std::vector<std::shared_ptr<Ball>>::iterator it = std::begin(balls); it != std::end(balls); ++it) 
	{
		if (it->get()->isSamePos(posX, posY))
		{
			result = true;
			break;
		}
	}

	return result;
}

void Lines19::addSmallBalls()
{
	int posX = -1;
	int posY = -1;
	for (int i = 0; i < SMALL_BALL_COUNT; i++)
	{
		do
		{
			posX = std::rand() % POS_X;
			posY = std::rand() % POS_Y;
		} while (isOccupied(posX, posY));
		balls.push_back(std::shared_ptr<Ball>(new Ball(posX, posY, false)));
	}
}
