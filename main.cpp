#include <ncurses.h>
#include "player.h"

int main () {
  // setup start
  initscr();
  noecho();
  cbreak();
  keypad(stdscr, TRUE);
  // setup end

  Player *p = new Player();
  p->move(1, 0);
  printw("Hello World, lol");
  refresh();
  getch();
  getch();
  endwin();
  return 0;
}
