#include <ncurses.h>
#include "player.h"
#include "level.h"

int main () {
  // setup start
  initscr();
  noecho();
  cbreak();
  keypad(stdscr, TRUE);
  srand(time(NULL));
  // setup end

  printw("Map Generation Test ('q') to quit");

  Level *l = new Level();
  l->generate();
  l->draw();

  refresh();
  move(0,0);
  while(getch() != 'q') {}
  endwin();
  return 0;
}
