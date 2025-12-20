#ifndef MENU_H
#define MENU_H
#include "../include/game.h"
#include "../include/player.h"
#include "../include/raylib.h"
#include <stdbool.h>

typedef struct Menu {
  char player1Name[32];
  char player2Name[32];
  int player1NameLen;
  int player2NameLen;
  bool editingPlayer1;
  int screenWidth;
  int screenHeight;
  Color player1Color;
  Color player2Color;
} Menu;

void new_menu(Menu *menu);
void draw_main_menu(Menu *menu, Game *game);
void check_inputs(Menu *menu, Game *game, Level *level);

#endif // !DEBUG
