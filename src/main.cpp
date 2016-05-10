#include "GameEngine.h"
#include <iostream>
#include <string>
#include "memstat.hpp"
int main(int argc, char *argv[]) {
	GameEngine ge;
	for (int i = 1; i < argc; i+=2) {
		std::cout << argv[i] << std::endl;
		std::string s = argv[i];
		if (s == "-f") {
			//read from file
		}
		else if (s == "-h") {
			ge.showHelp();
			exit(1);
		}
		else if (s == "-or") {
			//set odd rule
		}
		else if (s == "-er") {
			//set even rule
		}
		else if (s == "-g") {
			//set number of generations
		}
		else if (s == "-s") {
			ge.setWindowSize(argv[i + 1]);
		}
		else {
			//Print error message plus help and exit?
		}
	}
	
	ge.run();
	
	return 0;
}