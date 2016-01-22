/* File Name:   Wall.cpp
 * Author:      Steven Ford
 * Date:        January 21th, 2015
 * Description: This class represents a wall of a four wall cell of a maze
 *              and is implemented by the Cell class
 */

#include "Wall.h"
#include "debug.h"

// Contructors
Wall::Wall() {
  UP = true;
}
Wall::Wall(bool u) {
  set(u);
}

// Getters
bool Wall::isUp() {
  return UP;
}

// Setters
void Wall::set(bool u) {
  UP = u;
}

void Wall::setUp() {
  UP = true;
}

void Wall::setDown() {
  UP = false;
}
