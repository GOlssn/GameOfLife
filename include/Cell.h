/**
* @author Daniel Jennebo
* @brief This class represents a cell that is a 1 by 1 tile in a cellmap.
* The cell can be either dead or alive and has an age.
* It also has one color for alive and one for dead.
*/

#ifndef CELL_H
#define CELL_H

#include "../terminal/terminal.h"

class Cell {
	public:
		Cell();
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