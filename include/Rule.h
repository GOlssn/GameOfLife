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
		/**
		* @author Gustav Olsson
		* @brief Declaration for specificRule pure virtual function. This function is implemented in derived classes from Rule.
		* @param cell contains the current cell being checked in applyRules function.
		* @param pNeighboursAlive contains the living cell neighbours to the current cell (param cell).
		*/
		virtual void specificRule(Cell* cell, vector<Cell*> pNeighboursAlive) = 0;
};

#endif // !RULE_H


