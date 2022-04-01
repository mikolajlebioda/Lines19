#pragma once

static const int COLOURS_NUM = 6;

class Ball
{
public:
	Ball(const int posX, const int posY, const bool bigBall = true);
	const int getColorId() const { return colorId; };
	const bool isSamePos(const int posX, const int posY) const;
	const int getPosX() const { return posX; };
	const int getPosY() const { return posY; };
	const bool isBigBall() const { return bigBall; };
	void grow() { bigBall = true; };

private:
	int colorId;
	int posX;
	int posY;
	bool bigBall;
};

