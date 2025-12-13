#include "include/game.h"
#include "include/constants.h"
#include "include/player.h"
#include "include/raylib.h"

void start_game(Config *config) {
  const char *title = "Test Game";
  if (config->fullscreen) {
    SetConfigFlags(FLAG_FULLSCREEN_MODE);
    InitWindow(GetScreenWidth(), GetScreenHeight(), title);
  } else {
    InitWindow(config->screenWidth, config->screenHeight, title);
  }
  const int screenWidth = GetScreenWidth();
  const int screenHeight = GetScreenHeight();
  Player player;
  player.position = (Vector2){screenWidth * 0.9f, screenHeight * 0.8f};
  player.speed = START_SPEED;
  player.acceleration = PLAYER_ACCELERATION;
  player.max_speed = MAX_SPEED;
  player.radius = PLAYER_RADIUS;
  player.color = PINK;

  Player player2;
  player2.position = (Vector2){screenWidth * 0.1f, screenHeight * 0.2f};
  player2.speed = START_SPEED;
  player2.acceleration = PLAYER_ACCELERATION;
  player2.max_speed = MAX_SPEED;
  player2.radius = PLAYER_RADIUS;
  player2.color = VIOLET;

  SetTargetFPS(config->targetFPS);
  const Level level = get_level(1);

  while (!WindowShouldClose()) {

    // Player movement
    update_position(&player, false, level, screenWidth, screenHeight);
    update_position(&player2, true, level, screenWidth, screenHeight);

    // Player boundary checking
    two_player_collision(&player, &player2, level, screenWidth, screenHeight);
    check_collision(&player, screenWidth, screenHeight);
    check_collision(&player2, screenWidth, screenHeight);

    BeginDrawing();
    const char *fpsText = TextFormat("FPS: %d", GetFPS());
    const char *screenInfo =
        TextFormat("Screen: %dx%d", screenWidth, screenHeight);
    const char *playerPosText = TextFormat(
        "Player1 Pos: (%.2f, %.2f)", player.position.x, player.position.y);
    const char *player2PosText = TextFormat(
        "Player2 Pos: (%.2f, %.2f)", player2.position.x, player2.position.y);
    ClearBackground(RED);
    render_level(level, screenWidth, screenHeight);
    DrawCircleV(player.position, player.radius, player.color);
    DrawCircleV(player2.position, player2.radius, player2.color);
    DrawText(fpsText, 0, 0, 20, WHITE);
    DrawText(screenInfo, 0, 20, 20, WHITE);
    DrawText(playerPosText, 0, 40, 20, WHITE);
    DrawText(player2PosText, 0, 60, 20, WHITE);
    EndDrawing();
  }
  CloseWindow();
}
