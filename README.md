Game of Life - Version 1.0
=====================================

General info
------------
"The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970.  
The "game" is a zero-player game, meaning that its evolution is determined by its initial state, requiring no further input.  
One interacts with the Game of Life by creating an initial configuration and observing how it evolves." - [Wikipedia](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life)

Demo
------------
There are some demo files included in this project. See the demo directory for these files and start with parameter -f <filename> to test them out.

How to run "gameoflife"
------------------------
#####Example: gameoflife.exe -er pontus -or daniel -g 100 -s 50x50

* -h help
* -er <even rulename> [default = conway]
* -or <odd rulename> [default = conway]
* -g <generations> [default = 500]
* -s <widthxheight> [default = 80x24]
* -f <filename> [default = random state]

### Rules  
- conway
	* Any live cell with fewer than two live neighbours dies, as if caused by under-population.
	* Any live cell with two or three live neighbours lives on to the next generation.
	* Any live cell with more than three live neighbours dies, as if by over-population.
	* Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
- pontus
	* A living cell with one to seven neighbours will live on
	* A living cell with zero or eight neighbours will die
	* A dead cell with one to seven neighbours will live
	* A dead cell with zero or eight neighbours will continue to be dead
- gustav
	* A dead cell is of color RED
	* If a dead cell has exactly two living neighbours it will revive
	* If a living cell has any living neighbours that are exactly age 2, it will die
	* If a cell has 6 to 8 neighbours that are alive, it will die
	* If a dead cell has one living neighbours that is above age 0, it will revive
- daniel
	* If a living cell is older then age 4 it dies.
	* If a living cell has 4 or more neighbours it dies.
	* If a dead cell has 2 or more neighbours where at least 2 of them is age 1 or more. The dead cell will live.
	* If cell age 1: COLOR YELLOW.
	* If cell age 2: COLOR CYAN.
	* If cell age 3: COLOR BLUE.
	* If cell age 4: COLOR RED.


File format
------------------------
First you need to specify the size of the board by width * height.  
Then you need to specify all the cells that should be alive in the initialize.  
  
An example is presented below  
20x20<br>
10,10  
10,11  
11,40  
10,39  


Developers
-----------
__Pontus Stenlund__  
__Daniel Jennebo__  
__Gustav Olsson__