#ifndef GAMEOBJECTHPP
#define GAMEOBJECTHPP
#include "Rect.hpp"

class GameObject {
protected:
    Rect box;
    Vec2 pos;
    float rotation;
    void constuct();
public:
    GameObject();
    virtual ~GameObject();
    virtual void update(float dt) = 0;
    virtual void render() = 0;
    virtual bool isDead() = 0;
    inline Rect &getBox() { return box; }
    inline Vec2 getCenterPos(){return pos;}
};


#endif
