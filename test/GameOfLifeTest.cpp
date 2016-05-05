#include "catch.hpp"
#include "Cell.h"

TEST_CASE("Cell class test") {
	SECTION("Check isAlive function TRUE") {
		Cell cell(0,0,true);
		REQUIRE(cell.isAlive() == true);
	}
	SECTION("Check isAliva function FALSE") {
		Cell cell(0, 0, false);
		REQUIRE(cell.isAlive() == false);
	}
}