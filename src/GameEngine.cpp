#include "GameEngine.h"
#include "screen.h"
#include "Cell.h"
#include <random>

/**
* @author Daniel Jennebo.
* @brief Default constuct for GameEngine class.
*/
GameEngine::GameEngine()
{

}

/**
* @author Daniel Jennebo.
* @brief Destructor for GameEngine class. Deletes pointers in cellMap
*/
GameEngine::~GameEngine() {
	for (auto row : cellMap) {
		for (auto cell : row) {
			delete cell;
		}
	}
	cellMap.clear();
}

/**
* @brief Function handles the programs runtime.
*/
void GameEngine::run() {
	if (cellMap.size() == 0) {
		setStartCellsRandom();
	}
	
	Terminal terminal;
	Screen screen(x, y);
	screen.fill(' ', TerminalColor(COLOR::BLACK, COLOR::WHITE));
	screen.draw(terminal);
	system("pause");
}

/**
* @author Daniel Jennebo.
* @brief Function sets x and y values to determine size of terminal window.
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
* @brief Function sets number of generations to iterate trough. Sets the membervariable to params value.
* @param pGenerations contains a string with number of generations.
*/
void GameEngine::setGenerations(std::string pGenerations)
{
	generations = stoi(pGenerations);
}

/**
* @author Daniel Jennebo.
* @brief Function returns membervariable generations.
* @return membervariable generations as int.
*/
int GameEngine::getGenerations() const
{
	return generations;
}

/**
* @author Daniel Jennebo.
* @brief Function sets membervariable oddRule value to params value. 
* @param rule contains a rule object.
*/
void GameEngine::setOddRule(/*Rule rule*/)
{
	//oddRule = rule;
}

/**
* @author Daniel Jennebo.
* @brief Function sets membervariable evenRule value to params value.
* @param rule contains a rule object.
*/
void GameEngine::setEvenRule(/*Rule rule*/)
{
	//evenRule = rule;
}

//Sätter startceller, läser från fil om startparameter används
void GameEngine::readStartCellsFromFile(std::string file)
{

}

/**
* @author Daniel Jennebo.
* @brief Function make random number of cells alive at random places in cellMap.
*/
void GameEngine::setStartCellsRandom()
{
	initCellMap();
	std::default_random_engine generator;
	std::uniform_int_distribution<int> cellNumRand(1,x*y);
	std::uniform_int_distribution<int> rowRand(0, y-1);
	std::uniform_int_distribution<int> colRand(0, x-1);

	int numberOfAlive = cellNumRand(generator);
	for (int i = 0; i < numberOfAlive; i++) {
		cellMap[rowRand(generator)].at(colRand(generator))->revive();
	}
}

/**
* @author Daniel Jennebo.
* @brief Function initiate the cellMap vector with dead cells.
*/
void GameEngine::initCellMap() {
	std::vector<Cell*> tmp;
	for (int col = 0; col < y; col++) {
		for (int row = 0; row < x; row++) {
			tmp.push_back(new Cell);
		}
		cellMap.push_back(tmp);
		tmp.clear();
	}
}

/**
* @author Daniel Jennebo.
* @brief Function returns membervariable x.
* @return membervariable x as int.
*/
int GameEngine::getX() const
{
	return x;
}

/**
* @author Daniel Jennebo.
* @brief Function sets membervariable x to params value.
* @param pX (int) contains number of columns.
*/
void GameEngine::setX(int pX)
{
	x = pX;
}

/**
* @author Daniel Jennebo.
* @brief Function returns membervariable y.
* @return membervariable y as int.
*/
int GameEngine::getY() const
{ 
	return y;
}

/**
* @author Daniel Jennebo.
* @brief Function sets membervariable y to params value.
* @param pY (int) contains number of columns.
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

std::vector<std::vector<Cell*>> GameEngine::getVector()
{
	return cellMap;
}
