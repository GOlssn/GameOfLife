#ifndef RULEFACTORY_H
#define RULEFACTORY_H

#include <string>
#include "ConwayRule.h"
#include "PontusRule.h"

class RuleFactory {
public:
	RuleFactory();
	static Rule* createRule(std::string rule);
};

#endif // !RULEFACTORY_H

