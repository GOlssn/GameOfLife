#include "GameEngine.h"
#include "memstat.hpp"
#include <iostream>
#include <string>
#include "memstat.hpp"
#include "RuleFactory.h"
int main(int argc, char *argv[]) {
	GameEngine ge;
	std::string oddRule, evenRule;

	bool readFromFile = false;

	for (int i = 1; i < argc; i+=2) {

		std::string s = argv[i];
		if (s == "-f") {
			ge.readStartCellsFromFile(argv[i + 1]);
			readFromFile = true;
		}
		else if (s == "-h") {

			std::cout << ge.showHelp();
			return 0;
		}
		else if (s == "-or") {
			oddRule = argv[i + 1];
		}
		else if (s == "-er") {
			evenRule = argv[i + 1];
		}
		else if (s == "-g") {
			ge.setGenerations(argv[i+1]);
		}

		else if ((s == "-s") && !readFromFile) {
			ge.setWindowSize(argv[i + 1]);
		}
		else {
			std::cout << "Unknown argument was used, here is a list of known arguments" << std::endl << std::endl;
			std::cout << ge.showHelp();
			return 0;
		}
	}
	ge.setEvenRule(RuleFactory::createRule(evenRule));
	ge.setOddRule(RuleFactory::createRule(oddRule));
	ge.run();

	return 0;
}