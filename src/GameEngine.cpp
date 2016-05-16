
#include <vector>
#include <thread>
#include <chrono>
#include <iostream>
#include "GameEngine.h"
#include "screen.h"
#include "Cell.h"
#include <random>
#include <fstream>

const std::string DELIM = ",";

/**
* @author Daniel Jennebo.
* @brief Default constuct for GameEngine class.
*/
GameEngine::GameEngine()
{
	oddRule = new ConwayRule();
	evenRule = new ConwayRule();
}

/**
* @author Daniel Jennebo.
* @brief Destructor for GameEngine class. Deletes pointers in #evenCellMap, #oddCellMap & pointers #oddRule, #evenRule
*/
GameEngine::~GameEngine() {
	for (auto row : evenCellMap) {
		for (auto cell : row) {
			delete cell;
		}
	}
	for (auto row : oddCellMap) {
		for (auto cell : row) {
			delete cell;
		}
	}
	evenCellMap.clear();
	oddCellMap.clear();
	delete oddRule;
	delete evenRule;

}

/**
* @brief Function handles the programs runtime.
*/
void GameEngine::run() {

	if (evenCellMap.size() == 0) {
		setStartCellsRandom();
	}

	drawOnScreen(evenCellMap);
	for (int i = 1; i <= generations; i++) {

		if (i % 2 == 0) {
			evenRule->applyRules(oddCellMap, evenCellMap);
			drawOnScreen(evenCellMap);
		}
		else {
			oddRule->applyRules(evenCellMap, oddCellMap);
			drawOnScreen(oddCellMap);
		}
	}
}

/**
* @author Daniel Jennebo, Gustav Olsson
* @brief This function handles draw on screen (print the alive and dead cells to terminal)
*/
void GameEngine::drawOnScreen(vector<vector<Cell*>> pCellMap) {
	Terminal terminal;
	Screen screen(x, y);
	screen.fill(' ', TerminalColor(COLOR::BLACK, COLOR::WHITE));
	for (int y = 0; y < pCellMap.size(); y++) {
		for (int x = 0; x < pCellMap[y].size(); x++) {
			if (pCellMap[y][x]->isAlive()) {
				screen.set(x, y, ' ', TerminalColor(COLOR::BLACK, pCellMap[y][x]->getColorAlive()));
			}
			else {
				screen.set(x, y, ' ', TerminalColor(COLOR::BLACK, pCellMap[y][x]->getColorDead()));
			}
		}
	}

	screen.draw(terminal);
	std::this_thread::sleep_for(std::chrono::seconds(1));
}

/**
* @author Daniel Jennebo.
* @brief Function sets #x and #y values to determine size of terminal window.
* @param size contains a string with "WIDTHxHEIGHT".
*/
void GameEngine::setWindowSize(std::string size)
{
	//Kolla så att inmatning är korrekt?

	setX(stoi(size.substr(0, size.find("x"))));
	setY(stoi(size.substr(size.find("x")+1)));
}


/**
* @author Daniel Jennebo.
* @brief Function sets number of generations to iterate trough. Sets the membervariable #generations to params value.
* @param pGenerations contains a string with number of generations.
*/
void GameEngine::setGenerations(std::string pGenerations)
{
	generations = stoi(pGenerations);
}

/**
* @author Daniel Jennebo.
* @brief Function returns membervariable #generations.
* @return membervariable generations as int.
*/
int GameEngine::getGenerations() const
{
	return generations;
}

/**
* @author Daniel Jennebo.
* @brief Function sets membervariable #oddRule value to params value. 
* @param rule contains a rule object.
*/

void GameEngine::setOddRule(Rule *rule)
{

	delete oddRule;
	oddRule = rule;
}

/**

* @author Daniel Jennebo.
* @brief Function sets membervariable #evenRule value to params value.
* @param rule contains a rule object.
*/

void GameEngine::setEvenRule(Rule *rule)
{

	delete evenRule;
	evenRule = rule;
}



/**
* @author Pontus Stenlund
* @brief Reads from file and sets windowsize and which cells 
* to be alive.
* @param file is the string that holds the name of the file to be read.
*/
void GameEngine::readStartCellsFromFile(std::string file)
{
	std::ifstream inFile(file);
	if (inFile.good())
	{
		std::string size;
		getline(inFile, size);
		setWindowSize(size);
		initCellMaps();

		std::string tmp;
		std::size_t pos;
		int posX;
		int posY;
		while (getline(inFile, tmp))
		{
			pos = tmp.find(DELIM);
			posX = stoi(tmp.substr(0, pos));
			tmp.erase(0, pos + DELIM.size());

			posY = stoi(tmp);

			evenCellMap[posY][posX]->revive();
		}
	}

	inFile.close();
}

/**


* @author Daniel Jennebo.
* @brief Function make random number of cells alive at random places in #evenCellMap cause that's the 
* initial state.
*/
void GameEngine::setStartCellsRandom()
{
	initCellMaps();
	std::default_random_engine generator(time(0));
	std::uniform_int_distribution<int> cellNumRand(1,x*y);
	std::uniform_int_distribution<int> rowRand(0, y-1);
	std::uniform_int_distribution<int> colRand(0, x-1);

	int numberOfAlive = cellNumRand(generator);
	for (int i = 0; i < numberOfAlive; i++) {
		evenCellMap[rowRand(generator)].at(colRand(generator))->revive();
	}
}

/**


* @author Daniel Jennebo.
* @brief Function initiate the #evenCellMap & #oddCellMap vectors with dead cells.
*/
void GameEngine::initCellMaps() {
	std::vector<Cell*> tmp;
	std::vector<Cell*> newTmp;

	for (int row = 0; row < y; row++) {
		for (int cell = 0; cell < x; cell++) {
			tmp.push_back(new Cell());
			newTmp.push_back(new Cell());
		}
		evenCellMap.push_back(tmp);
		oddCellMap.push_back(newTmp);
		newTmp.clear();
		tmp.clear();
	}
}


/**
* @author Daniel Jennebo.
* @brief Function returns membervariable #x.
* @return membervariable #x as int.
*/
int GameEngine::getX() const
{
	return x;
}

/**


* @author Daniel Jennebo.
* @brief Function sets membervariable #x to params value.
* @param pX (int) contains number of columns (width).
*/
void GameEngine::setX(int pX)
{
	x = pX;
}

/**


* @author Daniel Jennebo.
* @brief Function returns membervariable #y.
* @return membervariable y as int.
*/
int GameEngine::getY() const
{ 
	return y;
}

/**


* @author Daniel Jennebo.
* @brief Function sets membervariable #y to params value.
* @param pY (int) contains number of rows (height).
*/
void GameEngine::setY(int pY)
{
	y = pY;
}

/**
* @author Daniel Jennebo.
* @brief Function returns a string with help.
* @return help - Contains help information.
*/
std::string GameEngine::showHelp()
{
	std::string help =	"-h help\n-er <even rulename>[default = conway]\n-or <odd rulename>[default = conway]\n-g <generations>[default = 500]\n-s <widthxheight>[default = 80x24]\n-f <filename for initial state>[default = random state]\n";
	return help;
}

/**
* @author Daniel Jennebo.
* @brief Returns the vector #evenCellMap.
*/
std::vector<std::vector<Cell*>> GameEngine::getVector()
{
	return evenCellMap;
}
