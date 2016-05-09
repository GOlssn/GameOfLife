/**
* @author: Daniel Jennebo, Gustav Olsson, Pontus Stenlund
* This class handles runtime of program
*/

#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <string>
#include <vector>
#include "Cell.h"

class GameEngine {
	private:
		//Rule oddRule = new Rule;
		//Rule evenRule = new Rule;
		/**Member variable that holds the x-axels value of window*/
		int x = 80;
		/**Member variable that holds the y-axels value of window*/
		int y = 24;
		/**Member variale that holds the generations value (the times to iterate)*/
		int generations = 500;
		std::vector<std::vector<Cell*>> cellMap;
	
	public:
		GameEngine();
		void run();
		void setWindowSize(std::string size);
		void setGenerations(std::string pGenerations);
		int getGenerations() const;
		void setOddRule(std::string rule);
		void setEvenRule(std::string rule);
		void readStartCellsFromFile(std::string file);
		bool getCell();
		void setStartCellsRandom();
		int getX() const;
		void setX(int pX);
		int getY() const;
		void setY(int pY);
		std::string showHelp();

};


#endif // !GAMEENGINE_H
