#include <catch.hpp>
#include "Cell.h"
#include "GameEngine.h"

TEST_CASE("Cell class test") {
	SECTION("Check isAlive function TRUE") {
		Cell cell(0,0,true);
		REQUIRE(cell.isAlive() == true);
	}
	SECTION("Check isAlive function FALSE") {
		Cell cell(0, 0, false);
		REQUIRE(cell.isAlive() == false);
	}

	SECTION("getX()") {
		Cell cell(1, 1, true);
		REQUIRE(cell.getX() == 1); 
	}

	SECTION("getY()") {
		Cell cell(1, 1, true);
		REQUIRE(cell.getY() == 1);
	}

	SECTION("cell.kill() turn alive cell to false") {
		Cell cell(1, 1, true);
		cell.kill();
		REQUIRE(cell.isAlive() == false);
	}

	SECTION("cell.revive() turn dead cell to alive") {
		Cell cell(0, 0, false);
		cell.revive();
		REQUIRE(cell.isAlive() == true);
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
	
}