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
	return x;
}

int Cell::getY() const
{
	return y;
}

void Cell::kill()
{
	alive = false;
}

void Cell::revive()
{
	alive = true;
}

bool Cell::isAlive() const
{
	return alive;
}
