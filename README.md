# Emezama
A simple maze game I've been playing around with. This program utiilized the NCurses library to draw a maze on a terminal screen. The maze size is determined by the window size. The maze is automatically regenerated if the window is resized. This program consists of 6 c++ source files and 5 classes:

Cell.cpp
Maze.cpp
Player.cpp
Emezama.cpp
Window.cpp
main.cpp 

Cell:
This class represents one cell of the a maze. This class consists of five boolean values: four that represent the four walls of the cell, and one to keep track of whether or not the cell has been visited during maze generation.

Maze:
This class generates and holds the maze. The maze that is generated has dimension equal to ((W / 2) - 2),((H / 2) - 2) of the W,H of the console. Each maze cell is drawn as 3x3 console characters that overlap with the surrounding cells.

Player:
This class represents the player traversing the maze, it holds their name, the symbol representing them in the maze, and their location in the maze.

Emezama:
This class is the main class for the game, it initialized curses mode, instantiates the Maze object, and provides the main loop for the input to move the player class through the maze.

Window:
This class is currently not used. It is intended to be create windows using NCurses and allow the printing of text to them.

# How to Build
Just 'make' it.

The makefile also specifies a debug version that is made with 'make debug'.
