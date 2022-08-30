#include "raylib.h"
#include "raymath.h"

int main()
{
  const int windowWidth = 384;
  const int windowHeight = 384;
  InitWindow(windowWidth, windowHeight, "Colonize the Crustacean");

  Texture2D map = LoadTexture("nature_tileset/OpenWorldMap24x24.png");
  Vector2 mapPos = {0.0, 0.0};
  float speed = 4.0;

  Texture2D knightIdle = LoadTexture("characters/knight_idle_spritesheet.png");
  Texture2D knightRun = LoadTexture("characters/knight_run_spritesheet.png");
  Texture2D knight = LoadTexture("characters/knight_idle_spritesheet.png");
  Vector2 knightPos = {
      (float)windowWidth / 2.0f - 4.0f * (0.5f * (float)knight.width / 6.0f),
      (float)windowHeight / 2.0f - 4.0f * (0.5f * (float)knight.height)};
  float rightLeft = 1.0f; // 1: right, 2: left

  // knight animation vars
  float runningTime;
  int frameCount;
  const int maxFrames = 6;
  const float updateTime = {1.0f / 12.0f};

  SetTargetFPS(60);
  while (!WindowShouldClose())
  {
    BeginDrawing();
    ClearBackground(WHITE);

    Vector2 direction = {};
    if (IsKeyDown(KEY_A))
      direction.x -= 1.0;
    if (IsKeyDown(KEY_D))
      direction.x += 1.0;
    if (IsKeyDown(KEY_W))
      direction.y -= 1.0;
    if (IsKeyDown(KEY_S))
      direction.y += 1.0;
    if (Vector2Length(direction) != 0.0)
    {
      // mapPos = mapPos - direction
      mapPos = Vector2Subtract(mapPos, Vector2Scale(Vector2Normalize(direction), speed));
      rightLeft = direction.x < 0.0f ? -1.0f : 1.0f;
      knight = knightRun;
    }
    else
    {
      knight = knightIdle;
    }

    // draw map
    DrawTextureEx(map, mapPos, 0.0, 4.0, WHITE);

    // update knight animation frame
    runningTime += GetFrameTime();
    if (runningTime >= updateTime)
    {
      frameCount++;
      runningTime = 0.0f;
      if (frameCount > maxFrames)
        frameCount = 0;
    }

    // draw character
    Rectangle source = {
        frameCount * (float)knight.width / 6.0f,
        0.0f,
        rightLeft * (float)knight.width / 6.0f,
        (float)knight.height};
    Rectangle dest = {
        knightPos.x,
        knightPos.y,
        4.0f * (float)knight.width / 6.0f,
        4.0f * (float)knight.height};
    Vector2 origin = {};
    DrawTexturePro(knight, source, dest, origin, 0.0f, WHITE);

    EndDrawing();
  }
  CloseWindow();
}