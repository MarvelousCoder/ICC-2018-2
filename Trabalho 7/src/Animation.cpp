#include "Animation.hpp"
#include "Camera.hpp"

Animation::Animation(float x, float y, float rotation, string sprite, float timeLimit, bool ends, int frameCount,
                     float frameTime)
        : sp(sprite, frameCount, frameTime), oneTimeOnly(ends),  timeLimit(timeLimit) {

    this->rotation = rotation;
    endTimer.restart();
    pos = Vec2(x, y);
    int width = sp.GetWidth() / frameCount;
    int height = sp.GetHeight();
    center_LT_displacement = -1 * Vec2(width * 0.5, height * 0.5);
    box = Rect(pos + center_LT_displacement, height, width);
}

void Animation::update(float dt) {
    endTimer.update(dt);

    sp.update(dt);
}

void Animation::render() {
    Vec2 pos = box.getTopLeft() - Camera::getPos(Camera::PLAYER_GROUND_VIEW);

    sp.Render(pos.x, pos.y, rotation);
}

bool Animation::isDead() {
    if (oneTimeOnly && (endTimer.get() > timeLimit))
        return true;
    else
        return false;
}

void Animation::notifyCollision(GameObject *other) {

}

bool Animation::is(std::string type) {
    return type == "Animation";
}

void Animation::notifyCollision(GameObject &other) {

}
