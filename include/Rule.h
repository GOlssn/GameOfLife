#ifndef RULE_H
#define RULE_H

#include <vector>
#include "Cell.h"

using std::vector;

class Rule {
	public:
		Rule() { }
		virtual ~Rule() { }
		virtual vector<vector<Cell*>> applyRules(vector<vector<Cell*>> &cellMap);
		virtual void specificRule(Cell* cell, vector<Cell*> pNeighboursAlive) = 0;
};

#endif // !RULE_H


