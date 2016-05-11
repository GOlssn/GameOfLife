#ifndef CELL_H
#define CELL_H

#include "../terminal/terminal.h"

class Cell {
	public:
		Cell() : color(COLOR::GREEN) { }
		~Cell();
		void kill();
		void revive();
		bool isAlive() const;
		COLOR getColor() const { return color; }
		void setColor(COLOR pColor) { color = pColor; }

	private:
		COLOR color;
		bool alive = false;
};

#endif // CELL_H