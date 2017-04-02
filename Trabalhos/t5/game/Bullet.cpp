//
// Created by jasf on 4/21/16.
//

#include "Bullet.h"
#include "Camera.h"

Bullet::Bullet(float x, float y, float angle, float speed, float maxDistance, string sprite) {

    sp.open(sprite);

    rotation = angle;

    this->speed = Vec2::getVec2FromPolar(speed, angle);

    distanceLeft = maxDistance;

    pos = Vec2(x, y);

    int width = sp.getWidth();
    int height = sp.getHeight();


    center_LT_displacement = -1 * Vec2(height * 0.5, width * 0.5);

    box = Rect(pos + center_LT_displacement, height, width);


}

void Bullet::update(float dt) {

    pos += speed * dt;

    distanceLeft -= (speed * dt).magnitude();

}

void Bullet::render() {
    Vec2 c = pos + Camera::getPos(1) + center_LT_displacement;
    sp.render(c.x, c.y, rotation);

}

bool Bullet::isDead() {
    return distanceLeft <= 0;
}
