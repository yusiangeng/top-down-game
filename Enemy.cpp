#include "Enemy.h"
#include "raymath.h"

Enemy::Enemy(
    Vector2 pos,
    Texture2D texture_idle,
    Texture2D texture_run)
{
  texture = texture_idle;
  this->texture_idle = texture_idle;
  this->texture_run = texture_run;
  worldPos = pos;

  width = texture.width / maxFrames;
  height = texture.height;

  speed = 3.f;
}

Vector2 Enemy::getScreenPos()
{
  return Vector2Subtract(worldPos, target->getWorldPos());
}

void Enemy::tick(float deltaTime)
{
  velocity = Vector2Subtract(target->getScreenPos(), getScreenPos());
  if (Vector2Length(velocity) < radius)
  {
    velocity = {};
  }

  BaseCharacter::tick(deltaTime);

  if (CheckCollisionRecs(target->getCollisionRec(), getCollisionRec()))
  {
    target->takeDamage(damagePerSecond * deltaTime);
  }
}
