#include "error.h"
#include "game.h"
#include <stdio.h>

void HANDLE_ERROR(Game *game, int error_code) {
  switch (error_code) {
  case ERROR_CREATE_PLAYERS:
    printf("Error creating players, returning to main menu\n");
    game->gameState = MAIN_MENU;
    break;
  case ERROR_ALLOC_PLAYER:
    printf("Error allocating memory for a player, returning to main menu\n");
    game->gameState = MAIN_MENU;
    break;
  case ERROR_ALLOC_PLAYER_ARRAY:
    printf(
        "Error allocating memory for player array, returning to main menu\n");
    game->gameState = MAIN_MENU;
    break;
  case ERROR_ALLOC_CAMERA:
    printf("Error allocating memory for a camera, returning to main menu\n");
    game->gameState = MAIN_MENU;
    break;
  case ERROR_ALLOC_CAMERA_ARRAY:
    printf(
        "Error allocating memory for camera array, returning to main menu\n");
    game->gameState = MAIN_MENU;
    break;
  case ERROR_ALLOC_LEVEL:
    printf("Error allocating memory for level, returning to main menu\n");
    game->gameState = MAIN_MENU;
    break;
  case 0:
    break;
  }
}
