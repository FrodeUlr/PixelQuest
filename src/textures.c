#include "../include/textures.h"

TextureDef SetTextureDef(const char *name, int startX, int endX, int startY,
                         int endY, char *texturePath) {
  TextureDef tex_def;
  tex_def.name = name;
  tex_def.startX = startX;
  tex_def.endX = endX;
  tex_def.startY = startY;
  tex_def.endY = endY;
  tex_def.texture = LoadTexture(texturePath);
  return tex_def;
}
