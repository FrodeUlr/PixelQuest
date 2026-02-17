#include "player_factory.h"
#include "error.h"
#include "level.h"
#include "menu.h"
#include "player.h"
#include <stdio.h>
#include <stdlib.h>

void free_players(Game *game) {
  if (game->players != NULL && game->playerCount > 0) {
    for (size_t i = 0; i < game->playerCount; i++) {
      if (game->players[i] != NULL) {
        game->players[i] = NULL;
      }
      if (game->level->cameras != NULL && game->level->cameras[i] != NULL) {
        free(game->level->cameras[i]);
      }
    }
    free(game->players);
    game->players = NULL;
    free(game->level->cameras);
    game->level->cameras = NULL;
    game->playerCount = 0;
    game->firstPlayerSet = false;
  }
}

void set_p_count(Game *game, struct Menu *menu) {
  for (int i = 0; i < 2; i++) {
    if (menu->players[i]->nameLen != 0) {
      if (i == 0) {
        game->firstPlayerSet = true;
      }
      game->playerCount += 1;
    }
  }
}

int alloc_gp_mem(Game *game) {
  if (game->players == NULL) {
    game->players = malloc(sizeof(Player *) * game->playerCount);
    if (game->players == NULL) {
      printf("Error allocating memory for players\n");
      return ERROR_ALLOC_PLAYER_ARRAY;
    }
  }
  return 0;
}

int initialize_players(Game *game, struct Menu *menu) {
  free_players(game);
  set_p_count(game, menu);
  alloc_gp_mem(game);
  for (int i = 0; i < game->playerCount; i++) {
    printf("Generating player %d...\n", i + 1);
    int idx_player = game->firstPlayerSet ? i : i + 1;
    game->players[i] = malloc(sizeof(Player));
    if (game->players[i] == NULL) {
      printf("Error allocating memory for player %d\n", i + 1);
      return ERROR_ALLOC_PLAYER;
    }
    generate_player(game->players[i], menu->players[idx_player]->name,
                    idx_player, GetScreenWidth() * 0.9f,
                    GetScreenHeight() * 0.7f,
                    idx_player == 0 ? RAYWHITE : PINK);
  }
  return 0;
}

int create_players(Game *game, struct Menu *menu) {
  int err = initialize_players(game, menu);
  if (err != 0) {
    printf("Error initializing players\n");
    free_players(game);
  }
  return err;
}
