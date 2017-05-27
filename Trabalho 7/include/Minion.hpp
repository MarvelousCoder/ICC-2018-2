#ifndef MINIONHPP
#define MINIONHPP

#include "GameObject.hpp"
#include "Sprite.hpp"

class Minion : public GameObject {
    GameObject *center;
    Sprite sp;
    float arc;
    float distance_from_center;
    float angular_velocity;
public:
    virtual void notifyCollision(GameObject &other);
    virtual bool is(std::string type);
    Minion(GameObject* minionCenter, float arcOffset = 0);
    void update(float dt);
    void render();
    bool isDead();
    void shoot(Vec2 pos);
};

#endif // MINIONHPP
