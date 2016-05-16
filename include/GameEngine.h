/**
* @author: Daniel Jennebo, Gustav Olsson, Pontus Stenlund
* @brief This class handles runtime of program
*/

#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include<vector>
#include <string>
#include "Cell.h"
#include "ConwayRule.h"

class GameEngine {
	private:
		/**Member variable that holds the oddRule*/
		Rule *oddRule;
		/**Member variable that holds the evenRule*/
		Rule *evenRule;

		/**Member variable that holds the width value of window*/
		int x = 80;

		/**Member variable that holds the height value of window*/
		int y = 24;
		/**Member variale that holds the generations value (the times to iterate)*/
		int generations = 500;

		/**Member variable that holds the cellMap with the cells states*/
		std::vector<std::vector<Cell*>> evenCellMap;
		/**Member variable that holds the */
		std::vector<std::vector<Cell*>> oddCellMap;
	
	public:
		GameEngine();
		~GameEngine();
		void run();
		void setWindowSize(std::string size);
		void setGenerations(std::string pGenerations);
		int getGenerations() const;

		void setOddRule(Rule *rule);
		void setEvenRule(Rule *rule);
		void readStartCellsFromFile(std::string file);
		void setStartCellsRandom();
		int getX() const;
		void setX(int pX);
		int getY() const;
		void setY(int pY);
		std::string showHelp();
		std::vector<std::vector<Cell*>> getVector();
		void initCellMaps();
		void drawOnScreen(vector<vector<Cell*>> pCellMap);

};


#endif // !GAMEENGINE_H
