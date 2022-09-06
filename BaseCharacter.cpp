#include "BaseCharacter.h"

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
      screenPos.x,
      screenPos.y,
      width * scale,
      height * scale};
}

void BaseCharacter::tick(float deltaTime)
{
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