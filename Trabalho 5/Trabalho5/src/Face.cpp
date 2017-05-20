#include "Face.hpp"
#include "Camera.hpp"
#include "InputManager.hpp"

Face::Face(float x, float y) {
    construct(x, y);
}

Face::Face(Vec2 pos) {
    construct(pos.x, pos.y);

}

void Face::construct(float x, float y) {
    hitpoints = 20;
    sp.open("img/penguinface.png");

    int width = sp.GetWidth();
    int height = sp.GetHeight();

    currentPos = Vec2(x, y) - Vec2(height * 0.5, width * 0.5);
    x = currentPos.x;
    y = currentPos.y;

    box = Rect(currentPos, height, width);
}

void Face::Damage(int damage) {
    hitpoints -= damage;
}

void Face::update(float dt) {
    InputManager &im = InputManager::getInstance();

    if (im.mousePress(LEFT_MOUSE_BUTTON)) {
        Vec2 mouse_click(im.getMouseX(), im.getMouseY());
        // mouse_click -= Camera::getPos(1);
        if (box.IsInside(mouse_click.x, mouse_click.y))
            Damage(rand() % 10 + 10);
    }
}

void Face::render() {
    sp.Render(currentPos.x, currentPos.y);
}

bool Face::isDead() {
    return hitpoints <= 0;
}
