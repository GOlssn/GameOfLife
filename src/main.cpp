#include "screen.h"

int main(int argc, char *args[]) {
	for (int i = 0; i < argc; i+2) {
		if (args[i] == "-f") {
			//read from file
		}
		else if (args[i] == "-h") {
			//show help
		}
		else if (args[i] == "-or") {
			//set odd rule
		}
		else if (args[i] == "-er") {
			//set even rule
		}
		else if (args[i] == "-g") {
			//set number of generations
		}
		else if (args[i] == "-s") {
			//set size of window W,H
		}
		else {
			//Print error message plus help and exit?
		}
	}

	Terminal terminal;
	Screen screen(80, 24);
	screen.fill(' ', TerminalColor(COLOR::BLACK, COLOR::WHITE));

	screen.draw(terminal);

	system("pause");
	return 0;
}