#ifndef CONFIG_H
#define CONFIG_H
#include <stdbool.h>

typedef struct Config {
  int screenWidth;
  int screenHeight;
  int targetFPS;
  bool fullscreen;
} Config;

void load(Config *config, const char *filename);
void set_default(Config *config);

#endif
