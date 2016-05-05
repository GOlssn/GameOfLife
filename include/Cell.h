#ifndef CELL_H
#define CELL_H

class Cell {
	public:
		Cell(int pX, int pY, bool pAlive);
		~Cell();
		int getX();
		int getY();
		void kill();
		void revive();
		bool isAlive();

	private:
		int x;
		int y;
		bool alive;
};

#endif // CELL_H