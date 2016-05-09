#include "..\include\GameEngine.h"
#include "GameEngine.h"
#include "screen.h"
#include "Cell.h"
#include <random>
#include <fstream>

const std::string DELIM = ",";
/**
* Default constuct for GameEngine class
*/
GameEngine::GameEngine()
{

}

/**
* Function handles the programs runtime
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
* Function sets x and y values to determine size of terminal window
* @param size contains a string with "WIDTHxHEIGHT"
*/
void GameEngine::setWindowSize(std::string size)
{
	//Kolla så att inmatning är korrekt?

	setX(stoi(size.substr(0, size.find("x"))));
	setY(stoi(size.substr(size.find("x")+1)));
}


/**
* Function sets number of generations to iterate trough. Sets the membervariable to params value.
* @param pGenerations contains a string with number of generations.
*/
void GameEngine::setGenerations(std::string pGenerations)
{
	generations = stoi(pGenerations);
}

/**
* Function returns membervariable generations.
* @return membervariable generations as int.
*/
int GameEngine::getGenerations() const
{
	return generations;
}


/**
* Function sets membervariable oddRule value to params value. 
* @param rule contains a rule object.
*/
void GameEngine::setOddRule(/*Rule rule*/)
{
	//oddRule = rule;
}


/**
* Function sets membervariable evenRule value to params value.
* @param rule contains a rule object.
*/
void GameEngine::setEvenRule(/*Rule rule*/)
{
	//evenRule = rule;
}


/**
* @author Pontus Stenlund
* @brief Reads from file and sets windowsize and which cells 
* to be alive.
* @param file is the string that holds the name of the file to be read.
*/
void GameEngine::readStartCellsFromFile(std::string file)
{
	/*
	ex:
	80x24
	10,10
	10,11
	10,20 
	etc
	*/
	std::ifstream inFile(file);
	if (inFile.good())
	{
		std::string size;
		getline(inFile, size);
		setWindowSize(size);
		initCellMap();

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

			cellMap[posY][posX]->revive();
		}
	}

	inFile.close();
}


bool GameEngine::getCell()
{
	// hardcoded for testcase
	return cellMap[1][1]->isAlive();
}

/**
* Function make random number of cells alive at random places in cellMap
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
* Function initiate the cellMap vector with dead cells
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
* Function returns membervariable x.
* @return membervariable x as int.
*/
int GameEngine::getX() const
{
	return x;
}

/**
* Function sets membervariable x to params value.
* @param pX (int) contains number of columns.
*/
void GameEngine::setX(int pX)
{
	x = pX;
}


/**
* Function returns membervariable y.
* @return membervariable y as int.
*/
int GameEngine::getY() const
{ 
	return y;
}

/**
* Function sets membervariable y to params value.
* @param pY (int) contains number of columns.
*/
void GameEngine::setY(int pY)
{
	y = pY;
}


/**
* Function returns a string with help.
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
