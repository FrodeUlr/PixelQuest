#ifndef GAME_H
#define GAME_H
#include "config.h"
#include "player.h"

typedef enum { MAIN_MENU, EXIT, LEVEL_ONE, LEVEL_TWO, GAME_OVER } GameState;
typedef struct Game {
  GameState game_state;
  bool running;
} Game;

void start_game(Game *game, Config *config);
void draw_ui(Player *players[], int player_count, int screen_width,
             int screen_height);

#endif
