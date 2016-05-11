#include "RuleFactory.h"
#include <algorithm>

RuleFactory::RuleFactory() {
	
}

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