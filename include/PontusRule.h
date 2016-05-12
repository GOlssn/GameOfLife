/**
* @author Pontus Stenlund
* @brief This class handles the implementation of PontusRule.
* @details the rules are:
* - A living cell with one to seven neighbours will live on
* - A living cell with zero or eight neighbours will die
* - A dead cell with one to seven neighbours will live
* - A dead cell with zero or eight neighbours will continue to be dead
*/
#ifndef PONTUSRULE_H
#define PONTUSRULE_H

#include "Rule.h"

class PontusRule : public Rule {
	public:
		PontusRule() {}
		void specificRule(Cell *cell, vector<Cell*> pNeighboursAlive);
};
#endif // !PONTUSRULE_H

