#ifndef CELL_H
#define CELL_H

class Cell {
	public:
		Cell(int pX, int pY, bool pAlive);
		~Cell();
		int getX() const;
		int getY() const;
		void kill();
		void revive();
		bool isAlive() const;

	private:
		int x;
		int y;
		bool alive;
};

#endif // CELL_H