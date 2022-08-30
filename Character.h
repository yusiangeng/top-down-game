#include "raylib.h"

class Character
{
public:
  Character(int windowWidth, int windowHeight);
  Vector2 getWorldPos() { return worldPos; }
  void tick(float deltaTime);
  void undoMovement();
  Rectangle getCollisionRec();

private:
  Texture2D texture{LoadTexture("characters/knight_idle_spritesheet.png")};
  Texture2D texture_idle{LoadTexture("characters/knight_idle_spritesheet.png")};
  Texture2D texture_run{LoadTexture("characters/knight_run_spritesheet.png")};
  Vector2 screenPos{};
  Vector2 worldPos{};
  Vector2 worldPosLastFrame{};
  float rightLeft = 1.f; // 1: right, 2: left
  // animation vars
  float runningTime{};
  int frameCount{};
  int maxFrames = 6;
  float updateTime = 1.f / 12.f;
  float speed = 4.f;
  float width{};
  float height{};
  float scale = 4.f;
};