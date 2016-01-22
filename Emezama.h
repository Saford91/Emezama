#ifndef MAZE_GAME_H
#define MAZE_GAME_H

#include "Maze.h"
#include "Player.h"

#define MY_KEY_UP    65
#define MY_KEY_DOWN  66
#define MY_KEY_LEFT  68
#define MY_KEY_RIGHT 67

class Emezama {
    // Stores the size of the screen
    struct {
      int width;
      int height; 
    } screen;
    Maze* gameMaze;
    Player* gamePlayer;

    // Private setters
    void setScreenWidth(int w);
    void setScreenHeight(int h);
  public:
    // Constructors
    Emezama();
    // Deconstructor
    ~Emezama();
    
    // Getters
    int getScreenWidth();
    int getScreenHeight();

    // Other functions
    void resize();
    void title();
    bool run(unsigned int speed);
    void quit();
};

#endif
