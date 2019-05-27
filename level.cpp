#include <ncurses.h>
#include "level.h"

void Level::generate() {
  short numRooms = (rand() % 8) + 1;

  Room r;
  r.posX = 5;
  r.posY = 0;
  r.height = 3;
  r.width = 6;
  rooms.push_back(r);
}

void Level::draw() {
  // just draw what we can see from 0,0 for now lol

  for (auto itr = rooms.begin(); itr != rooms.end(); itr++) {
    Room r = *itr;

    // draw corners first
    move(r.posX, r.posY);
    addch(ACS_ULCORNER);

    move(r.posX + 1 + r.height, r.posY);
    addch(ACS_LLCORNER);

    move(r.posX, r.posY + 1 + r.width);
    addch(ACS_URCORNER);

    move(r.posX + 1 + r.height, r.posY + 1 + r.width);
    addch(ACS_LRCORNER);

    for (short i = r.posX + 1; i <= r.posX + r.height; i++) {
      move(i, r.posY);
      addch(ACS_VLINE);

      move(i, r.posY + 1 + r.width);
      addch(ACS_VLINE);
    }

    for (short i = r.posY + 1; i <= r.posY + r.width; i++) {
      move(r.posX, i);
      addch(ACS_HLINE);

      move(r.posX + 1 + r.height, i);
      addch(ACS_HLINE);
    }
  }

  refresh();
}
