typedef struct Level {
  int width;
  int height;
  const char **data;
} Level;

void render_level(Level level, int screen_width, int screen_height);
Level level_one();
Level level_two();
