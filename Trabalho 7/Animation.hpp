#ifndef ANIMATIONHPP
#define ANIMATIONHPP

#include "Timer.hpp"
#include "Sprite.hpp"
#include "GameObject.hpp"

class Animation : public GameObject {
    Timer endTimer;
    float timeLimit;
    bool oneTimeOnly;
    Sprite sp;
public:
    Animation(float x, float y, float rotation, string sprite, float timeLimit, bool ends, int frameCount, float frameTime);
    void update(float dt);
    bool isDead();
    virtual void notifyCollision(GameObject &other);
    void notifyCollision(GameObject *other);
    virtual bool is(std::string type);
    void render();
};


#endif // ANIMATIONHPP
