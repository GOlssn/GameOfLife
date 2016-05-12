#ifndef CELL_H
#define CELL_H

#include "../terminal/terminal.h"

class Cell {
	public:
		Cell() : colorAlive(COLOR::GREEN), colorDead(COLOR::WHITE) { }
		~Cell();
		void kill();
		void revive();
		bool isAlive() const;
		COLOR getColorAlive() const;
		void setColorAlive(COLOR pColor);
		COLOR getColorDead() const;
		void setColorDead(COLOR pColor);
		int getAge() const;
		void setAge(int pAge);

	private:
		/**Membervariable that holds the color for alivecell*/
		COLOR colorAlive;
		/**Membervariable that holds the color for deadcell*/
		COLOR colorDead;
		/**Membervariable that holds true or false if cell are alive or dead*/
		bool alive = false;
		/**Membervariable that holds the age for cell*/
		int age = 0;
};

#endif // CELL_H