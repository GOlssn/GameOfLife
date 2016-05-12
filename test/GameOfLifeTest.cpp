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
		//REQUIRE(cell.getColorAlive() == COLOR::BLUE);
	}
	//KOLLA TEST, KAN INTE HA == COLOR::BLUE
	SECTION("cell.getColorDead() & cell.setColorDead() testing set and get of member color") {
		Terminal t;
		Cell cell;
		cell.setColorDead(COLOR::BLUE);
		//REQUIRE(cell.getColorAlive() == COLOR::BLUE);
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
	SECTION("Test function initCellMap() rows and columns") {
		GameEngine ge;
		ge.initCellMap();

		REQUIRE(ge.getVector().size() == 24);
		for (int i = 0; i < ge.getVector().size(); i++) {
			REQUIRE(ge.getVector().at(i).size() == 80);
		}
		
	}
	SECTION("Test function setStartCellsRandom(), if random alive cell works") {
		GameEngine ge;
		ge.setStartCellsRandom();
		bool aliveCell = false;
		for (auto row : ge.getVector()) {
			for (auto cell : row) {
				if (cell->isAlive()) {
					aliveCell = true;
				}
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
	std::vector<Cell*> cellMapRow;

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

	Rule *rule = new ConwayRule();

	SECTION("A living cell that has less than two living neighbours will die") {

		// Given there is one cell at coordinates 1,1 that is alive
		// And no more than ONE of the surrounding cells are alive
		cellMap[1][1]->revive();
		cellMap[0][1]->revive();

		// When rules are applied
		std::vector<std::vector<Cell*>> newCellMap = rule->applyRules(cellMap);
		
		// Then that cell should be dead
		REQUIRE(!newCellMap[1][1]->isAlive());
		for (auto row : newCellMap) {
			for (auto cell : row) {
				delete cell;
			}
		}

	}

	SECTION("A living cell with two to three living neighbours will survive") {
		// Given there is one cell at coordinates 1,1 that is alive
		// And two of its neighbours are alive
		cellMap[1][1]->revive();
		cellMap[0][0]->revive();
		cellMap[0][1]->revive();

		// When the rules are applied
		std::vector<std::vector<Cell*>> newCellMap = rule->applyRules(cellMap);

		// Then that cell should still be alive
		REQUIRE(newCellMap[1][1]->isAlive());
		for (auto row : newCellMap) {
			for (auto cell : row) {
				delete cell;
			}
		}
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
		std::vector<std::vector<Cell*>> newCellMap = rule->applyRules(cellMap);

		// Then that cell should be dead
		REQUIRE(!newCellMap[1][1]->isAlive());
		for (auto row : newCellMap) {
			for (auto cell : row) {
				delete cell;
			}
		}
	}

	SECTION("A dead cell with exactly three neighbours is alive after applying rules") {
		// Given there is one cell at coordinates 1,1 that is dead
		// And exactly three of its neighbours are alive
		cellMap[1][1]->kill();
		cellMap[0][0]->revive();
		cellMap[0][1]->revive();
		cellMap[1][0]->revive();

		// When the rules are applied
		std::vector<std::vector<Cell*>> newCellMap = rule->applyRules(cellMap);

		// Then that cell should be alive
		REQUIRE(newCellMap[1][1]->isAlive());
		for (auto row : newCellMap) {
			for (auto cell : row) {
				delete cell;
			}
		}
	}

	SECTION("Testing grid wrap functionality") {
		// Given there are cells at coordinates 1,1 | 0,0 | 0,1 that are alive
		cellMap[0][0]->revive();
		cellMap[0][1]->revive();
		cellMap[1][1]->revive();

		// When rules are applied
		std::vector<std::vector<Cell*>> newCellMap = rule->applyRules(cellMap);

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
		for (auto row : newCellMap) {
			for (auto cell : row) {
				delete cell;
			}
		}
	}

	delete rule;
}

TEST_CASE("Testing Daniel Rule") {
	std::vector<std::vector<Cell*>> cellMap;
	std::vector<Cell*> cellMapRow;

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
	Rule *drule = new DanielRule();

	SECTION("When one alive cell is over age 4 it should die") {
		
		cellMap[1][1]->revive();
		cellMap[1][1]->setAge(4);
		std::vector<std::vector<Cell*>> newCellMap = drule->applyRules(cellMap);

		REQUIRE(!newCellMap[1][1]->isAlive());

		for (auto row : newCellMap) {
			for (auto cell : row) {
				delete cell;
			}
		}
	}

	SECTION("When one alive cell has 4 or more alive neighbours it should die") {

		cellMap[1][1]->revive();
		cellMap[0][1]->revive();
		cellMap[1][2]->revive();
		cellMap[1][0]->revive();
		cellMap[0][0]->revive();

	
		std::vector<std::vector<Cell*>> newCellMap = drule->applyRules(cellMap);

		REQUIRE(!newCellMap[1][1]->isAlive());

		for (auto row : newCellMap) {
			for (auto cell : row) {
				delete cell;
			}
		}
	}

	SECTION("When one alive cell is age 1, coloralive should be YELLOW") {
		cellMap[1][1]->revive();//Cause rule increses age by 1
		std::vector<std::vector<Cell*>> newCellMap = drule->applyRules(cellMap);
		//REQUIRE(cellMap[1][1]->getColorAlive() == COLOR::YELLOW);
		REQUIRE(newCellMap[1][1]->getAge() == 1);
		for (auto row : newCellMap) {
			for (auto cell : row) {
				delete cell;
			}
		}
	}
	SECTION("When one alive cell is age 2, coloralive should be CYAN") {
		cellMap[1][1]->revive();
		cellMap[1][1]->setAge(1);//Cause rule increses age by 1
		std::vector<std::vector<Cell*>> newCellMap = drule->applyRules(cellMap);
		//REQUIRE(cellMap[1][1]->getColorAlive() == COLOR::CYAN);
		REQUIRE(newCellMap[1][1]->getAge() == 2);
		for (auto row : newCellMap) {
			for (auto cell : row) {
				delete cell;
			}
		}
	}
	SECTION("When one alive cell is age 3, coloralive should be BLUE") {
		cellMap[1][1]->revive();
		cellMap[1][1]->setAge(2);//Cause rule increses age by 1
		std::vector<std::vector<Cell*>> newCellMap = drule->applyRules(cellMap);
		//REQUIRE(cellMap[1][1]->getColorAlive() == COLOR::BLUE);
		REQUIRE(newCellMap[1][1]->getAge() == 3);
		for (auto row : newCellMap) {
			for (auto cell : row) {
				delete cell;
			}
		}
	}
	SECTION("When one alive cell is age 4, coloralive should be RED") {
		cellMap[1][1]->revive();
		cellMap[1][1]->setAge(3); //Cause rule increses age by 1
		std::vector<std::vector<Cell*>> newCellMap = drule->applyRules(cellMap);
		//REQUIRE(cellMap[1][1]->getColorAlive() == COLOR::RED);
		REQUIRE(newCellMap[1][1]->getAge() == 4);
		for (auto row : newCellMap) {
			for (auto cell : row) {
				delete cell;
			}
		}
	}

	SECTION("When one dead cell has 2 neighbours that is age 1 or more, the cell should come to life") {
		cellMap[1][1]->revive();
		cellMap[1][1]->setAge(1);
		cellMap[1][0]->revive();
		cellMap[1][0]->setAge(1);
		std::vector<std::vector<Cell*>> newCellMap = drule->applyRules(cellMap);
		REQUIRE(newCellMap[0][0]->isAlive());
		for (auto row : newCellMap) {
			for (auto cell : row) {
				delete cell;
			}
		}
	}

	delete drule;

}

TEST_CASE("Testing Pontus Rule") {

	std::vector<std::vector<Cell*>> cellMap;
	std::vector<Cell*> cellMapRow;

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

	Rule *rule = new PontusRule();

	SECTION("A living cell that has one neighbour vill live") {

		// Given there is one cell at coordinates 1,1 that is alive
		cellMap[0][1]->revive();
		cellMap[1][1]->revive();
		

		// When rules are applied
		std::vector<std::vector<Cell*>> newCellMap = rule->applyRules(cellMap);

		// Then that cell should be alive
		REQUIRE(newCellMap[1][1]->isAlive());

		for (auto row : newCellMap) {
			for (auto cell : row) {
				delete cell;
			}
		}

	}

	SECTION("A living cell that has two neighbours vill live") {

		// Given there is one cell at coordinates 1,1 that is alive
		cellMap[0][0]->revive();
		cellMap[0][1]->revive();
		cellMap[1][1]->revive();


		// When rules are applied
		std::vector<std::vector<Cell*>> newCellMap = rule->applyRules(cellMap);

		// Then that cell should be alive
		REQUIRE(newCellMap[1][1]->isAlive());

		for (auto row : newCellMap) {
			for (auto cell : row) {
				delete cell;
			}
		}

	}

	SECTION("A living cell that has three neighbours vill live") {

		// Given there is one cell at coordinates 1,1 that is alive
		cellMap[0][0]->revive();
		cellMap[0][1]->revive();
		cellMap[0][2]->revive();
		cellMap[1][1]->revive();


		// When rules are applied
		std::vector<std::vector<Cell*>> newCellMap = rule->applyRules(cellMap);

		// Then that cell should be alive
		REQUIRE(newCellMap[1][1]->isAlive());

		for (auto row : newCellMap) {
			for (auto cell : row) {
				delete cell;
			}
		}

	}

	SECTION("A living cell that has four neighbours vill live") {

		// Given there is one cell at coordinates 1,1 that is alive
		cellMap[0][0]->revive();
		cellMap[0][1]->revive();
		cellMap[0][2]->revive();
		cellMap[1][0]->revive();
		cellMap[1][1]->revive();


		// When rules are applied
		std::vector<std::vector<Cell*>> newCellMap = rule->applyRules(cellMap);

		// Then that cell should be alive
		REQUIRE(newCellMap[1][1]->isAlive());

		for (auto row : newCellMap) {
			for (auto cell : row) {
				delete cell;
			}
		}

	}

	SECTION("A living cell that has five neighbours vill live") {

		// Given there is one cell at coordinates 1,1 that is alive
		cellMap[0][0]->revive();
		cellMap[0][1]->revive();
		cellMap[0][2]->revive();
		cellMap[1][0]->revive();
		cellMap[1][1]->revive();
		cellMap[1][2]->revive();


		// When rules are applied
		std::vector<std::vector<Cell*>> newCellMap = rule->applyRules(cellMap);

		// Then that cell should be alive
		REQUIRE(newCellMap[1][1]->isAlive());

		for (auto row : newCellMap) {
			for (auto cell : row) {
				delete cell;
			}
		}

	}

	SECTION("A living cell that has six neighbours vill live") {

		// Given there is one cell at coordinates 1,1 that is alive
		cellMap[0][0]->revive();
		cellMap[0][1]->revive();
		cellMap[0][2]->revive();
		cellMap[1][0]->revive();
		cellMap[1][1]->revive();
		cellMap[1][2]->revive();
		cellMap[2][0]->revive();


		// When rules are applied
		std::vector<std::vector<Cell*>> newCellMap = rule->applyRules(cellMap);

		// Then that cell should be alive
		REQUIRE(newCellMap[1][1]->isAlive());

		for (auto row : newCellMap) {
			for (auto cell : row) {
				delete cell;
			}
		}

	}

	SECTION("A living cell that has seven neighbours vill live") {

		// Given there is one cell at coordinates 1,1 that is alive
		cellMap[0][0]->revive();
		cellMap[0][1]->revive();
		cellMap[0][2]->revive();
		cellMap[1][0]->revive();
		cellMap[1][1]->revive();
		cellMap[1][2]->revive();
		cellMap[2][0]->revive();
		cellMap[2][1]->revive();


		// When rules are applied
		std::vector<std::vector<Cell*>> newCellMap = rule->applyRules(cellMap);

		// Then that cell should be alive
		REQUIRE(newCellMap[1][1]->isAlive());

		for (auto row : newCellMap) {
			for (auto cell : row) {
				delete cell;
			}
		}

	}

	SECTION("A dead cell that has one neighbour will revive") {
		// Given there is one cell at coordinates 1,1 that is dead
		cellMap[0][0]->revive();
		cellMap[1][1]->kill();

		// When rules are applied
		std::vector<std::vector<Cell*>> newCellMap = rule->applyRules(cellMap);

		// Then that cell should be alive
		REQUIRE(newCellMap[1][1]->isAlive());

		for (auto row : newCellMap) {
			for (auto cell : row) {
				delete cell;
			}
		}
	}

	SECTION("A dead cell that has two neighbour will revive") {
		// Given there is one cell at coordinates 1,1 that is dead
		cellMap[0][0]->revive();
		cellMap[0][1]->revive();
		cellMap[1][1]->kill();

		// When rules are applied
		std::vector<std::vector<Cell*>> newCellMap = rule->applyRules(cellMap);

		// Then that cell should be alive
		REQUIRE(newCellMap[1][1]->isAlive());

		for (auto row : newCellMap) {
			for (auto cell : row) {
				delete cell;
			}
		}
	}

	SECTION("A dead cell that has three neighbour will revive") {
		// Given there is one cell at coordinates 1,1 that is dead
		cellMap[0][0]->revive();
		cellMap[0][1]->revive();
		cellMap[0][2]->revive();
		cellMap[1][1]->kill();

		// When rules are applied
		std::vector<std::vector<Cell*>> newCellMap = rule->applyRules(cellMap);

		// Then that cell should be alive
		REQUIRE(newCellMap[1][1]->isAlive());

		for (auto row : newCellMap) {
			for (auto cell : row) {
				delete cell;
			}
		}
	}

	SECTION("A dead cell that has four neighbour will revive") {
		// Given there is one cell at coordinates 1,1 that is dead
		cellMap[0][0]->revive();
		cellMap[0][1]->revive();
		cellMap[0][2]->revive();
		cellMap[1][0]->revive();
		cellMap[1][1]->kill();

		// When rules are applied
		std::vector<std::vector<Cell*>> newCellMap = rule->applyRules(cellMap);

		// Then that cell should be alive
		REQUIRE(newCellMap[1][1]->isAlive());

		for (auto row : newCellMap) {
			for (auto cell : row) {
				delete cell;
			}
		}
	}

	SECTION("A dead cell that has five neighbour will revive") {
		// Given there is one cell at coordinates 1,1 that is dead
		cellMap[0][0]->revive();
		cellMap[0][1]->revive();
		cellMap[0][2]->revive();
		cellMap[1][0]->revive();
		cellMap[1][2]->revive();
		cellMap[1][1]->kill();

		// When rules are applied
		std::vector<std::vector<Cell*>> newCellMap = rule->applyRules(cellMap);

		// Then that cell should be alive
		REQUIRE(newCellMap[1][1]->isAlive());

		for (auto row : newCellMap) {
			for (auto cell : row) {
				delete cell;
			}
		}
	}

	SECTION("A dead cell that has six neighbour will revive") {
		// Given there is one cell at coordinates 1,1 that is dead
		cellMap[0][0]->revive();
		cellMap[0][1]->revive();
		cellMap[0][2]->revive();
		cellMap[1][0]->revive();
		cellMap[1][2]->revive();
		cellMap[2][0]->revive();
		cellMap[1][1]->kill();

		// When rules are applied
		std::vector<std::vector<Cell*>> newCellMap = rule->applyRules(cellMap);

		// Then that cell should be alive
		REQUIRE(newCellMap[1][1]->isAlive());

		for (auto row : newCellMap) {
			for (auto cell : row) {
				delete cell;
			}
		}
	}

	SECTION("A dead cell that has seven neighbour will revive") {
		// Given there is one cell at coordinates 1,1 that is dead
		cellMap[0][0]->revive();
		cellMap[0][1]->revive();
		cellMap[0][2]->revive();
		cellMap[1][0]->revive();
		cellMap[1][2]->revive();
		cellMap[2][0]->revive();
		cellMap[2][1]->revive();
		cellMap[1][1]->kill();

		// When rules are applied
		std::vector<std::vector<Cell*>> newCellMap = rule->applyRules(cellMap);

		// Then that cell should be alive
		REQUIRE(newCellMap[1][1]->isAlive());

		for (auto row : newCellMap) {
			for (auto cell : row) {
				delete cell;
			}
		}
	}

	SECTION("A living cell with zero neighbours will die") {
		// Given there is one cell at coordinates 1,1 that is living
		cellMap[1][1]->revive();

		// When rules are applied
		std::vector<std::vector<Cell*>> newCellMap = rule->applyRules(cellMap);

		// Then that cell should be dead
		REQUIRE(!newCellMap[1][1]->isAlive());

			for (auto row : newCellMap) {
				for (auto cell : row) {
					delete cell;
				}
			}
	}

	SECTION("A living cell with eight neighbours will die") {
		// Given there is one cell at coordinates 1,1 that is living
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
		std::vector<std::vector<Cell*>> newCellMap = rule->applyRules(cellMap);

		// Then that cell should be dead
		REQUIRE(!newCellMap[1][1]->isAlive());

		for (auto row : newCellMap) {
			for (auto cell : row) {
				delete cell;
			}
		}
	}

	SECTION("A dead cell with zero neighbours will not turn to living") {
		// Given there is one cell at coordinates 1,1 that is dead
		cellMap[1][1]->kill();

		// When rules are applied
		std::vector<std::vector<Cell*>> newCellMap = rule->applyRules(cellMap);

		// Then that cell should be dead
		REQUIRE(!newCellMap[1][1]->isAlive());

		for (auto row : newCellMap) {
			for (auto cell : row) {
				delete cell;
			}
		}
	}

	SECTION("A dead cell with eight neighbours will not turn to living") {
		// Given there is one cell at coordinates 1,1 that is dead
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
		std::vector<std::vector<Cell*>> newCellMap = rule->applyRules(cellMap);

		// Then that cell should be dead
		REQUIRE(!newCellMap[1][1]->isAlive());

		for (auto row : newCellMap) {
			for (auto cell : row) {
				delete cell;
			}
		}
	}

	delete rule;

}