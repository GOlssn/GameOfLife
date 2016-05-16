/**
* @author Gustav Olsson
* @brief A concrete rule. Derived from base class Rule.
* @details The rules are:
* - A living cell that has fewer than two living neighbours will die
* - A living cell with two to three living neighbours will survive
* - A living cell with more than three living neighbours will die
* - A dead cell with exactly three neighbours will reproduce
* - If a dead cell has one living neighbours that is above age 0, it will revive
*/

#ifndef CONWAYRULE_H
#define CONWAYRULE_H

#include "Rule.h"

class ConwayRule : public Rule {
	public:
		ConwayRule() { }
		void specificRule(Cell* cell, vector<Cell*> pNeighboursAlive);
};

#endif // !CONWAYRULE_H


