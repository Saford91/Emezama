#include <stdlib.h>
#include <ncurses.h>
#include <signal.h>
#include "Emezama.h"
#include "debug.h"

Emezama* game;

int main(int argc, char *argv[])
{	
  game = new Emezama();

  //myEmezama->title();

  while (game->run(1)) {};

  game->quit();

  delete game;

  return 0;

}
