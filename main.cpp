#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
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
  int ch = 0;
  do
  {
    ch = getch();
    if (ch == 'r') {
      l->generate();
      l->draw();
    }
  } while (ch != 'q');
  endwin();
  return 0;
}
