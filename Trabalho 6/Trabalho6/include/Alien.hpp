#ifndef ALIENHPP
#define ALIENHPP

#include <queue>
#include "GameObject.hpp"
#include "Sprite.hpp"
#include "Minion.hpp"
#include "Timer.hpp"

class Alien : public GameObject {
    Sprite sp;
    Vec2 speed;
    enum AlientState{ MOVING, RESTING};
    AlientState state;
    Timer restTimer;
    Vec2 destination;
    static float VELOCITY_CONST;
    static float alienCoolDownTime;
    static int alientCount;
    int hp;
    std::vector<Minion *> minionArray;
    float angular_velocity;
public:
    Alien(float x, float y, int nMinions);
    virtual bool is(std::string type);
    virtual void notifyCollision(GameObject &other);
    virtual ~Alien();
    void update(float dt);
    void render();
    bool isDead();
    void damage(int dm);
};
#endif // ALIENHPP
