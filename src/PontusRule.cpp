#include "PontusRule.h"

/**
* @author Pontus Stenlund
* @param cell contains the current cell being checked in applyRules function.
* @param pNeighboursAlive contains the living cell neighbours to the current cell (param cell).
* @brief Applies the specific rule for pontusRule of who lives and who dies.
* @see Rule::applyRules(vector<vector<Cell*>> &cellMap)
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