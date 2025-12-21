#include "../include/menu.h"

void new_menu(Menu *menu) {
  menu->p1Name[0] = '\0';
  menu->p2Name[0] = '\0';
  menu->p1NameLen = 0;
  menu->p2NameLen = 0;
  menu->focusField = PLAYER1_NAME;
  menu->screenWidth = GetScreenWidth();
  menu->screenHeight = GetScreenHeight();
  menu->p1Color = LIME;
  menu->p2Color = BLACK;
  menu->exitColor = DARKGRAY;
  menu->startColor = DARKGRAY;
}

void draw_player_name_input(Rectangle rec, const char *label,
                            const char *playerName, Color focusColor,
                            Color textColor) {
  DrawText(label, rec.x + 20, rec.y - 20, 20, focusColor);
  DrawRectangleLinesEx(rec, 8.0f, focusColor);
  DrawRectangle(rec.x + 2, rec.y + 2, rec.width - 4, rec.height - 4, LIGHTGRAY);
  DrawText(playerName, rec.x + 10, rec.y + 10, 20, textColor);
}

bool handle_menu_button(Rectangle rect, Color *color, Color hoverColor,
                        Color normalColor, bool resetColor) {
  Vector2 mouse = GetMousePosition();

  if (CheckCollisionPointRec(mouse, rect)) {
    *color = hoverColor;
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
      return true;
    }
  } else if (resetColor) {
    *color = normalColor;
  }
  return false;
}

void draw_main_menu(Menu *menu, Game *game) {
  int halfScreenWidth = menu->screenWidth / 2;
  int halfScreenHeight = menu->screenHeight / 2;
  //
  // Player 1
  //
  Rectangle rec_p1 = {.height = 44,
                      .width = 204,
                      .x = halfScreenWidth - 102,
                      .y = halfScreenHeight - 172};
  draw_player_name_input(rec_p1, "Player 1 name:", menu->p1Name, menu->p1Color,
                         BLACK);
  //
  // Player 2
  //
  Rectangle rec_p2 = {.height = 44,
                      .width = 204,
                      .x = halfScreenWidth - 102,
                      .y = halfScreenHeight - 102};
  draw_player_name_input(rec_p2, "Player 2 name:", menu->p2Name, menu->p2Color,
                         BLACK);
  //
  // Buttons
  //
  Rectangle rec_start = {.height = 40,
                         .width = 200,
                         .x = halfScreenWidth - 100,
                         .y = halfScreenHeight};
  DrawRectanglePro(rec_start, (Vector2){0, 0}, 0.0f, menu->startColor);
  DrawText("START", halfScreenWidth - 37, halfScreenHeight + 10, 20, WHITE);

  Rectangle rec_exit = {.height = 40,
                        .width = 200,
                        .x = halfScreenWidth - 100,
                        .y = halfScreenHeight + 60};
  DrawRectanglePro(rec_exit, (Vector2){0, 0}, 0.0f, menu->exitColor);
  DrawText("EXIT", halfScreenWidth - 28, halfScreenHeight + 70, 20, WHITE);

  //
  // Check collisions
  //
  if (handle_menu_button(rec_p1, &menu->p1Color, LIME, BLACK,
                         menu->focusField != PLAYER1_NAME)) {
    menu->focusField = PLAYER1_NAME;
  }
  if (handle_menu_button(rec_p2, &menu->p2Color, LIME, BLACK,
                         menu->focusField != PLAYER2_NAME)) {
    menu->focusField = PLAYER2_NAME;
  }
  if (handle_menu_button(rec_start, &menu->startColor, LIME, DARKGRAY,
                         menu->focusField != START_BUTTON)) {
    game->gameState = LEVEL_ONE;
  }
  if (handle_menu_button(rec_exit, &menu->exitColor, RED, DARKGRAY,
                         menu->focusField != EXIT_BUTTON)) {
    game->gameState = EXIT;
  }
  //
  // Check inputs
  //
  if (IsKeyPressed(KEY_TAB)) {
    menu->focusField = (menu->focusField + 1) % FOCUS_FIELD_COUNT;
    if (menu->focusField == PLAYER1_NAME) {
      menu->p1Color = LIME;
      menu->p2Color = BLACK;
    } else if (menu->focusField == PLAYER2_NAME) {
      menu->p1Color = BLACK;
      menu->p2Color = LIME;
    } else if (menu->focusField == START_BUTTON) {
      menu->startColor = LIME;
    } else if (menu->focusField == EXIT_BUTTON) {
      menu->exitColor = RED;
    }
  }
  int key = GetCharPressed();
  while (key > 0) {
    if (menu->focusField == PLAYER1_NAME && menu->p1NameLen < 15) {
      menu->p1Name[menu->p1NameLen++] = (char)key;
      menu->p1Name[menu->p1NameLen] = '\0';
    } else if (menu->focusField == PLAYER2_NAME && menu->p2NameLen < 15) {
      menu->p2Name[menu->p2NameLen++] = (char)key;
      menu->p2Name[menu->p2NameLen] = '\0';
    }
    key = GetCharPressed();
  }
  if (IsKeyPressed(KEY_BACKSPACE)) {
    if (menu->focusField == PLAYER1_NAME && menu->p1NameLen > 0)
      menu->p1Name[--menu->p1NameLen] = '\0';
    else if (menu->focusField == PLAYER2_NAME && menu->p2NameLen > 0)
      menu->p2Name[--menu->p2NameLen] = '\0';
  }
  if (IsKeyPressed(KEY_ENTER)) {
    if (menu->focusField == START_BUTTON) {
      game->gameState = LEVEL_ONE;
    } else if (menu->focusField == EXIT_BUTTON) {
      game->gameState = EXIT;
    }
  }
}

void check_inputs(Menu *menu, Game *game, Level *level) {
  if (IsKeyPressed(KEY_ESCAPE)) {
    game->gameState = MAIN_MENU;
    level->firstFrame = true;
  }
}
