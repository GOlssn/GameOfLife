/**
* @author Gustav Olsson
* @brief CONWAY
*/
#ifndef CONWAYRULE_H
#define CONWAYRULE_H

#include "Rule.h"

class ConwayRule : public Rule {
	public:
		ConwayRule() { }
		void specificRule(Cell* cell, vector<Cell*> pNeighboursAlive);
};

#endif // !CONWAYRULE_H


