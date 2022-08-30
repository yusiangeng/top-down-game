#include "raylib.h"
#include "raymath.h"
#include "Character.h"

int main()
{
  const int windowWidth = 384;
  const int windowHeight = 384;
  InitWindow(windowWidth, windowHeight, "Colonize the Crustacean");

  Texture2D map = LoadTexture("nature_tileset/OpenWorldMap24x24.png");
  Vector2 mapPos{0.f, 0.f};

  Character knight;
  knight.setScreenPos(windowWidth, windowHeight);

  SetTargetFPS(60);
  while (!WindowShouldClose())
  {
    BeginDrawing();
    ClearBackground(WHITE);

    mapPos = Vector2Scale(knight.getWorldPos(), -1.f);

    // draw map
    DrawTextureEx(map, mapPos, 0.f, 4.f, WHITE);

    knight.tick(GetFrameTime());

    EndDrawing();
  }
  CloseWindow();
}