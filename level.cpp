#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include "level.h"

void Level::generate() {
  rooms.clear();
  clear();
  short numRooms = (rand() % 12) + 5;

  int y;
  int x;
  getmaxyx(stdscr, y, x);

  for (short i = 0; i < numRooms; i++) {
    Room room;
    room.height = (rand() % 8) + 2;
    room.width = (rand() % 8) + 2;
    room.posX = (rand() % x);
    room.posY = (rand() % y);
    rooms.push_back(room);
  }
}



void Level::draw() {
  // just draw what we can see from 0,0 for now lol

  int y;
  int x;
  getmaxyx(stdscr, y, x);

  for (auto itr = rooms.begin(); itr != rooms.end(); itr++) {
    Room r = *itr;

    // if out of bounds, don't draw

    if (r.posX + r.width >= (x - 1) || r.posY + r.height >= (y - 1)) {
      continue;
    }

    // draw corners first
    move(r.posY, r.posX);
    addch(ACS_ULCORNER);

    move(r.posY, r.posX + 1 + r.width);
    addch(ACS_URCORNER);

    move(r.posY + 1 + r.height, r.posX);
    addch(ACS_LLCORNER);

    move(r.posY + 1 + r.height, r.posX + 1 + r.width);
    addch(ACS_LRCORNER);

    for (short i = r.posX + 1; i <= r.posX + r.width; i++) {
      move(r.posY, i);
      addch(ACS_HLINE);

      move(r.posY + 1 + r.height, i);
      addch(ACS_HLINE);
    }

    for (short i = r.posY + 1; i <= r.posY + r.height; i++) {
      move(i, r.posX);
      addch(ACS_VLINE);

      move(i, r.posX + 1 + r.width);
      addch(ACS_VLINE);
    }
  }

  refresh();
}
