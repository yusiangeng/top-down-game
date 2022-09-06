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
  BaseCharacter::tick(deltaTime);

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
}
