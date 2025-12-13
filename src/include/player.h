#include "raylib.h"

typedef struct Player {
  Vector2 position;
  float speed;
  float acceleration;
  float max_speed;
  float radius;
  Color color;
} Player;

void update_position(Player *player, bool TwoPlayer, const char **level,
                     int screenWidth, int screenHeight);

void check_collision(Player *player, int screenWidth, int screenHeight);
void two_player_collision(Player *player1, Player *player2, const char **level,
                          int screenWidth, int screenHeight);
bool is_blocked(char tile);
bool collides_with_level(float x, float y, float radius, const char **level,
                         int screenWidth, int screenHeight);
