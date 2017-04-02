#ifndef GAMEOBJECTHPP
#define GAMEOBJECTHPP
#include "Rect.hpp"

class GameObject {
public:
    GameObject();
    virtual ~GameObject();
    virtual void Update(float dt) = 0;
    virtual void Render() = 0;
    virtual bool IsDead() = 0;
    Rect box;
};


#endif
