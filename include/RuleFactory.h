/**
* @author Daniel Jennebo
* @brief This class is a factory that instantiate a rule based on user input.
*/

#ifndef RULEFACTORY_H
#define RULEFACTORY_H

#include <string>
#include "ConwayRule.h"
#include "DanielRule.h"
#include "PontusRule.h"

class RuleFactory {
public:
	RuleFactory();
	static Rule* createRule(std::string rule);
};

#endif // !RULEFACTORY_H

