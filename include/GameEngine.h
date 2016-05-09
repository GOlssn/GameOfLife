/**
* @author: Daniel Jennebo, Gustav Olsson, Pontus Stenlund
* This class handles runtime of program
*/

#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include<vector>
#include <string>
#include "Cell.h"

class GameEngine {
	private:
		/**Member variable that holds the oddRule*/
		//Rule oddRule = new Rule;
		/**Member variable that holds the evenRule*/
		//Rule evenRule = new Rule;
		/**Member variable that holds the height value of window*/
		int x = 80;
		/**Member variable that holds the width value of window*/
		int y = 24;
		/**Member variale that holds the generations value (the times to iterate)*/
		int generations = 500;
		/**Member variable that holds the cellMap with the cells states*/
		std::vector<std::vector<Cell*>> cellMap;
	
	public:
		GameEngine();
		void run();
		void setWindowSize(std::string size);
		void setGenerations(std::string pGenerations);
		int getGenerations() const;
		void setOddRule(/*Rule rule*/);
		void setEvenRule(/*Rule rule*/);
		void readStartCellsFromFile(std::string file);
		void setStartCellsRandom();
		int getX() const;
		void setX(int pX);
		int getY() const;
		void setY(int pY);
		std::string showHelp();
		std::vector<std::vector<Cell*>> getVector();
		void initCellMap();

};


#endif // !GAMEENGINE_H
