#ifndef LEVELS_H
#define LEVELS_H
#include "raylib.h"
#include "textures.h"
#include <stdbool.h>

typedef struct Level {
  int number;
  int columns;
  int rows;
  int offsetX;
  int offsetY;
  int tileSize;
  bool firstFrame;
  const char **data;
  bool completed;
  TextureDef wallTexture;
  TextureDef groundTexture;
  TextureDef targetTexture;
  TextureDef houseTexture;
  TextureDef waterTexture;
} Level;

typedef enum { WALL, TARGET, WATER, GROUND, HOUSE, PLAYER } TILE_TYPE;

void render_level(Level *level);
void set_offset(Level *level);
void set_level(Level *level, int number);

#endif
