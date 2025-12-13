#include "include/levels.h"
#include "include/raylib.h"
#include <string.h>

Level level_one() {
  Level level;
  static const char *level_data[] = {
      "####################", "#..............@...#", "#..####............#",
      "#..#..#............#", "#..#..#....####....#", "#..####....#..#....#",
      "#..........#..#....#", "#..........####....#", "#..................#",
      "####################",
  };
  level.data = level_data;
  level.width = strlen(level_data[0]);
  level.height = sizeof(level_data) / sizeof(level_data[0]);
  return level;
}

Level level_two() {
  Level level;
  static const char *level_data[] = {
      "####################", "#...#..............#", "#...#..............#",
      "#...####@@.........#", "#........@.....#...#", "#........@.....#...#",
      "#........@.....#...#", "#..............#...#", "#..............#...#",
      "####################",
  };
  level.data = level_data;
  level.width = strlen(level_data[0]);
  level.height = sizeof(level_data) / sizeof(level_data[0]);
  return level;
}
void render_level(Level level, int screen_width, int screen_height) {
  int tile_width = screen_width / level.width;
  int tile_height = screen_height / level.height;
  for (int y = 0; y < level.height; y++) {
    for (int x = 0; x < level.width; x++) {
      char tile = level.data[y][x];
      Color color;
      switch (tile) {
      case '#':
        color = DARKGRAY;
        break;
      case '.':
        color = LIGHTGRAY;
        break;
      case '@':
        color = BLUE;
        break;
      default:
        color = BLACK;
        break;
      }
      DrawRectangle(x * tile_width, y * tile_height, tile_width, tile_height,
                    color);
    }
  }
}
