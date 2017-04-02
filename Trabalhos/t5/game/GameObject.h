//
// Created by jasf on 3/23/16.
//

#ifndef IDJ201601T1_GAMEOBJECT_H
#define IDJ201601T1_GAMEOBJECT_H

#include "Rect.h"

class GameObject {
protected:
    Rect box;

    //center pos
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


#endif //IDJ201601T1_GAMEOBJECT_H
