#include <stdlib.h>
#include <ncurses.h>
#include <time.h>
#include "Emezama.h"
#include "Maze.h"
#include "Window.h"
#include "Player.h"
#include "debug.h"

// Constructors
Emezama::Emezama(){
  // Initialize the screen
  initscr();
  if(has_colors() == false) {
    endwin();
    printf("Your terminal does not support color\n");
    exit(1);
  }
  noecho(); // Don't echo key presses
  cbreak(); // Capture all input
  nodelay(stdscr, true);
  curs_set(0); // Don't show the curser
  // Start color mode and initialize our color pairs
  start_color();
  // COLOR_NORM is used for everything not in the maze
  // COLOR_WALL is used for the maze walls
  // COLOR_PATH is used for the maze path
  init_pair(COLOR_NORM, COLOR_WHITE, COLOR_BLACK);
  init_pair(COLOR_WALL, COLOR_BLACK, COLOR_RED);
  init_pair(COLOR_PATH, COLOR_RED, COLOR_WHITE);

  setScreenWidth(COLS);
  setScreenHeight(LINES);
  #ifdef _DEBUG // Use a constant seed if in debug mode
  gameMaze = new Maze((getScreenWidth() / 2) - 2, (getScreenHeight() / 2) - 2, DEBUG_START_X, DEBUG_START_Y,  DEBUG_SEED);
  #else
  gameMaze = new Maze((getScreenWidth() / 2) - 2, (getScreenHeight() / 2) - 2);
  #endif

  gameMaze->drawMaze();
  gamePlayer = new Player();
  gamePlayer->enter(gameMaze);
}

// Deconstructor
Emezama::~Emezama() {
  if ( gameMaze ) delete gameMaze;
  if ( gamePlayer ) delete gamePlayer;
}

// Private Setters
void Emezama::setScreenWidth(int w) {
  screen.width = w;
}
void Emezama::setScreenHeight(int h) {
  screen.height = h;
}

// Getters
int Emezama::getScreenWidth() {
  return screen.width;
}
int Emezama::getScreenHeight() {
  return screen.height;
}

// Other Methods
void Emezama::resize() { // Re generate the maze
  setScreenWidth(COLS);
  setScreenHeight(LINES);

  if ( gameMaze ) delete gameMaze;

  clear();

  #ifdef _DEBUG // Use a constant seed if in debug mode
  gameMaze = new Maze((getScreenWidth() / 2) - 2, (getScreenHeight() / 2) - 2, DEBUG_START_X, DEBUG_START_Y,  DEBUG_SEED);
  #else
  gameMaze = new Maze((getScreenWidth() / 2) - 2, (getScreenHeight() / 2) - 2);
  #endif

  gameMaze->drawMaze();
  gamePlayer->enter(gameMaze);
  gamePlayer->draw(gameMaze);  
}

// This method displays the title screen
void Emezama::title() {
  Window* title = new Window();
  //gameMaze->drawMaze();
  //title->clear();
  title->draw();
  title->print("Hello!!\nWelcome to Emezama!!\n\n A simple maze game.");
  getch();
  delete title;
}

// This is the main game loop, it reads input and moves the player
bool Emezama::run(unsigned int speed) {
  gamePlayer->draw(gameMaze);
  int key = getch();
  switch (key) {
    case MY_KEY_UP:
      gamePlayer->goNorth(gameMaze);
      break;
    case MY_KEY_RIGHT:
      gamePlayer->goEast(gameMaze);
      break;
    case MY_KEY_DOWN:
      gamePlayer->goSouth(gameMaze);
      break;
    case MY_KEY_LEFT:
      gamePlayer->goWest(gameMaze);
      break;
    case KEY_RESIZE:
      resize();
      break;
    case KEY_BREAK:
      return false;
      break;
  }
  #ifdef _DEBUG
  mvprintw(1, 0, "Key: %i", key);
  #endif
  refresh();
  return true;  
}

void Emezama::quit() {
  endwin();
}

