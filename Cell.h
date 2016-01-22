#ifndef CELL_H
#define CELL_H

#include "Wall.h"

class Cell {
    Wall* northWall;
    Wall* eastWall;
    Wall* southWall;
    Wall* westWall;
    bool beenVisited;
  public:
    // Constructors
    Cell();
    Cell(Cell* oldCell);

    // Deconstructor
    ~Cell();

    // Getters
    bool north();
    bool east();
    bool south();
    bool west();
    bool visited();

    // Setters
    void setNorth(bool u);
    void setEast(bool u);
    void setSouth(bool u);
    void setWest(bool u);
    void setVisited();
    void setVisited(bool v);
};

#endif
