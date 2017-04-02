//
// Created by jasf on 3/23/16.
//

#include "Face.h"
#include "InputManager.h"
#include "defines.h"
#include "Logger.h"
#include "Camera.h"

std::vector<std::string> Face::angryMsgs{
        "You'll pay for this, Summer boy!",
        "You'll your actions!",
        "I'll make you pay!",
        "Only your life will pay for this insult"
};

std::vector<std::string> Face::eliminatedMsgs{
        "Next time you won't be having fun...",
        "My friends will revenge me....",
        "You may have the battle, but never the war!"
};
unsigned int Face::angryMsgIdx = 0;
unsigned int Face::eliminatedMsgIdx = 0;

void Face::construct(float x, float y) {

    hitpoints = 20;

    sp.open("img/penguinface.png");
    int width = sp.getWidth();
    int height = sp.getHeight();

    currentPos = Vec2(x, y) - Vec2(height * 0.5, width * 0.5);
    x = currentPos.x;
    y = currentPos.y;

    box = Rect(currentPos, height, width);

}

Face::Face(float x, float y) {
    construct(x, y);

}

Face::Face(Vec2 pos) {
    construct(pos.x, pos.y);

}


void Face::Damage(int damage) {
    hitpoints -= damage;
    Logger::log("Mad penguim says: \"" + getNextAngryMsg() + "\"");

}

void Face::update(float dt) {
    InputManager &im = InputManager::getInstance();


    if (im.mousePress(LEFT_MOUSE_BUTTON)) {
        Vec2 mouse_click(im.getMouseX(), im.getMouseY());
        mouse_click -= Camera::getPos(1);
        if (box.isPointInside(mouse_click.x, mouse_click.y))
            Damage(rand() % 10 + 10);
    }

}

void Face::render() {
    Vec2 c = currentPos + Camera::getPos(1);
    sp.render(c.x, c.y, 0);

}

bool Face::isDead() {
    return hitpoints <= 0;
}

std::string Face::getNextAngryMsg() {
    angryMsgIdx = (angryMsgIdx + 1) % angryMsgs.size();
    return angryMsgs[angryMsgIdx];

}

std::string Face::getNextEliminatedMsg() {
    eliminatedMsgIdx = (eliminatedMsgIdx + 1) % eliminatedMsgs.size();
    return eliminatedMsgs[eliminatedMsgIdx];
}
