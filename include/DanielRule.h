/**
* @author Daniel Jennebo
* @brief A concrete rule. Derived from base class Rule.
* @details The rules are:
* - If a living cell is older then age 4 it dies.
* - If a living cell has 4 or more neighbours it dies.
* - If a dead cell has 2 or more neighbours where at least 2 of them is age 1 or more. The dead cell will live.
* - Colors:
*	- If cell age 1: COLOR YELLOW.
*	- If cell age 2: COLOR CYAN.
*	- If cell age 3: COLOR BLUE.
*	- If cell age 4: COLOR RED.
*/
#ifndef DANIELRULE_H
#define DANIELRULE_H

#include "Rule.h"

class DanielRule : public Rule {
	public:
		DanielRule() { }
		void specificRule(Cell* cell, vector<Cell*> pNeighboursAlive);
};

#endif // !DANIELRULE_H