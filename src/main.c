#include "../include/game.h"

int main(void) {
  Config config;
  load(&config, "config.cfg");
  Game game = {.game_state = MAIN_MENU, .running = true};
  start_game(&game, &config);
  return 0;
}
