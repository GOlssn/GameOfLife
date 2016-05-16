#include "ConwayRule.h"

/**
* @author Gustav Olsson
* @param cell contains the current cell being checked in applyRules function.
* @param pNeighboursAlive contains the living cell neighbours to the current cell (param cell).
* @brief applies the specific rules for ConwayRule. Who lives and who dies.
* @see Rule::applyRules(vector<vector<Cell*>> &cellMap)
*/
void ConwayRule::specificRule(Cell *cell, vector<Cell*> pNeighboursAlive) {
	if (cell->isAlive()) {
		if (pNeighboursAlive.size() > 3 || pNeighboursAlive.size() < 2) {
			cell->kill();
		}
		else {
			cell->revive();
		}
	}
	else {
		if (pNeighboursAlive.size() == 3) {
			cell->revive();
		}
	}
}