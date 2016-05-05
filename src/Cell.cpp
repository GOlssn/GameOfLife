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

int Cell::getX() const
{
	return false;
}

int Cell::getY() const
{
	return false;
}

void Cell::kill()
{
}

void Cell::revive()
{
	alive = true;
}

bool Cell::isAlive() const
{
	return alive;
}
