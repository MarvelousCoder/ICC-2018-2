#ifndef FACEHPP
#define FACEHPP

#include "Sprite.hpp"
#include "GameObject.hpp"

class Face : public GameObject {
    int hitpoints;
    Sprite sp;
    Vec2 currentPos;
public:
    Face(float x, float y);
    Face(Vec2 pos);
    void Damage(int damage);
    void Update(float dt);
    void Render();
    bool IsDead();
    void construct(float x, float y);
};
#endif // FACEHPP