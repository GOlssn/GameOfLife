#include "GameEngine.h"
#include "screen.h"

GameEngine::GameEngine()
{

}

void GameEngine::run() {
	// Om cellmap.size() == 0 k�r setStartCellsRandom()
	Terminal terminal;
	Screen screen(x, y);
	screen.fill(' ', TerminalColor(COLOR::BLACK, COLOR::WHITE));

	screen.draw(terminal);
	system("pause");
}

//S�tter storlek p� f�nstret ifall startparameter anv�nds
void GameEngine::setWindowSize(std::string size)
{
}

//S�tter antalet generationer ifall startparameter anv�nds
void GameEngine::setGenerations(std::string pGenerations)
{
}

//S�tter oddRule om startparameter anv�nds
void GameEngine::setOddRule(std::string rule)
{
}

//S�tter evenRule om startparameter anv�nds
void GameEngine::setEvenRule(std::string rule)
{
}

//S�tter startceller, l�ser fr�n fil om startparameter anv�nds
void GameEngine::readStartCellsFromFile(std::string file)
{
}

//S�tter startceller random
void GameEngine::setStartCellsRandom()
{
}

//Returnerar hj�lptext ifall startparameter anv�nds
std::string GameEngine::showHelp()
{
	return std::string();
}
