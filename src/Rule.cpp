#include "Rule.h"

using std::vector;

/**
* @author Gustav Olsson
* @param cellMap is a vector that contains the current generation of cells.
* @param newCellMap is a vector that will hold the next generation of cells, i.e. the cells after rules are applied.
* @brief Counts neighbouring cells and applies rules to every cell.
* Invokes specificRule() to apply derived implementations of rules on cells.
* @see Rule::specificRule(Cell* cell, vector<Cell*> pNeighboursAlive)
*/
void Rule::applyRules(const vector<vector<Cell*>> &cellMap, vector<vector<Cell*>> &newCellMap) {
	vector<Cell*> neighboursAlive;
	int tmpI = 0;
	int tmpJ = 0;

	for (int i = 0; i < cellMap.size(); i++) { //Row
		for (int j = 0; j < cellMap[i].size(); j++) { //Each cell in row
			tmpI = i;
			tmpJ = j;

			// Loop through current cells neighbours
			for (int m = -1; m <= 1; m++) {
				for (int n = -1; n <= 1; n++) {

					//Check if i or j are out of bounds and if they are, wrap to start or end.
					if (i + m == -1) {
						i = cellMap.size();
					}
					else if (i + m == cellMap.size()) {
						i = -1;
					}

					if (j + n == -1) {
						j = cellMap[tmpI].size();
					}
					else if (j + n == cellMap[tmpI].size()) {
						j = -1;
					}

					//If neighbour is alive, push to neighbour vector
					if ((cellMap[i + m][j + n]->isAlive()) && !(i + m == i && j + n == j)) {
						neighboursAlive.push_back(cellMap[i + m][j + n]);
					}

					i = tmpI;
					j = tmpJ;
				}
			}

			// Copy cellMap cell states to newCellMap and increase age
			if (cellMap[i][j]->isAlive()) {
				newCellMap[i][j]->revive();
				newCellMap[i][j]->setAge(cellMap[i][j]->getAge()+1);
			} else {
				newCellMap[i][j]->kill();
			}
			specificRule(newCellMap[i][j], neighboursAlive);
			neighboursAlive.clear();
		}
	}
}