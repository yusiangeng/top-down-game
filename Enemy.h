#include "raylib.h"
#include "BaseCharacter.h"
#include "Character.h"

class Enemy : public BaseCharacter
{
public:
  Enemy(Vector2 pos, Texture2D texture_idle, Texture2D texture_run);
  virtual void tick(float deltaTime) override;
  void setTarget(Character *character) { target = character; }
  virtual Vector2 getScreenPos() override;

private:
  Character *target;
  float damagePerSecond = 10.f;
  float radius = 25.f;
};