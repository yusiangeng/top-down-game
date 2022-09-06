#include "raylib.h"
#include "BaseCharacter.h"

class Enemy : public BaseCharacter
{
public:
  Enemy(Vector2 pos, Texture2D texture_idle, Texture2D texture_run);
  virtual void tick(float deltaTime) override;

private:
};