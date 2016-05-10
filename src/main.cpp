#include "GameEngine.h"
#include <iostream>
#include <string>
int main(int argc, char *argv[]) {
	GameEngine ge;
	//RuleFactory rf;
	bool readFromFile = false;
	for (int i = 1; i < argc; i+=2) {
		std::cout << argv[i] << std::endl;
		std::string s = argv[i];
		if (s == "-f") {
			ge.readStartCellsFromFile(argv[i + 1]);
			readFromFile = true;
		}
		else if (s == "-h") {
			ge.showHelp();
			exit(1);
		}
		else if (s == "-or") {
			//ge.setOddRule(rf.createRule(argv[i+1]));
		}
		else if (s == "-er") {
			//ge.setEvenRule(rf.createRule(argv[i+1]));
		}
		else if (s == "-g") {
			ge.setGenerations(argv[i+1]);
		}
		else if ((s == "-s") && !readFromFile) {
			ge.setWindowSize(argv[i + 1]);
		}
		else {
			//Print error message plus help and exit?
			std::cout << "Unknown argument was used, here is a list of known arguments" << std::endl << std::endl;
			ge.showHelp();
			exit(1);
		}
	}
	
	ge.run();
	
	return 0;
}