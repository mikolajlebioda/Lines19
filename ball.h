#pragma once

static const int COLOURS_NUM = 6;

class Ball
{
public:
	Ball();
	const int getColorId() const { return colorId; };

private:
	int colorId;
	int posX;
	int posY;
	bool visible;
};

