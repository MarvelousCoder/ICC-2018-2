#include "Face.hpp"

Face::Face(float x, float y) {
    construct(x, y);
}

Face::Face(Vec2 pos) {
    construct(pos.x, pos.y);

}

void Face::construct(float x, float y) {
    sp.open("img/penguinface.png");

    int width = sp.GetWidth();
    int height = sp.GetHeight();

    currentPos = Vec2(x, y) - Vec2(height * 0.5, width * 0.5);
    x = currentPos.x;
    y = currentPos.y;

    box = Rect(currentPos, height, width);

    hitpoints = 30;
}

void Face::Damage(int damage) {
    hitpoints -= damage;
}

void Face::Update(float dt) {

}

void Face::Render() {
    sp.Render(currentPos.x, currentPos.y);
}

bool Face::IsDead() {
    return hitpoints <= 0;
}
