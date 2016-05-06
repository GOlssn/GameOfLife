#include <catch.hpp>
#include "Cell.h"

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
}