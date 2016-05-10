#include "GameEngine.h"
#include "memstat.hpp"
#include <iostream>
#include <string>
#include "memstat.hpp"
#include "RuleFactory.h"
int main(int argc, char *argv[]) {
	GameEngine ge;

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

			ge.setOddRule(RuleFactory::createRule(argv[i + 1]));
		}
		else if (s == "-er") {

			ge.setEvenRule(RuleFactory::createRule(argv[i + 1]));
		}
		else if (s == "-g") {
			ge.setGenerations(argv[i+1]);
		}

		else if ((s == "-s") && !readFromFile) {
			// -s 80x24
			ge.setWindowSize(argv[i + 1]);
		}
		else {
			//Print error message plus help and exit?
			std::cout << "Unknown argument was used, here is a list of known arguments" << std::endl << std::endl;

			std::cout << ge.showHelp();
			return 0;
		}
	}
	
	ge.run();

	return 0;
}