#include "raylib.h"
#include "raymath.h"
#include "Character.h"

int main()
{
  const int WINDOW_WIDTH = 384;
  const int WINDOW_HEIGHT = 384;
  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Colonize the Crustacean");

  Texture2D MAP = LoadTexture("nature_tileset/OpenWorldMap24x24.png");
  Vector2 mapPos{0.f, 0.f};
  const float MAP_SCALE = 4.f;

  Character knight;
  knight.setScreenPos(WINDOW_WIDTH, WINDOW_HEIGHT);

  SetTargetFPS(60);
  while (!WindowShouldClose())
  {
    BeginDrawing();
    ClearBackground(WHITE);

    mapPos = Vector2Scale(knight.getWorldPos(), -1.f);

    DrawTextureEx(MAP, mapPos, 0.f, MAP_SCALE, WHITE);

    knight.tick(GetFrameTime());
    // check map bounds
    if (knight.getWorldPos().x < 0 ||
        knight.getWorldPos().y < 0 ||
        knight.getWorldPos().x + WINDOW_WIDTH > MAP.width * MAP_SCALE ||
        knight.getWorldPos().y + WINDOW_HEIGHT > MAP.height * MAP_SCALE)
    {
      knight.undoMovement();
    }

    EndDrawing();
  }
  CloseWindow();
}