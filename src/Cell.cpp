#include "Cell.h"

Cell::Cell(int pX, int pY, bool pAlive)
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
	return false;
}

int Cell::getY()
{
	return false;
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
