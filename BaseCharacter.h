#ifndef BASE_CHARACTER_H
#define BASE_CHARACTER_H
#include "raylib.h"

class BaseCharacter
{
public:
  BaseCharacter();
  Vector2 getWorldPos() { return worldPos; }
  void undoMovement();
  Rectangle getCollisionRec();
  virtual void tick(float deltaTime);
  virtual Vector2 getScreenPos() = 0;
  bool getAlive() { return alive; }
  void setAlive(bool alive) { this->alive = alive; }

protected:
  Texture2D texture{LoadTexture("characters/knight_idle_spritesheet.png")};
  Texture2D texture_idle{LoadTexture("characters/knight_idle_spritesheet.png")};
  Texture2D texture_run{LoadTexture("characters/knight_run_spritesheet.png")};
  Vector2 screenPos{};
  Vector2 worldPos{};
  Vector2 worldPosLastFrame{};
  float rightLeft = 1.f; // 1: right, -1: left
  // animation vars
  float runningTime{};
  int frameCount{};
  int maxFrames = 6;
  float updateTime = 1.f / 12.f;
  float speed = 4.f;
  float width{};
  float height{};
  float scale = 4.f;
  Vector2 velocity{};

private:
  bool alive = true;
};

#endif