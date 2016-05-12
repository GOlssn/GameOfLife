#include "ConwayRule.h"

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