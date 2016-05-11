#include "DanielRule.h"

/**
* @author Daniel Jennebo
* @param cell contains the current cell being checked in applyRules function.
* @param pNeighboursAlive contains the living cell neighbours to the current cell (param cell).
* @brief applies the specific rules for DanielRule. Who lives and who dies. The rules are:
* - If a living cell is older then age 4 it dies.
* - If a living cell has 4 or more neighbours it dies.
* - If a dead cell has 2 or more neighbours where at least 2 of them is age 1 or more. The dead cell will live
* - Colors:
*	- If age 1: COLOR YELLOW.
*	- If age 1: COLOR CYAN.
*	- If age 1: COLOR BLUE.
*	- If age 1: COLOR RED.
* @see Rule::applyRules(vector<vector<Cell*>> &cellMap)
*/
void DanielRule::specificRule(Cell* cell, vector<Cell*> pNeighboursAlive) {
	int neighboursAge1orMore = 0;
	if (cell->isAlive()) {
		if (cell->getAge()>4) {
			cell->kill();
		}
		if (pNeighboursAlive.size() >= 4) {
			cell->kill();
		}
		switch (cell->getAge())
		{
		case 0: cell->setColorAlive(COLOR::GREEN);
			break;
		case 1: cell->setColorAlive(COLOR::YELLOW);
			break;
		case 2: cell->setColorAlive(COLOR::CYAN);
			break;
		case 3: cell->setColorAlive(COLOR::BLUE);
			break;
		case 4: cell->setColorAlive(COLOR::RED);
			break;
		}
	} else {
		if (pNeighboursAlive.size() >= 2) {
			for (auto cell : pNeighboursAlive) {
				if (cell->getAge() >= 1) {
					neighboursAge1orMore++;
				}
			}
			if (neighboursAge1orMore >= 2) {
				cell->revive();
			}
		}
	}
}