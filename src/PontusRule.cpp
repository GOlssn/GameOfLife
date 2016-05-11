#include "PontusRule.h"

/**
*
* @author Pontus Stenlund
* @brief This is the special rule made by pontus, the rules are:
* - A living cell with one to seven neighbours will live on
* - A living cell with zero or eight neighbours will die
* - A dead cell with one to seven neighbours will live
* - A dead cell with zero or eight neighbours will continue to be dead
*/
void PontusRule::specificRule(Cell *cell, int pNeighboursAlive) {
	if (cell->isAlive()) {
		if (pNeighboursAlive >= 1 && pNeighboursAlive <= 7) {
			cell->revive();
			cell->setColor(COLOR::BLUE);
		}
		else if (pNeighboursAlive == 0 || pNeighboursAlive == 8) {
			cell->kill();
		}
	}
	else {
		if (pNeighboursAlive >= 1 && pNeighboursAlive <= 7) {
			cell->revive();
			cell->setColor(COLOR::RED);
		}
	}
}