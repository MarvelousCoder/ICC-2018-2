#ifndef PENGUINSHPP
#define PENGUINSHPP

#include "Sprite.hpp"
#include "Vec2.hpp"
#include "GameObject.hpp"
#include "Timer.hpp"

class Penguins : public GameObject {
    Sprite bodySp, cannonSp;
    Vec2 speed;
    float linearSpeed, cannonAngle;
    int hp;
    Vec2 penguint_LT_displacement;
    Vec2 cannon_center_LT_displacement;
    static float MAX_LIN_SPEED;
    static float MIN_LIN_SPEED;
    Timer coolDownTimer;
public:
    virtual void notifyCollision(GameObject &other);
    virtual bool is(std::string type);
    Penguins(float x, float y);
    virtual ~Penguins();
    void update(float dt);
    void render();
    bool isDead();
    void shoot();
    static Penguins* player;
    void damage(int dm);
};

#endif // PENGUISHPP
