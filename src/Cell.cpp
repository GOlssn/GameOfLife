#include "Cell.h"

Cell::Cell(int pX, int pY, int pAlive)
{
	x = pX;
	y = pY;
	alive = pAlive;
}

Cell::~Cell()
{
}

int Cell::getX()
{
	return 0;
}

int Cell::getY()
{
	return 0;
}

void Cell::kill()
{
}

void Cell::revive()
{
}

bool Cell::isAlive()
{
	return false;
}
