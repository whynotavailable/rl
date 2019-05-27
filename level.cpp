#include <ncurses.h>
#include "level.h"

void Level::generate() {
  Room r;
  rooms.push_back(r);
}

void Level::draw() {
  // just draw what we can see from 0,0

  addch(ACS_ULCORNER);
  move(0, 1);
  addch(ACS_HLINE);
}
