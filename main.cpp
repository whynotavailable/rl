#include <ncurses.h>
#include "player.h"
#include "level.h"

int main () {
  // setup start
  initscr();
  noecho();
  cbreak();
  keypad(stdscr, TRUE);
  // setup end

  Level *l = new Level();
  l->generate();
  l->draw();

  refresh();
  getch();
  getch();
  endwin();
  return 0;
}
