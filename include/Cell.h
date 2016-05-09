#ifndef CELL_H
#define CELL_H

class Cell {
	public:
		Cell() { alive = false; }
		Cell(bool pAlive);
		~Cell();
		void kill();
		void revive();
		bool isAlive() const;

	private:
		bool alive;
};

#endif // CELL_H