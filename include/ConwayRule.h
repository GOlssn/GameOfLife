#ifndef CONWAYRULE_H
#define CONWAYRULE_H

#include "Rule.h"
using std::vector;

class ConwayRule : public Rule {
	public:
		ConwayRule() { }
		vector<vector<Cell*>> applyRules(vector<vector<Cell*>> &cellMap);
};
#endif // !CONWAYRULE_H


