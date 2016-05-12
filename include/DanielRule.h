/**
* @author Daniel Jennebo
* @brief This class handles the implementation of DanielRule.
* @details The rules are:
* - If a living cell is older then age 4 it dies.
* - If a living cell has 4 or more neighbours it dies.
* - If a dead cell has 2 or more neighbours where at least 2 of them is age 1 or more. The dead cell will live.
* - Colors:
*	- If age 1: COLOR YELLOW.
*	- If age 2: COLOR CYAN.
*	- If age 3: COLOR BLUE.
*	- If age 4: COLOR RED.
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