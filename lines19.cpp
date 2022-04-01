#include "lines19.h"
#include <glm/gtc/type_ptr.hpp>
#include "allmodels.h"
#include "shaderprogram.h"
#include <ctime>
Lines19::Lines19()
{
}

void Lines19::init()
{
	int posX = -1;
	int posY = -1;
	std::srand(std::time(0));
	for (int i = 0; i < INIT_BALL_COUNT; i++)
	{
		do
		{
			posX = std::rand() % POS_X;
			posY = std::rand() % POS_Y;
		} while (board.isOccupied(posX, posY));
		board.newBall(posX, posY);
	}
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
	for (int j = 0; j < POS_Y; j++)
	{
		for (int i = 0; i < POS_X; i++)
		{
			if (board.isOccupied(i, j))
			{
				glm::mat4 M = glm::mat4(1.0f);

				setColor(i, j);
				M = glm::translate(M, glm::vec3(board.getTransX(j), board.getTransY(i), 0.0f));
				M = glm::scale(M, glm::vec3(0.2f, 0.2f, 0.2f));
				glUniformMatrix4fv(spLambert->u("M"), 1, false, glm::value_ptr(M));
				Models::sphere.drawSolid();
			}
		}
	}
}

// learning purposes only!!!
void Lines19::setRandomColor()
{
	const int colorId = std::rand() % COLOURS_NUM;
	glUniform4f(spLambert->u("color"), colors[colorId].getRed(), colors[colorId].getGreen(), colors[colorId].getBlue(), 1);
}

void Lines19::setColor(const int posX, const int posY)
{
	const int colorId = board.getBallColor(posX, posY);
	glUniform4f(spLambert->u("color"), colors[colorId].getRed(), colors[colorId].getGreen(), colors[colorId].getBlue(), 1);
}
