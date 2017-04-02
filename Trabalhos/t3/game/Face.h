//
// Created by jasf on 3/23/16.
//

#ifndef IDJ201601T1_FACE_H
#define IDJ201601T1_FACE_H


#include <Sprite.h>
#include "GameObject.h"

class Face : public GameObject{

protected:
    int hitpoints;
    Sprite sp;
    Vec2 currentPos;

    void construct(float x, float y);

public:
    /***
     * x and y are the coordinates of the center
     */
    Face(float x, float y);
    Face(Vec2 pos);
    void Damage(int damage);
    void Update(float dt);
    void Render();
    bool IsDead();


};


#endif //IDJ201601T1_FACE_H
