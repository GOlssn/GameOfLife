
#ifndef PONTUSRULE_H
#define PONTUSRULE_H

#include "Rule.h"

class PontusRule : public Rule {
	public:
		PontusRule() {}
		void specificRule(Cell *cell, int pNeighboursAlive);
};
#endif // !PONTUSRULE_H

