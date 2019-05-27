#pragma once

#include <vector>

struct Room
{
  short posX;
  short posY;
  
  // these are how much space a room has not the actual size
  short height;
  short width;
};

class Level
{
  std::vector<Room> rooms;

public:
  void generate();
  // draw the map on the window
  void draw();
};
