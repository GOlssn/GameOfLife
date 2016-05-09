#include "Cell.h"

Cell::Cell()
{
	
}

Cell::~Cell()
{
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
