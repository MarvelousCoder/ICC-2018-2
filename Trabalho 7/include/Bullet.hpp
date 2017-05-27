#ifndef BULLETHPP
#define BULLETHPP

#include "Sprite.hpp"
#include "Vec2.hpp"
#include "GameObject.hpp"

class Bullet : public GameObject {
protected:
    Sprite sp;
    Vec2 speed;
    float distanceLeft;
    bool targetsPlayer;
public:
    virtual void notifyCollision(GameObject &other);
    virtual bool is(std::string type);
    Bullet(float x, float y, float angle, float speed, float maxDistance, string sprite, float frameTime,
           int frameCount, bool targetsPlayer);
    void update(float dt);
    void render();
    bool isDead();
    inline bool getTargetsPlayer(){return targetsPlayer;}
};

#endif // BULLETHPP
