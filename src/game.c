#include "../include/game.h"
#include "../include/constants.h"
#include "../include/player.h"
#include "../include/raylib.h"

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
  Player player_one =
      generate_player("Player1", screenWidth * 0.9f, screenHeight * 0.8f, PINK);
  Player player_two = generate_player("Player2", screenWidth * 0.1f,
                                      screenHeight * 0.2f, VIOLET);
  SetTargetFPS(config->targetFPS);
  const Level level = get_level(1);

  while (!WindowShouldClose()) {

    // Player movement
    update_position(&player_one, false, level, screenWidth, screenHeight);
    update_position(&player_two, true, level, screenWidth, screenHeight);

    // Player boundary checking
    two_player_collision(&player_one, &player_two, level, screenWidth,
                         screenHeight);
    check_collision(&player_one, screenWidth, screenHeight);
    check_collision(&player_two, screenWidth, screenHeight);

    BeginDrawing();
    const char *fpsText = TextFormat("FPS: %d", GetFPS());
    const char *screenInfo =
        TextFormat("Screen: %dx%d", screenWidth, screenHeight);
    const char *playerPosText =
        TextFormat("Player1 Pos: (%.2f, %.2f)", player_one.position.x,
                   player_one.position.y);
    const char *player_two_pos_text =
        TextFormat("Player2 Pos: (%.2f, %.2f)", player_two.position.x,
                   player_two.position.y);
    ClearBackground(RED);
    render_level(level, screenWidth, screenHeight);
    DrawCircleV(player_one.position, player_one.radius, player_one.color);
    DrawCircleV(player_two.position, player_two.radius, player_two.color);
    DrawText(fpsText, 0, 0, 20, WHITE);
    DrawText(screenInfo, 0, 20, 20, WHITE);
    DrawText(playerPosText, 0, 40, 20, WHITE);
    DrawText(player_two_pos_text, 0, 60, 20, WHITE);
    EndDrawing();
  }
  CloseWindow();
}
