#ifndef MINIONHPP
#define MINIONHPP

#include "GameObject.hpp"
#include "Sprite.hpp"

class Minion : public GameObject {
    GameObject *center;
    Sprite sp;
    float arc;
    Vec2 center_LT_displacement;
    float distance_from_center;
    float angular_velocity;
public:
    Minion(GameObject* minionCenter, float arcOffset = 0);
    void update(float dt);
    void render();
    bool isDead();
    void shoot(Vec2 pos);
};

#endif // MINIONHPP
