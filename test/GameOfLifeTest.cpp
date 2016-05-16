#include <catch.hpp>
#include "GameEngine.h"
#include "ConwayRule.h"
#include "PontusRule.h"
#include <fstream>
#include "memstat.hpp"
#include "DanielRule.h"

TEST_CASE("Cell class test") {
	SECTION("Check isAlive function TRUE") {
		Cell cell;
		cell.revive();
		REQUIRE(cell.isAlive() == true);
	}
	SECTION("Check isAlive function FALSE") {
		Cell cell;
		REQUIRE(cell.isAlive() == false);
	}
	SECTION("cell.kill() turn alive cell to false") {
		Cell cell;
		cell.kill();
		REQUIRE(cell.isAlive() == false);
	}

	SECTION("cell.revive() turn dead cell to alive") {
		Cell cell;
		cell.revive();
		REQUIRE(cell.isAlive() == true);
	}
	//KOLLA TEST, KAN INTE HA == COLOR::BLUE
	SECTION("cell.getColorAlive() & cell.setColorAlive() testing set and get of member color") {
		Terminal t;
		Cell cell;
		cell.setColorAlive(COLOR::BLUE);

		REQUIRE(static_cast<int>(cell.getColorAlive()) == static_cast<int>(COLOR::BLUE));
	}
	//KOLLA TEST, KAN INTE HA == COLOR::BLUE
	SECTION("cell.getColorDead() & cell.setColorDead() testing set and get of member color") {
		Terminal t;
		Cell cell;
		cell.setColorDead(COLOR::BLUE);

		REQUIRE(static_cast<int>(cell.getColorDead()) == static_cast<int>(COLOR::BLUE));
	}

	SECTION("cell.getAge() & cell.setAge() testing set and get of member age") {
		Cell cell;
		cell.setAge(1);
		REQUIRE(cell.getAge() == 1);
	}
}

TEST_CASE("GameEngine Class test") {
	SECTION("Test printHelp function") {
		GameEngine ge;
		REQUIRE(ge.showHelp() == "-h help\n-er <even rulename>[default = conway]\n-or <odd rulename>[default = conway]\n-g <generations>[default = 500]\n-s <widthxheight>[default = 80x24]\n-f <filename for initial state>[default = random state]\n");
	}
	SECTION("Test function setX && getX") {
		GameEngine ge;
		ge.setX(10);
		REQUIRE(ge.getX() == 10);
	}
	SECTION("Test function setY && getY") {
		GameEngine ge;
		ge.setY(5);
		REQUIRE(ge.getY() == 5);
	}
	SECTION("Test setWindowSize function") {
		GameEngine ge;
		ge.setWindowSize("10x15");
		REQUIRE(ge.getX() == 10);
		REQUIRE(ge.getY() == 15);
	}
	SECTION("Test function setGenerations and getGenerations") {
		GameEngine ge;
		ge.setGenerations("200");
		REQUIRE(ge.getGenerations() == 200);
	}
	SECTION("Test function initCellMaps() rows and columns") {
		GameEngine ge;
		ge.initCellMaps();

		REQUIRE(ge.getVector().size() == 24); //Checking height to be correct amount
		for (int i = 0; i < ge.getVector().size(); i++) {
			REQUIRE(ge.getVector().at(i).size() == 80); //Checking witdh to be correct amount
		}
		
	}
	SECTION("Test function setStartCellsRandom(), if random alive cell works") {
		GameEngine ge;
		ge.setStartCellsRandom();
		bool aliveCell = false;
		for (auto row : ge.getVector()) {	//looping cellmap
			for (auto cell : row) {
				if (cell->isAlive()) {		//If at least one cell is alive the function works
					aliveCell = true;
					break;
				}
			}
			if (aliveCell) {
				break;
			}
		}
		REQUIRE(aliveCell == true);
	}

	SECTION("Test read from file") {
		std::ofstream file;
		file.open("test.txt");
		file << "2x2\n0,0\n1,1";
		file.close();
		GameEngine ge;
		ge.readStartCellsFromFile("test.txt");
		REQUIRE(ge.getVector()[1][1]->isAlive());
	}

}

TEST_CASE("Testing Conway Rule") {
	
	std::vector<std::vector<Cell*>> cellMap;
	std::vector<std::vector<Cell*>> newCellMap;
	std::vector<Cell*> cellMapRow;
	std::vector<Cell*> newCellMapRow;

	cellMapRow.push_back(new Cell());
	cellMapRow.push_back(new Cell());
	cellMapRow.push_back(new Cell());
	cellMap.push_back(cellMapRow);
	cellMapRow.clear();
	cellMapRow.push_back(new Cell());
	cellMapRow.push_back(new Cell());
	cellMapRow.push_back(new Cell());
	cellMap.push_back(cellMapRow);
	cellMapRow.clear();
	cellMapRow.push_back(new Cell());
	cellMapRow.push_back(new Cell());
	cellMapRow.push_back(new Cell());
	cellMap.push_back(cellMapRow);
	cellMapRow.clear();
	
	newCellMapRow.push_back(new Cell());
	newCellMapRow.push_back(new Cell());
	newCellMapRow.push_back(new Cell());
	newCellMap.push_back(newCellMapRow);
	newCellMapRow.clear();
	newCellMapRow.push_back(new Cell());
	newCellMapRow.push_back(new Cell());
	newCellMapRow.push_back(new Cell());
	newCellMap.push_back(newCellMapRow);
	newCellMapRow.clear();
	newCellMapRow.push_back(new Cell());
	newCellMapRow.push_back(new Cell());
	newCellMapRow.push_back(new Cell());
	newCellMap.push_back(newCellMapRow);
	newCellMapRow.clear();
	
	Rule *rule = new ConwayRule();


	SECTION("A living cell that has less than two living neighbours will die") {

		// Given there is one cell at coordinates 1,1 that is alive
		// And no more than ONE of the surrounding cells are alive
		cellMap[1][1]->revive();
		cellMap[0][1]->revive();

		// When rules are applied

		rule->applyRules(cellMap, newCellMap);
		
		// Then that cell should be dead
		REQUIRE(!newCellMap[1][1]->isAlive());

	}

	SECTION("A living cell with two to three living neighbours will survive") {
		// Given there is one cell at coordinates 1,1 that is alive
		// And two of its neighbours are alive
		cellMap[1][1]->revive();
		cellMap[0][0]->revive();
		cellMap[0][1]->revive();

		// When the rules are applied

		rule->applyRules(cellMap, newCellMap);

		// Then that cell should still be alive
		REQUIRE(newCellMap[1][1]->isAlive());

	}

	SECTION("A living cell with more than three living neighbours will die") {
		// Given there is one cell at coordinates 1,1 that is alive
		// And four of its neighbours are alive
		cellMap[1][1]->revive();
		cellMap[0][0]->revive();
		cellMap[0][1]->revive();
		cellMap[1][0]->revive();
		cellMap[1][2]->revive();

		// When the rules are applied

		rule->applyRules(cellMap, newCellMap);

		// Then that cell should be dead
		REQUIRE(!newCellMap[1][1]->isAlive());

	}

	SECTION("A dead cell with exactly three neighbours is alive after applying rules") {
		// Given there is one cell at coordinates 1,1 that is dead
		// And exactly three of its neighbours are alive
		cellMap[1][1]->kill();
		cellMap[0][0]->revive();
		cellMap[0][1]->revive();
		cellMap[1][0]->revive();

		// When the rules are applied

		rule->applyRules(cellMap, newCellMap);

		// Then that cell should be alive
		REQUIRE(newCellMap[1][1]->isAlive());

	}

	SECTION("Testing grid wrap functionality") {
		// Given there are cells at coordinates 1,1 | 0,0 | 0,1 that are alive
		cellMap[0][0]->revive();
		cellMap[0][1]->revive();
		cellMap[1][1]->revive();

		// When rules are applied

		rule->applyRules(cellMap, newCellMap);

		// Then all cells should be alive
		REQUIRE(newCellMap[0][0]->isAlive());
		REQUIRE(newCellMap[0][1]->isAlive());
		REQUIRE(newCellMap[0][2]->isAlive());
		REQUIRE(newCellMap[1][0]->isAlive());
		REQUIRE(newCellMap[1][1]->isAlive());
		REQUIRE(newCellMap[1][2]->isAlive());
		REQUIRE(newCellMap[2][0]->isAlive());
		REQUIRE(newCellMap[2][1]->isAlive());
		REQUIRE(newCellMap[2][2]->isAlive());

	}

	for (auto row : cellMap) {
		for (auto cell : row) {
			delete cell;
		}
	}

	for (auto row : newCellMap) {
		for (auto cell : row) {
			delete cell;
		}
	}

	delete rule;
}


TEST_CASE("Testing Daniel Rule") {
	std::vector<std::vector<Cell*>> cellMap;
	std::vector<std::vector<Cell*>> newCellMap;
	std::vector<Cell*> cellMapRow;
	std::vector<Cell*> newCellMapRow;

	cellMapRow.push_back(new Cell());
	cellMapRow.push_back(new Cell());
	cellMapRow.push_back(new Cell());
	cellMap.push_back(cellMapRow);
	cellMapRow.clear();
	cellMapRow.push_back(new Cell());
	cellMapRow.push_back(new Cell());
	cellMapRow.push_back(new Cell());
	cellMap.push_back(cellMapRow);
	cellMapRow.clear();
	cellMapRow.push_back(new Cell());
	cellMapRow.push_back(new Cell());
	cellMapRow.push_back(new Cell());
	cellMap.push_back(cellMapRow);
	cellMapRow.clear();

	newCellMapRow.push_back(new Cell());
	newCellMapRow.push_back(new Cell());
	newCellMapRow.push_back(new Cell());
	newCellMap.push_back(newCellMapRow);
	newCellMapRow.clear();
	newCellMapRow.push_back(new Cell());
	newCellMapRow.push_back(new Cell());
	newCellMapRow.push_back(new Cell());
	newCellMap.push_back(newCellMapRow);
	newCellMapRow.clear();
	newCellMapRow.push_back(new Cell());
	newCellMapRow.push_back(new Cell());
	newCellMapRow.push_back(new Cell());
	newCellMap.push_back(newCellMapRow);
	newCellMapRow.clear();

	Rule *drule = new DanielRule();

	SECTION("When one alive cell is over age 4 it should die") {
		
		//Given there is one alive cell at age 4
		cellMap[1][1]->revive();
		cellMap[1][1]->setAge(4);
		//When rules are applied
		drule->applyRules(cellMap, newCellMap);
		//It should be dead
		REQUIRE(!newCellMap[1][1]->isAlive());

	}

	SECTION("When one alive cell has 4 or more alive neighbours it should die") {

		//Given there are one cell alive with 4 alive neighbours
		cellMap[1][1]->revive();
		cellMap[0][1]->revive();
		cellMap[1][2]->revive();
		cellMap[1][0]->revive();
		cellMap[0][0]->revive();

	
		//When rules are applied
		drule->applyRules(cellMap, newCellMap);
		//The cell should be dead
		REQUIRE(!newCellMap[1][1]->isAlive());

	}

	SECTION("When one alive cell is age 1, coloralive should be YELLOW") {
		//Given we have an alive cell with age 1 (It will age one in applyrules)
		cellMap[1][1]->revive();//Cause rule increses age by 1

		//When rules are applied
		drule->applyRules(cellMap, newCellMap);
		//It should have color yellow
		REQUIRE(static_cast<int>(newCellMap[1][1]->getColorAlive()) == static_cast<int>(COLOR::YELLOW));
		REQUIRE(newCellMap[1][1]->getAge() == 1);

	}

	SECTION("When one alive cell is age 2, coloralive should be CYAN") {
		//Given we have an alive cell with age 2 (It will age one in applyrules)
		cellMap[1][1]->revive();
		cellMap[1][1]->setAge(1);//Cause rule increses age by 1

		//When rules are applied
		drule->applyRules(cellMap, newCellMap);

		//It should have color Cyan
		REQUIRE(static_cast<int>(newCellMap[1][1]->getColorAlive()) == static_cast<int>(COLOR::CYAN));
		REQUIRE(newCellMap[1][1]->getAge() == 2);

	}

	SECTION("When one alive cell is age 3, coloralive should be BLUE") {
		//Given we have an alive cell with age 3 (It will age one in applyrules)
		cellMap[1][1]->revive();
		cellMap[1][1]->setAge(2);//Cause rule increses age by 1
		//When rules are applied
		drule->applyRules(cellMap, newCellMap);
		//It should have color blue
		REQUIRE(static_cast<int>(newCellMap[1][1]->getColorAlive()) == static_cast<int>(COLOR::BLUE));
		REQUIRE(newCellMap[1][1]->getAge() == 3);
	}


	SECTION("When one alive cell is age 4, coloralive should be RED") {
		//Given we have an alive cell with age 4 (It will age one in applyrules)
		cellMap[1][1]->revive();
		cellMap[1][1]->setAge(3); //Cause rule increses age by 1
		//When rules are applied
		drule->applyRules(cellMap, newCellMap);
		//It should have color Red
		REQUIRE(static_cast<int>(newCellMap[1][1]->getColorAlive()) == static_cast<int>(COLOR::RED));
		REQUIRE(newCellMap[1][1]->getAge() == 4);

	}

	SECTION("When one dead cell has 2 neighbours that is age 1 or more, the cell should come to life") {
		//Given we have one dead cell with 2 alive neighbours with age 1 (or more)
		cellMap[1][1]->revive();
		cellMap[1][1]->setAge(1);
		cellMap[1][0]->revive();
		cellMap[1][0]->setAge(1);
		//When rules are applied
		drule->applyRules(cellMap, newCellMap);
		//The cell should be alive
		REQUIRE(newCellMap[0][0]->isAlive());

	}

	for (auto row : cellMap) {
		for (auto cell : row) {
			delete cell;
		}
	}

	for (auto row : newCellMap) {
		for (auto cell : row) {
			delete cell;
		}
	}

	delete drule;

}

TEST_CASE("Testing Pontus Rule") {

	std::vector<std::vector<Cell*>> cellMap;
	std::vector<std::vector<Cell*>> newCellMap;
	std::vector<Cell*> cellMapRow;
	std::vector<Cell*> newCellMapRow;

	cellMapRow.push_back(new Cell());
	cellMapRow.push_back(new Cell());
	cellMapRow.push_back(new Cell());
	cellMap.push_back(cellMapRow);
	cellMapRow.clear();
	cellMapRow.push_back(new Cell());
	cellMapRow.push_back(new Cell());
	cellMapRow.push_back(new Cell());
	cellMap.push_back(cellMapRow);
	cellMapRow.clear();
	cellMapRow.push_back(new Cell());
	cellMapRow.push_back(new Cell());
	cellMapRow.push_back(new Cell());
	cellMap.push_back(cellMapRow);
	cellMapRow.clear();

	newCellMapRow.push_back(new Cell());
	newCellMapRow.push_back(new Cell());
	newCellMapRow.push_back(new Cell());
	newCellMap.push_back(newCellMapRow);
	newCellMapRow.clear();
	newCellMapRow.push_back(new Cell());
	newCellMapRow.push_back(new Cell());
	newCellMapRow.push_back(new Cell());
	newCellMap.push_back(newCellMapRow);
	newCellMapRow.clear();
	newCellMapRow.push_back(new Cell());
	newCellMapRow.push_back(new Cell());
	newCellMapRow.push_back(new Cell());
	newCellMap.push_back(newCellMapRow);
	newCellMapRow.clear();

	Rule *rule = new PontusRule();

	SECTION("A living cell that has one neighbour vill live") {

		// Given there is one cell at coordinates 1,1 that is alive
		// with one living neighbour
		cellMap[0][1]->revive();
		cellMap[1][1]->revive();

		// When rules are applied

		rule->applyRules(cellMap, newCellMap);

		// Then that cell should be alive
		REQUIRE(newCellMap[1][1]->isAlive());

	}
	
	SECTION("A living cell that has two neighbours vill live") {

		// Given there is one cell at coordinates 1,1 that is alive
		// with two living neighbours
		cellMap[0][0]->revive();
		cellMap[0][1]->revive();
		cellMap[1][1]->revive();


		// When rules are applied

		rule->applyRules(cellMap, newCellMap);

		// Then that cell should be alive
		REQUIRE(newCellMap[1][1]->isAlive());

	}

	SECTION("A living cell that has three neighbours vill live") {

		// Given there is one cell at coordinates 1,1 that is alive
		// with three living neighbours
		cellMap[0][0]->revive();
		cellMap[0][1]->revive();
		cellMap[0][2]->revive();
		cellMap[1][1]->revive();


		// When rules are applied

		rule->applyRules(cellMap, newCellMap);

		// Then that cell should be alive
		REQUIRE(newCellMap[1][1]->isAlive());

	}

	SECTION("A living cell that has four neighbours vill live") {

		// Given there is one cell at coordinates 1,1 that is alive
		// with four living neighbours
		cellMap[0][0]->revive();
		cellMap[0][1]->revive();
		cellMap[0][2]->revive();
		cellMap[1][0]->revive();
		cellMap[1][1]->revive();


		// When rules are applied

		rule->applyRules(cellMap, newCellMap);

		// Then that cell should be alive
		REQUIRE(newCellMap[1][1]->isAlive());

	}
	
	SECTION("A living cell that has five neighbours vill live") {

		// Given there is one cell at coordinates 1,1 that is alive
		// with five living neighbours
		cellMap[0][0]->revive();
		cellMap[0][1]->revive();
		cellMap[0][2]->revive();
		cellMap[1][0]->revive();
		cellMap[1][1]->revive();
		cellMap[1][2]->revive();


		// When rules are applied

		rule->applyRules(cellMap, newCellMap);

		// Then that cell should be alive
		REQUIRE(newCellMap[1][1]->isAlive());


	}

	SECTION("A living cell that has six neighbours vill live") {

		// Given there is one cell at coordinates 1,1 that is alive
		// with six living neighbours
		cellMap[0][0]->revive();
		cellMap[0][1]->revive();
		cellMap[0][2]->revive();
		cellMap[1][0]->revive();
		cellMap[1][1]->revive();
		cellMap[1][2]->revive();
		cellMap[2][0]->revive();


		// When rules are applied

		rule->applyRules(cellMap, newCellMap);

		// Then that cell should be alive
		REQUIRE(newCellMap[1][1]->isAlive());

	}

	SECTION("A living cell that has seven neighbours vill live") {

		// Given there is one cell at coordinates 1,1 that is alive
		// with seven living neighbours
		cellMap[0][0]->revive();
		cellMap[0][1]->revive();
		cellMap[0][2]->revive();
		cellMap[1][0]->revive();
		cellMap[1][1]->revive();
		cellMap[1][2]->revive();
		cellMap[2][0]->revive();
		cellMap[2][1]->revive();


		// When rules are applied

		rule->applyRules(cellMap, newCellMap);

		// Then that cell should be alive
		REQUIRE(newCellMap[1][1]->isAlive());

	}

	SECTION("A dead cell that has one neighbour will revive") {
		// Given there is one cell at coordinates 1,1 that is dead
		// // with one living neighbour
		cellMap[0][0]->revive();
		cellMap[1][1]->kill();

		// When rules are applied

		rule->applyRules(cellMap, newCellMap);

		// Then that cell should be alive
		REQUIRE(newCellMap[1][1]->isAlive());

	}
	
	SECTION("A dead cell that has two neighbour will revive") {
		// Given there is one cell at coordinates 1,1 that is dead
		// with two living neighbours
		cellMap[0][0]->revive();
		cellMap[0][1]->revive();
		cellMap[1][1]->kill();

		// When rules are applied

		rule->applyRules(cellMap, newCellMap);

		// Then that cell should be alive
		REQUIRE(newCellMap[1][1]->isAlive());

	}

	SECTION("A dead cell that has three neighbour will revive") {
		// Given there is one cell at coordinates 1,1 that is dead
		// with three living neighbours
		cellMap[0][0]->revive();
		cellMap[0][1]->revive();
		cellMap[0][2]->revive();
		cellMap[1][1]->kill();

		// When rules are applied

		rule->applyRules(cellMap, newCellMap);

		// Then that cell should be alive
		REQUIRE(newCellMap[1][1]->isAlive());

	}

	SECTION("A dead cell that has four neighbour will revive") {
		// Given there is one cell at coordinates 1,1 that is dead
		// with four living neighbours
		cellMap[0][0]->revive();
		cellMap[0][1]->revive();
		cellMap[0][2]->revive();
		cellMap[1][0]->revive();
		cellMap[1][1]->kill();

		// When rules are applied

		rule->applyRules(cellMap, newCellMap);

		// Then that cell should be alive
		REQUIRE(newCellMap[1][1]->isAlive());

	}

	SECTION("A dead cell that has five neighbour will revive") {
		// Given there is one cell at coordinates 1,1 that is dead
		// with five living neighbours
		cellMap[0][0]->revive();
		cellMap[0][1]->revive();
		cellMap[0][2]->revive();
		cellMap[1][0]->revive();
		cellMap[1][2]->revive();
		cellMap[1][1]->kill();

		// When rules are applied

		rule->applyRules(cellMap, newCellMap);

		// Then that cell should be alive
		REQUIRE(newCellMap[1][1]->isAlive());

	}

	SECTION("A dead cell that has six neighbour will revive") {
		// Given there is one cell at coordinates 1,1 that is dead
		// with six living neighbours
		cellMap[0][0]->revive();
		cellMap[0][1]->revive();
		cellMap[0][2]->revive();
		cellMap[1][0]->revive();
		cellMap[1][2]->revive();
		cellMap[2][0]->revive();
		cellMap[1][1]->kill();

		// When rules are applied

		rule->applyRules(cellMap, newCellMap);

		// Then that cell should be alive
		REQUIRE(newCellMap[1][1]->isAlive());

	}

	SECTION("A dead cell that has seven neighbour will revive") {
		// Given there is one cell at coordinates 1,1 that is dead
		// with seven living neighbours
		cellMap[0][0]->revive();
		cellMap[0][1]->revive();
		cellMap[0][2]->revive();
		cellMap[1][0]->revive();
		cellMap[1][2]->revive();
		cellMap[2][0]->revive();
		cellMap[2][1]->revive();
		cellMap[1][1]->kill();

		// When rules are applied

		rule->applyRules(cellMap, newCellMap);

		// Then that cell should be alive
		REQUIRE(newCellMap[1][1]->isAlive());

	}

	SECTION("A living cell with zero neighbours will die") {
		// Given there is one cell at coordinates 1,1 that is living
		// with zero living neighbours
		cellMap[1][1]->revive();

		// When rules are applied

		rule->applyRules(cellMap, newCellMap);

		// Then that cell should be dead
		REQUIRE(!newCellMap[1][1]->isAlive());

	}

	SECTION("A living cell with eight neighbours will die") {
		// Given there is one cell at coordinates 1,1 that is living
		// with eight living neighbours
		cellMap[0][0]->revive();
		cellMap[0][1]->revive();
		cellMap[0][2]->revive();
		cellMap[1][0]->revive();
		cellMap[1][1]->revive();
		cellMap[1][2]->revive();
		cellMap[2][0]->revive();
		cellMap[2][1]->revive();
		cellMap[2][2]->revive();

		// When rules are applied

		rule->applyRules(cellMap, newCellMap);

		// Then that cell should be dead
		REQUIRE(!newCellMap[1][1]->isAlive());

	}

	SECTION("A dead cell with zero neighbours will not turn to living") {
		// Given there is one cell at coordinates 1,1 that is dead
		// with zero living neighbours
		cellMap[1][1]->kill();

		// When rules are applied

		rule->applyRules(cellMap, newCellMap);

		// Then that cell should be dead
		REQUIRE(!newCellMap[1][1]->isAlive());

	}

	SECTION("A dead cell with eight neighbours will not turn to living") {
		// Given there is one cell at coordinates 1,1 that is dead
		// with eight living neighbours
		cellMap[0][0]->revive();
		cellMap[0][1]->revive();
		cellMap[0][2]->revive();
		cellMap[1][0]->revive();
		cellMap[1][1]->kill();
		cellMap[1][2]->revive();
		cellMap[2][0]->revive();
		cellMap[2][1]->revive();
		cellMap[2][2]->revive();

		// When rules are applied

		rule->applyRules(cellMap, newCellMap);

		// Then that cell should be dead
		REQUIRE(!newCellMap[1][1]->isAlive());
	}


	for (auto row : cellMap) {
		for (auto cell : row) {
			delete cell;
		}
	}

	for (auto row : newCellMap) {
		for (auto cell : row) {
			delete cell;
		}
	}

	delete rule;

}