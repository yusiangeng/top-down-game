#include "BaseCharacter.h"
#include "raymath.h"

BaseCharacter::BaseCharacter()
{
}

void BaseCharacter::undoMovement()
{
  worldPos = worldPosLastFrame;
}

Rectangle BaseCharacter::getCollisionRec()
{
  return Rectangle{
      getScreenPos().x,
      getScreenPos().y,
      width * scale,
      height * scale};
}

void BaseCharacter::tick(float deltaTime)
{
  if (!getAlive())
    return;

  worldPosLastFrame = worldPos;

  // update animation frame
  runningTime += deltaTime;
  if (runningTime >= updateTime)
  {
    frameCount++;
    runningTime = 0.f;
    if (frameCount > maxFrames)
      frameCount = 0;
  }

  // move character
  if (Vector2Length(velocity) != 0.f)
  {
    Vector2 directionScaled = Vector2Scale(Vector2Normalize(velocity), speed);
    worldPos = Vector2Add(worldPos, directionScaled);
    rightLeft = velocity.x < 0.f ? -1.f : 1.f;
    texture = texture_run;
  }
  else
  {
    texture = texture_idle;
  }
  velocity = {};

  // draw character
  Rectangle source = {
      frameCount * width,
      0.f,
      rightLeft * width,
      height};
  Rectangle dest = {
      getScreenPos().x,
      getScreenPos().y,
      scale * width,
      scale * height};
  Vector2 origin{};
  DrawTexturePro(texture, source, dest, origin, 0.f, WHITE);
}