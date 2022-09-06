#include "enemy.h"

Enemy::Enemy(
    Vector2 pos,
    Texture2D texture_idle,
    Texture2D texture_run)
{
  texture = texture_idle;
  texture_idle = texture_idle;
  texture_run = texture_run;
  worldPos = pos;

  width = texture.width / maxFrames;
  height = texture.height;
}

void Enemy::tick(float deltaTime)
{
  BaseCharacter::tick(deltaTime);
}
