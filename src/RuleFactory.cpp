#include "RuleFactory.h"
#include <algorithm>

/**
* @author Daniel Jennebo.
* @brief Default construct, no implementation.
*/
RuleFactory::RuleFactory() {
	
}

/**
* @author Daniel Jennebo.
* @brief Returns an instance of a rule based on parameters value.
* @param rule contains the name of the rule that should be created.
* @return An instance of the derived rule.
*/
Rule* RuleFactory::createRule(std::string rule) {
	std::transform(rule.begin(), rule.end(), rule.begin(), ::tolower);
	if (rule == "conway") {
		return new ConwayRule();
	}
	else if (rule == "daniel") {
		return new DanielRule();
	}
	else if (rule == "pontus") {
		return new PontusRule();
	}
	return new ConwayRule();
}