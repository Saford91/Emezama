#ifndef WALL_H
#define WALL_H

class Wall {
    bool UP;
  public:
    // Contructors
    Wall();
    Wall(bool u);
    // Getters
    bool isUp();
    // Setters
    void set(bool u);
    void setUp();
    void setDown();
};

#endif
