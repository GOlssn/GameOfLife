Game of Life - Version 1.0
=====================================

General info
------------
The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970.  
The "game" is a zero-player game, meaning that its evolution is determined by its initial state, requiring no further input.  
One interacts with the Game of Life by creating an initial configuration and observing how it evolves.  

 
Conway's rules are:   

* Any live cell with fewer than two live neighbours dies, as if caused by under-population.
* Any live cell with two or three live neighbours lives on to the next generation.
* Any live cell with more than three live neighbours dies, as if by over-population.
* Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.

Wikipedia [link](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life)

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

File format example:  
20x20  
10,10  
10,11  
11,40  
10,39  


Developers
-----------
__Pontus Stenlund__  
__Daniel Jennebo__  
__Gustav Olsson__
