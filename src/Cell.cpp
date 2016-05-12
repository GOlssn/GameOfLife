#include "Cell.h"

/**
* @author Daniel Jennebo
* @brief Default constructor for Cell class. Sets #colorAlive & #colorDead color to defaults.
*/
Cell::Cell() : colorAlive(COLOR::GREEN), colorDead(COLOR::WHITE) {}

/**
* @author Daniel Jennebo
* @brief Default destructor for Cell class, no implementation.
*/
Cell::~Cell()
{
}

/**
* @author Daniel Jennebo
* @brief Function kills a cell. I sets the #alive to false and #age to 0.
*/
void Cell::kill()
{
	alive = false;
	age = 0;
}

/**
* @author Daniel Jennebo
* @brief Function revives a cell. I sets the #alive to true.
*/
void Cell::revive()
{
	alive = true;
}

/**
* @author Daniel Jennebo
* @brief Function returns the state of cell (alive or dead).
* @return Membervariable #alive.
*/
bool Cell::isAlive() const
{
	return alive;
}

/**
* @author Daniel Jennebo
* @brief Function sets age on a cell.
* @param pAge contains the value that membervariable #age is going to set to.
*/
void Cell::setAge(int pAge) {
	age = pAge;
}

/**
* @author Daniel Jennebo
* @brief Function gets a cells age.
* @return Membervariable #age
*/
int Cell::getAge() const {
	return age;
}

/**
* @author Daniel Jennebo
* @brief Function sets the color for when the cell is alive.
* @param pColor contains the color that membervariable #colorAlive is going to set to.
*/
void Cell::setColorAlive(COLOR pColor) {
	colorAlive = pColor;
}

/**
* @author Daniel Jennebo
* @brief Function gets a cells alive color.
* @return Membervariable #colorAlive
*/
COLOR Cell::getColorAlive() const {
	return colorAlive;
}

/**
* @author Daniel Jennebo
* @brief Function sets the color for when the cell is dead.
* @param pColor contains the color that membervariable #colorDead is going to set to.
*/
void Cell::setColorDead(COLOR pColor) {
	colorDead = pColor;
}

/**
* @author Daniel Jennebo
* @brief Function gets a cells dead color.
* @return Membervariable #colorDead
*/
COLOR Cell::getColorDead() const {
	return colorDead;
}