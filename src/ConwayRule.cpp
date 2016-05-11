#include "ConwayRule.h"

void ConwayRule::specificRule(Cell *cell, int pNeighboursAlive) {
	if (cell->isAlive()) {
		if (pNeighboursAlive > 3 || pNeighboursAlive < 2) {
			cell->kill();
		}
		else {
			cell->revive();
		}
	}
	else {
		if (pNeighboursAlive == 3) {
			cell->revive();
		}
	}
}