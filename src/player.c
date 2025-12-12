#include "include/player.h"
#include "include/raylib.h"
#include <math.h>

void PlayerUpdatePosition(Player *player, bool TwoPlayer, const char **level,
                          int screenWidth, int screenHeight) {
  int tile_rows = 10;
  int tile_cols = 20;
  int tile_w = screenWidth / tile_cols;
  int tile_h = screenHeight / tile_rows;

  float new_x = player->position.x;
  float new_y = player->position.y;
  float radius = player->radius;

  if ((IsKeyDown(KEY_RIGHT) && !TwoPlayer) || (IsKeyDown(KEY_D) && TwoPlayer))
    new_x += player->speed * GetFrameTime();
  if ((IsKeyDown(KEY_LEFT) && !TwoPlayer) || (IsKeyDown(KEY_A) && TwoPlayer))
    new_x -= player->speed * GetFrameTime();
  if ((IsKeyDown(KEY_UP) && !TwoPlayer) || (IsKeyDown(KEY_W) && TwoPlayer))
    new_y -= player->speed * GetFrameTime();
  if ((IsKeyDown(KEY_DOWN) && !TwoPlayer) || (IsKeyDown(KEY_S) && TwoPlayer))
    new_y += player->speed * GetFrameTime();

  int left_tile = (int)((new_x - radius) / tile_w);
  int right_tile = (int)((new_x + radius) / tile_w);
  int top_tile = (int)((player->position.y - radius) / tile_h);
  int bottom_tile = (int)((player->position.y + radius) / tile_h);

  if (!is_blocked(level[top_tile][left_tile]) &&
      !is_blocked(level[bottom_tile][left_tile]) &&
      !is_blocked(level[top_tile][right_tile]) &&
      !is_blocked(level[bottom_tile][right_tile])) {
    player->position.x = new_x;
  }

  // Then try moving in Y direction
  left_tile = (int)((player->position.x - radius) / tile_w);
  right_tile = (int)((player->position.x + radius) / tile_w);
  top_tile = (int)((new_y - radius) / tile_h);
  bottom_tile = (int)((new_y + radius) / tile_h);

  if (!is_blocked(level[top_tile][left_tile]) &&
      !is_blocked(level[bottom_tile][left_tile]) &&
      !is_blocked(level[top_tile][right_tile]) &&
      !is_blocked(level[bottom_tile][right_tile])) {
    player->position.y = new_y;
  }
}

void PlayerCheckCollision(Player *player, int screenWidth, int screenHeight) {
  if (player->position.x < player->radius)
    player->position.x = player->radius;
  if (player->position.x > screenWidth - player->radius)
    player->position.x = screenWidth - player->radius;
  if (player->position.y < player->radius)
    player->position.y = player->radius;
  if (player->position.y > screenHeight - player->radius)
    player->position.y = screenHeight - player->radius;
}

void TwoPlayerCollision(Player *player1, Player *player2) {
  float dx = player1->position.x - player2->position.x;
  float dy = player1->position.y - player2->position.y;
  float distance = sqrtf(dx * dx + dy * dy);
  float minDistance = player1->radius + player2->radius;

  if (distance < minDistance) {
    float overlap = 0.5f * (minDistance - distance);
    float nx = dx / distance;
    float ny = dy / distance;

    player1->position.x += nx * overlap;
    player1->position.y += ny * overlap;
    player2->position.x -= nx * overlap;
    player2->position.y -= ny * overlap;
  }
}

bool is_blocked(char c) { return c == '#' || c == '@'; }
