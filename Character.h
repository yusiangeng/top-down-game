#include "raylib.h"
#include "BaseCharacter.h"

class Character : public BaseCharacter
{
public:
  Character(int windowWidth, int windowHeight);
  virtual void tick(float deltaTime) override;

private:
};