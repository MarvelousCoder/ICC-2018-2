#ifndef FACEHPP
#define FACEHPP

#include "Sprite.hpp"
#include "GameObject.hpp"

class Face : public GameObject {
protected:
    int hitpoints;
    Sprite sp;
    Vec2 currentPos;
    void construct(float x, float y);
public:
    Face(float x, float y);
    Face(Vec2 pos);
    void Damage(int damage);
    void update(float dt);
    void render();
    bool isDead();
};
#endif // FACEHPP
