//
// Created by jasf on 4/21/16.
//

#include "Minion.h"
#include "Resources.h"
#include "Camera.h"
#include "Logger.h"
#include "Bullet.h"
#include "State.h"
#include "Game.h"

Minion::Minion(GameObject *minionCenter, float arcOffset) {

    this->center = minionCenter;
    this->arc = arcOffset;

    sp.open("img/minion.png");
    float scale = 1.0 + (0.5*rand())/RAND_MAX;
    sp.setScaleX(scale);
    sp.setScaleY(scale);

    int width = sp.getWidth();
    int height = sp.getHeight();

    distance_from_center = 150;


    center_LT_displacement = -1*Vec2(height*0.5, width * 0.5);

    angular_velocity = M_PI_4;

    pos = center->getCenterPos() + Vec2::getVec2FromPolar(distance_from_center, arc);

    box = Rect( pos + center_LT_displacement, height, width);

}

void Minion::update(float dt) {
    arc += angular_velocity * dt;
    pos = center->getCenterPos() + Vec2::getVec2FromPolar(distance_from_center, arc);

    rotation = (pos - center->getCenterPos()).ang_rad() + M_PI;


}

void Minion::render() {
    Vec2 c = pos + Camera::getPos(1) + center_LT_displacement;
    sp.render(c.x, c.y, rotation);

}

bool Minion::isDead() {
    return false;

}

void Minion::shoot(Vec2 pos) {
    Bullet *b = new Bullet(this->pos.x, this->pos.y, (pos - this->pos).ang_rad(), 200, 1000, "img/minionbullet1.png" );

    Game::getInstance().GetState().addObject(b);


}
