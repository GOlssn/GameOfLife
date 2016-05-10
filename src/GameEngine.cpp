#include <vector>

#include "GameEngine.h"
#include "screen.h"
#include "Cell.h"
GameEngine::GameEngine()
{

}

void GameEngine::run() {
	// Om cellmap.size() == 0 kör setStartCellsRandom()
	
	Terminal terminal;
	Screen screen(x, y);
	screen.fill(' ', TerminalColor(COLOR::BLACK, COLOR::WHITE));

	screen.draw(terminal);
	system("pause");
}

//Sätter storlek på fönstret ifall startparameter används
void GameEngine::setWindowSize(std::string size)
{
	//Kolla så att inmatning är korrekt?

	setX(stoi(size.substr(0, size.find("x"))));
	setY(stoi(size.substr(size.find("x")+1)));
}

//Sätter antalet generationer ifall startparameter används
void GameEngine::setGenerations(std::string pGenerations)
{
	generations = stoi(pGenerations);
}

int GameEngine::getGenerations() const
{
	return generations;
}

//Sätter oddRule om startparameter används
void GameEngine::setOddRule(std::string rule)
{
}

//Sätter evenRule om startparameter används
void GameEngine::setEvenRule(std::string rule)
{
}

//Sätter startceller, läser från fil om startparameter används
void GameEngine::readStartCellsFromFile(std::string file)
{
}

//Sätter startceller random
void GameEngine::setStartCellsRandom()
{
}

//Hämtar x-värdet
int GameEngine::getX() const
{
	return x;
}

void GameEngine::setX(int pX)
{
	x = pX;
}

//Hämtar y-värdet
int GameEngine::getY() const
{ 
	return y;
}

void GameEngine::setY(int pY)
{
	y = pY;
}

//Returnerar hjälptext ifall startparameter används
std::string GameEngine::showHelp()
{
	std::string help =	"-h help\n-er <even rulename>[default = conway]\n-or <odd rulename>[default = conway]\n-g <generations>[default = 500]\n-s <widthxheight>[default = 80x24]\n-f <filename for initial state>[default = random state]\n";
	return help;
}
