#ifndef GUSTAV_H
#define GUSTAV_H

#include "Rule.h"

class GustavRule : public Rule {
	public:
		GustavRule() { }
		~GustavRule() { }
		void specificRule(Cell* cell, vector<Cell*> pNeighboursAlive);
};

#endif