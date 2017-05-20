#ifndef BULLETHPP
#define BULLETHPP

#include "Sprite.hpp"
#include "Vec2.hpp"
#include "GameObject.hpp"

class Bullet : public GameObject{

protected:
    Sprite sp;
    Vec2 speed;
    float distanceLeft;
public:
    Bullet(float x, float y, float angle, float speed, float maxDistance, string sprite);
    void update(float dt);
    void render();
    bool isDead();
    Vec2 center_LT_displacement;
};

#endif // BULLETHPP
