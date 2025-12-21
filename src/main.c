#include "../include/game.h"
#include <stdlib.h>

int main(void) {
  Config *config = malloc(sizeof(Config));
  load(config, "config.cfg");
  Game *game = malloc(sizeof(Game));
  game->game_state = MAIN_MENU;
  game->running = true;
  start_game(game, config);

  if (game != NULL) {
    free(game);
  }
  if (config != NULL) {
    free(config);
  }
  return 0;
}
