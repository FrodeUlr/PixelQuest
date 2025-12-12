#include "raylib.h"

typedef struct Player {
  Vector2 position;
  float speed;
  float radius;
  Color color;
} Player;

void PlayerUpdatePosition(Player *player, bool TwoPlayer, const char **level,
                          int screenWidth, int screenHeight);

void PlayerCheckCollision(Player *player, int screenWidth, int screenHeight);
void TwoPlayerCollision(Player *player1, Player *player2);
bool is_blocked(char tile);
