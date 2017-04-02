//
// Created by jasf on 4/21/16.
//

#ifndef IDJ201601T1_BULLET_H
#define IDJ201601T1_BULLET_H


#include "Sprite.h"
#include "Vec2.h"
#include "GameObject.h"

class Bullet : public GameObject{

protected:

    Sprite sp;
    Vec2 speed;
    float distanceLeft;

public:

    Bullet(float x, float y, float angle, float speed, float maxDistance, string sprite);

    void update(float dt);

    void render();

    bool isDead();


    Vec2 center_LT_displacement;
};


#endif //IDJ201601T1_BULLET_H
