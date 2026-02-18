#ifndef ERROR_H
#include "game.h"
#define ERROR_H

#define ERROR_CREATE_PLAYERS 1
#define ERROR_ALLOC_PLAYER_ARRAY 2
#define ERROR_ALLOC_PLAYER 3
#define ERROR_ALLOC_CAMERA 4
#define ERROR_ALLOC_CAMERA_ARRAY 5
#define ERROR_ALLOC_LEVEL 6

void HANDLE_ERROR(Game *game, int error_code);

#endif
