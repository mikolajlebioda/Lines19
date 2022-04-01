#include "board.h"

Board::Board()
{
}

bool Board::isOccupied(const int posX, const int posY) const
{
    return (positions[posX][posY].isOccupied());
}

void Board::newBall(const int posX, const int posY) const
{
    positions[posX][posY].setBall();
}

float Board::getTransX(const int posX) const
{
    return (positions[0][posX].getTransX());
}

float Board::getTransY(const int posY) const
{
    return (positions[posY][0].getTransY());
}

const int Board::getBallColor(const int posX, const int posY) const
{
    return (positions[posX][posY].getBallColorId());
}
