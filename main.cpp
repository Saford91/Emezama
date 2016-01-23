#include <stdlib.h>
#include <ncurses.h>
#include <signal.h>
#include "Emezama.h"
#include "debug.h"

Emezama* myEmezama;

int main(int argc, char *argv[])
{	
  myEmezama = new Emezama();

  //myEmezama->title();

  while (myEmezama->run(1)) {};

  myEmezama->quit();

  delete myEmezama;

  return 0;

}
