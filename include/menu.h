#ifndef MENU_H
#define MENU_H
#include "../include/game.h"
#include "../include/player.h"
#include "../include/raylib.h"
#include <stdbool.h>

typedef enum FocusField {
  PLAYER1_NAME,
  PLAYER2_NAME,
  START_BUTTON,
  EXIT_BUTTON,
  FOCUS_FIELD_COUNT
} FocusField;

typedef struct Menu {
  char p1Name[16];
  char p2Name[16];
  int p1NameLen;
  int p2NameLen;
  FocusField focusField;
  int screenWidth;
  int screenHeight;
  Color p1Color;
  Color p2Color;
  Color exitColor;
  Color startColor;
} Menu;

void new_menu(Menu *menu);
void draw_main_menu(Menu *menu, Game *game);
void check_inputs(Menu *menu, Game *game, Level *level);

#endif // !DEBUG
