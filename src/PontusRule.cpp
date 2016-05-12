#include "PontusRule.h"

/**
* @author Pontus Stenlund
* @param cell contains the current cell being checked in applyRules function.
* @param pNeighboursAlive contains the living cell neighbours to the current cell (param cell).
* @brief This is the special rule made by pontus, the rules are:
* - A living cell with one to seven neighbours will live on
* - A living cell with zero or eight neighbours will die
* - A dead cell with one to seven neighbours will live
* - A dead cell with zero or eight neighbours will continue to be dead
*/
void PontusRule::specificRule(Cell *cell, vector<Cell*> pNeighboursAlive) {
	if (cell->isAlive()) {
		if (pNeighboursAlive.size() >= 1 && pNeighboursAlive.size() <= 7) {
			cell->revive();
			cell->setColorAlive(COLOR::BLUE);
		}
		else if (pNeighboursAlive.size() == 0 || pNeighboursAlive.size() == 8) {
			cell->kill();
		}
	}
	else {
		if (pNeighboursAlive.size() >= 1 && pNeighboursAlive.size() <= 7) {
			cell->revive();
			cell->setColorAlive(COLOR::RED);
		}
	}
}