#ifndef TEXTURES_H
#define TEXTURES_H
#include "raylib.h"

typedef struct TextureDef {
  const char *name;
  int startX;
  int endX;
  int startY;
  int endY;
  Texture2D texture;
} TextureDef;

TextureDef SetTextureDef(const char *name, int startX, int endX, int startY,
                         int endY, char *texturePath);

#endif // !DEBUG
