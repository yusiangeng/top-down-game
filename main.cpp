#include "raylib.h"
#include "raymath.h"
#include "Character.h"
#include "Prop.h"

int main()
{
  const int WINDOW_WIDTH = 384;
  const int WINDOW_HEIGHT = 384;
  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Colonize the Crustacean");

  Texture2D map = LoadTexture("nature_tileset/OpenWorldMap24x24.png");
  Vector2 mapPos{0.f, 0.f};
  const float MAP_SCALE = 4.f;

  Character knight(WINDOW_WIDTH, WINDOW_HEIGHT);

  Prop props[2]{
      Prop{Vector2{600.f, 300.f}, LoadTexture("nature_tileset/Rock.png")},
      Prop{Vector2{400.f, 500.f}, LoadTexture("nature_tileset/Log.png")}};

  SetTargetFPS(60);
  while (!WindowShouldClose())
  {
    BeginDrawing();
    ClearBackground(WHITE);

    mapPos = Vector2Scale(knight.getWorldPos(), -1.f);

    // draw map
    DrawTextureEx(map, mapPos, 0.f, MAP_SCALE, WHITE);

    // draw props
    for (auto prop : props)
    {
      prop.Render(knight.getWorldPos());
    }

    knight.tick(GetFrameTime());
    // check map bounds
    if (knight.getWorldPos().x < 0 ||
        knight.getWorldPos().y < 0 ||
        knight.getWorldPos().x + WINDOW_WIDTH > map.width * MAP_SCALE ||
        knight.getWorldPos().y + WINDOW_HEIGHT > map.height * MAP_SCALE)
    {
      knight.undoMovement();
    }
    // check prop collisions
    for (auto prop : props)
    {
      if (CheckCollisionRecs(
              prop.getCollisionRec(knight.getWorldPos()),
              knight.getCollisionRec()))
      {
        knight.undoMovement();
      }
    }

    EndDrawing();
  }
  CloseWindow();
}