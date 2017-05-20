#include "Minion.hpp"
#include "Resources.hpp"
#include "Camera.hpp"
#include "Bullet.hpp"
#include "State.hpp"
#include "Game.hpp"
#define M_PI_4 0.785398163397448309616
#define M_PI 3.14159265358979323846

Minion::Minion(GameObject *minionCenter, float arcOffset) : sp("img/minion.png"){
    this->center = minionCenter;
    this->arc = arcOffset;

    float scale = 1.0 + (0.5*rand())/RAND_MAX;
    sp.setScaleX(scale);
    sp.setScaleY(scale);
    sp.setCenter(Vec2(31, 30));
    int width = sp.GetWidth();
    int height = sp.GetHeight();
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
    box.setRotation(rotation);
    box.setLT(pos + center_LT_displacement);
}

void Minion::render() {
    Vec2 c = pos - Camera::getPos(Camera::PLAYER_GROUND_VIEW) + center_LT_displacement;
    sp.Render(c.x, c.y, rotation);
}

bool Minion::isDead() {
    return false;
}

void Minion::shoot(Vec2 pos) {
    Bullet *b = new Bullet(this->pos.x, this->pos.y, (pos - this->pos).ang_rad(), 200, 1000, "img/minionbullet2.png",
                           0.2, 3, true);
    Game::GetInstance().GetState().AddObject(b);
}

void Minion::notifyCollision(GameObject &other) {

}

bool Minion::is(std::string type) {
    return type == "Minion";
}

