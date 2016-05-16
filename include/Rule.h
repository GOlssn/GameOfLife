/**
* @interface Rule
* @author Gustav Olsson
* @brief This is the base class for concrete implementations of rules.
*/

#ifndef RULE_H
#define RULE_H

#include <vector>
#include "Cell.h"

using std::vector;

class Rule {
	public:
		/**
		* @author Gustav Olsson
		* @brief Default construct, no implementation.
		*/
		Rule() { }
		/**
		* @author Gustav Olsson
		* @brief Default destruct, no implementation.
		*/
		virtual ~Rule() { }
		virtual void applyRules(const vector<vector<Cell*>> &cellMap, vector<vector<Cell*>> &newCellMap);
		virtual void specificRule(Cell* cell, vector<Cell*> pNeighboursAlive) = 0;
};

#endif // !RULE_H


