#include "GustavRule.h"

/**
* @author Gustav Olsson
* @param cell contains the current cell being checked in applyRules function.
* @param pNeighboursAlive contains the living cell neighbours to the current cell (param cell).
* @brief applies the specific rules for GustavRule. Who lives and who dies.
* @see Rule::applyRules(vector<vector<Cell*>> &cellMap)
*/
void GustavRule::specificRule(Cell* cell, vector<Cell*> pNeighboursAlive) {
	
	// Set ColorDead
	cell->setColorDead(COLOR::RED);
	
	// If a dead cell has exactly two living neighbours it will revive
	if (pNeighboursAlive.size() == 2) {
		cell->revive();
	}

	int counterAgeTwo = 0;
	int counterAgeAboveZero = 0;

	for (Cell *mCell : pNeighboursAlive) {
		if (mCell->getAge() == 2) {
			counterAgeTwo++;
		} else if (mCell->getAge() > 0) {
			counterAgeAboveZero++;
		}
	}

	// If a living cell has any living neighbours that are exactly age 2, it will die
	if (counterAgeTwo > 0) {
		cell->kill();
	}

	// If a dead cell has one living neighbours that is above age 0, it will revive
	if (counterAgeAboveZero == 1) {
		cell->revive();
	}

	// If a cell has 6 to 8 neighbours that are alive, it will die
	if (pNeighboursAlive.size() >= 6 && pNeighboursAlive.size() <= 8) {
		cell->kill();
	}
	
}