#include "Cell.h"

Cell::~Cell()
{
}


void Cell::kill()
{
	alive = false;
	age = 0;
}

void Cell::revive()
{
	alive = true;
}

bool Cell::isAlive() const
{
	return alive;
}

void Cell::setAge(int pAge) {
	age = pAge;
}

int Cell::getAge() const {
	return age;
}

void Cell::setColorAlive(COLOR pColor) {
	colorAlive = pColor;
}

COLOR Cell::getColorAlive() const {
	return colorAlive;
}

void Cell::setColorDead(COLOR pColor) {
	colorDead = pColor;
}

COLOR Cell::getColorDead() const {
	return colorDead;
}