//
// Created by jasf on 3/23/16.
//

#ifndef IDJ201601T1_GAMEOBJECT_H
#define IDJ201601T1_GAMEOBJECT_H

#include "Rect.h"

class GameObject {
protected:
    Rect box;

public:
    GameObject();
    virtual ~GameObject();

    virtual void Update(float dt) = 0;
    virtual void Render() = 0;
    virtual bool IsDead() = 0;

    inline Rect & getBox(){return box;}



};


#endif //IDJ201601T1_GAMEOBJECT_H
