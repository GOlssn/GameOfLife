#include "screen.h"

int main(char *args[]) {

	Terminal terminal;
	Screen screen(80, 24);
	screen.fill(' ', TerminalColor(COLOR::BLACK, COLOR::WHITE));

	screen.draw(terminal);

	system("pause");
	return 0;
}