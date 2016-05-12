#include "Rule.h"

using std::vector;

vector<vector<Cell*>> Rule::applyRules(vector<vector<Cell*>> &cellMap) {

	vector<vector<Cell*>> newCellMap;
	vector<Cell*> newCellMapRow;
	vector<Cell*> neighboursAlive;
	int tmpI = 0;
	int tmpJ = 0;

	for (vector<Cell*> row : cellMap) {
		for (Cell* cell : row) {
			newCellMapRow.push_back(new Cell());
		}
		newCellMap.push_back(newCellMapRow);
		newCellMapRow.clear();
	}

	for (int i = 0; i < cellMap.size(); i++) { //Row
		for (int j = 0; j < cellMap[i].size(); j++) { //Each cell in row
			tmpI = i;
			tmpJ = j;

			// Loop through current cells neighbours
			for (int m = -1; m <= 1; m++) {
				for (int n = -1; n <= 1; n++) {

					//Check if i or j are out of bounds
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

					if ((cellMap[i + m][j + n]->isAlive()) && !(i + m == i && j + n == j)) {
						neighboursAlive.push_back(cellMap[i + m][j + n]);
					}

					i = tmpI;
					j = tmpJ;
				}
			}

			if (cellMap[i][j]->isAlive()) {
				newCellMap[i][j]->revive();
				newCellMap[i][j]->setAge(cellMap[i][j]->getAge()+1);
			}

			specificRule(newCellMap[i][j], neighboursAlive);
			neighboursAlive.clear();
		}
	}

	for (auto row : cellMap) {
		for (auto cell : row) {
			delete cell;
		}
	}
	cellMap.clear();

	return newCellMap;
}