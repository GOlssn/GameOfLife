/**
* @author Gustav Olsson
* @brief A concrete rule. Derived from base class Rule.
* @details The rules are:
* - A dead cell is of color RED
* - If a dead cell has exactly two living neighbours it will revive
* - If a living cell has any living neighbours that are exactly age 2, it will die
* - If a cell has 6 to 8 neighbours that are alive, it will die
* - If a dead cell has one living neighbours that is above age 0, it will revive
*/

#ifndef GUSTAV_H
#define GUSTAV_H

#include "Rule.h"

class GustavRule : public Rule {
	public:
		GustavRule() { }
		~GustavRule() { }
		void specificRule(Cell* cell, vector<Cell*> pNeighboursAlive);
};

#endif