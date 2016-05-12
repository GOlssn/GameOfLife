/**
* @author: Daniel Jennebo
* brief: This class handles the implementation of DanielRule.
*/

#ifndef DANIELRULE_H
#define DANIELRULE_H

#include "Rule.h"
using std::vector;

class DanielRule : public Rule {
public:
	DanielRule() { }
	void specificRule(Cell* cell, vector<Cell*> pNeighboursAlive);
};

#endif // !DANIELRULE_H