#include "GameEngine.h"
#include "screen.h"

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
}

//Sätter antalet generationer ifall startparameter används
void GameEngine::setGenerations(std::string pGenerations)
{
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

//Returnerar hjälptext ifall startparameter används
std::string GameEngine::showHelp()
{
	return std::string();
}
