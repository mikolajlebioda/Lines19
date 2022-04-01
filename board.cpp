#include "board.h"

Board::Board()
{
}

float Board::getTransX(const int posX) const
{
    return (positions[0][posX].getTransX());
}

float Board::getTransY(const int posY) const
{
    return (positions[posY][0].getTransY());
}
