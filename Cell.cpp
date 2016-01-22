// Class to represent one cell in a maze

#include "Cell.h"
#include "debug.h"

// Constructors
Cell::Cell() {
  northWall = new Wall(true);
  eastWall  = new Wall(true);
  southWall = new Wall(true);
  westWall  = new Wall(true);
  beenVisited = false;
}
Cell::Cell(Cell* oldCell) {
  northWall = new Wall(oldCell->north());
  eastWall  = new Wall(oldCell->east());
  southWall = new Wall(oldCell->south());
  westWall  = new Wall(oldCell->west());
  beenVisited = oldCell->visited();
}

// Deconstructor
Cell::~Cell() {
  if ( northWall ) delete northWall;
  if ( eastWall  ) delete eastWall;
  if ( southWall ) delete southWall;
  if ( westWall  ) delete westWall;
}

// Getters
bool Cell::north() {
  return northWall->isUp();
}
bool Cell::east() {
  return eastWall->isUp();
}
bool Cell::south() {
  return southWall->isUp();
}
bool Cell::west() {
  return westWall->isUp();
}
bool Cell::visited() {
  return beenVisited;
}

// Setters
void Cell::setNorth(bool u) {
  northWall->set(u);
}
void Cell::setEast(bool u) {
  eastWall->set(u);
}
void Cell::setSouth(bool u) {
  southWall->set(u);
}
void Cell::setWest(bool u) {
  westWall->set(u);
}
void Cell::setVisited() {
  setVisited(true);
}
void Cell::setVisited(bool v) {
  beenVisited = v;
}
