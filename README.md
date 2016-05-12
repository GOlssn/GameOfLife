Game of Life - README.md Version 1.0
=====================================

General info
------------
Conway's Game of Life is a zero player game with cellular automaton.  
It uses arguments on startup and there after the game it self evolves from generation to generation. This without further user input. 
 
Conway's rules are:   

* Any live cell with fewer than two live neighbours dies, as if caused by under-population.
* Any live cell with two or three live neighbours lives on to the next generation.
* Any live cell with more than three live neighbours dies, as if by over-population.
* Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.

How to run "gameoflife"
------------------------
### Example: gameoflife.exe -er pontus -or daniel -g 100 -s 50x50

* __-h help__
* __-er <even rulename>[default = conway]__
* __-or <odd rulename>[default = conway]__
* __-g <generations>[default = 500]__
* __-s <widthxheight>[default = 80x24]__
* __-f <filename for initial state>[default = random state]__

Different rulenames to use are: pontus, gustav and daniel.


Developers
-----------
__Pontus Stenlund__  
__Daniel Jennebo__  
__Gustav Olsson__
