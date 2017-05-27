#ifndef GAMEOBJECTHPP
#define GAMEOBJECTHPP
#include "Rect.hpp"
#include "Sound.hpp"

class GameObject {
protected:
    Rect box;

    Vec2 pos;

    float rotation;

    Vec2 center_LT_displacement;
    void construct();

    Sound dyingSound;
public:
    GameObject();
    virtual ~GameObject();

    virtual void update(float dt) = 0;
    virtual void render() = 0;
    virtual bool isDead() = 0;

    inline Rect &getBox() { return box; }
    inline Vec2 getCenterPos(){return pos;}
    inline float getRotation() { return rotation; }

    virtual void notifyCollision(GameObject &other) = 0;
    virtual bool is(std::string type) = 0;
};


#endif
