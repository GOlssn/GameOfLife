#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <string>


/**
* This class handles runtime of program
*/
class GameEngine {
	private:
		//Rule oddRule = new Rule;
		//Rule evenRule = new Rule;
		/**Member variable that holds the x-axels value of window*/
		int x = 80;
		/**Member variable that holds the y-axels value of window*/
		int y = 24;
		int generations = 500;
		//vector<Cell> cellmap;
	
	public:
		GameEngine();
		void run();
		void setWindowSize(std::string size);
		void setGenerations(std::string pGenerations);
		void setOddRule(std::string rule);
		void setEvenRule(std::string rule);
		void readStartCellsFromFile(std::string file);
		void setStartCellsRandom();
		int getX() const;
		void setX(int pX);
		int getY() const;
		void setY(int pY);
		std::string showHelp();



};


#endif // !GAMEENGINE_H
