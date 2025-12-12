#include "include/levels.h"
#include "include/raylib.h"
#include <string.h>

const char **level_one() {
  static const char *level_data[] = {
      "####################",
      "#..............@...#",
      "#..####............#",
      "#..#..#............#",
      "#..#..#....####....#",
      "#..####....#..#....#",
      "#..........#..#....#",
      "#..........####....#",
      "#..................#",
      "####################",
      NULL // <-- Add this to mark the end!
  };
  return level_data;
}

void render_level(const char **level_data, int level_width, int level_height,
                  int screen_width, int screen_height) {
  int tile_width = screen_width / level_width;
  int tile_height = screen_height / level_height;
  for (int y = 0; y < level_height; y++) {
    for (int x = 0; x < level_width; x++) {
      char tile = level_data[y][x];
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
