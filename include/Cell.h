#ifndef CELL_H
#define CELL_H

class Cell {
	public:
		Cell();
		~Cell();
		void kill();
		void revive();
		bool isAlive() const;

	private:

		bool alive = false;
};

#endif // CELL_H