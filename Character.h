#include "raylib.h"

class Character
{
public:
  Character();
  Vector2 getWorldPos() { return worldPos; }
  void setScreenPos(int winWidth, int winHeight);
  void tick(float deltaTime);

private:
  Texture2D texture{LoadTexture("characters/knight_idle_spritesheet.png")};
  Texture2D TEXTURE_IDLE{LoadTexture("characters/knight_idle_spritesheet.png")};
  Texture2D TEXTURE_RUN{LoadTexture("characters/knight_run_spritesheet.png")};
  Vector2 screenPos{};
  Vector2 worldPos{};
  float rightLeft = 1.f; // 1: right, 2: left
  // animation vars
  float runningTime{};
  int frameCount{};
  int maxFrames = 6;
  float updateTime = 1.f / 12.f;
  float speed = 4.f;
  float width{};
  float height{};
};