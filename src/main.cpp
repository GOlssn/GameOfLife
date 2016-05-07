#include "GameEngine.h"
#include <iostream>
#include <string>
int main(int argc, char *argv[]) {
	GameEngine ge;
	for (int i = 1; i < argc; i+=2) {
		std::cout << argv[i] << std::endl;
		std::string s = argv[i];
		if (s == "-f") {
			//read from file
		}
		else if (s == "-h") {
			//show help
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
			//set size of window W,H
		}
		else {
			//Print error message plus help and exit?
		}
	}
	
	ge.run();
	
	return 0;
}