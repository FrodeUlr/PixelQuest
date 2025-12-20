#ifndef GAME_H
#define GAME_H
#include "config.h"

typedef enum { MAIN_MENU, EXIT, LEVEL_ONE, LEVEL_TWO, GAME_OVER } GameState;
typedef struct Game {
  GameState game_state;
  bool running;
} Game;

void start_game(Game *game, Config *config);

#endif
