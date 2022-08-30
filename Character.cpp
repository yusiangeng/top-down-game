#include "Character.h"
#include "raymath.h"

Character::Character(int windowWidth, int windowHeight)
{
  width = texture.width / maxFrames;
  height = texture.height;

  screenPos = {
      static_cast<float>(windowWidth) / 2.f - scale * (0.5f * width),
      static_cast<float>(windowHeight) / 2.f - scale * (0.5f * height)};
}

void Character::tick(float deltaTime)
{
  worldPosLastFrame = worldPos;

  Vector2 direction{};
  if (IsKeyDown(KEY_A))
    direction.x -= 1.f;
  if (IsKeyDown(KEY_D))
    direction.x += 1.f;
  if (IsKeyDown(KEY_W))
    direction.y -= 1.f;
  if (IsKeyDown(KEY_S))
    direction.y += 1.f;
  if (Vector2Length(direction) != 0.f)
  {
    Vector2 directionScaled = Vector2Scale(Vector2Normalize(direction), speed);
    worldPos = Vector2Add(worldPos, directionScaled);
    rightLeft = direction.x < 0.f ? -1.f : 1.f;
    texture = texture_run;
  }
  else
  {
    texture = texture_idle;
  }

  // update animation frame
  runningTime += deltaTime;
  if (runningTime >= updateTime)
  {
    frameCount++;
    runningTime = 0.f;
    if (frameCount > maxFrames)
      frameCount = 0;
  }

  // draw character
  Rectangle source = {
      frameCount * width,
      0.f,
      rightLeft * width,
      height};
  Rectangle dest = {
      screenPos.x,
      screenPos.y,
      scale * width,
      scale * height};
  Vector2 origin{};
  DrawTexturePro(texture, source, dest, origin, 0.f, WHITE);
}

void Character::undoMovement()
{
  worldPos = worldPosLastFrame;
}

Rectangle Character::getCollisionRec()
{
  return Rectangle{
      screenPos.x,
      screenPos.y,
      width * scale,
      height * scale};
}