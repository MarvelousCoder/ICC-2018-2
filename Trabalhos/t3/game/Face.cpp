//
// Created by jasf on 3/23/16.
//

#include "Face.h"

void Face::construct(float x, float y) {

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
}

void Face::Update(float dt) {
    //TODO

}

void Face::Render() {
    sp.render(currentPos.x, currentPos.y);

}

bool Face::IsDead() {
    return hitpoints <= 0;
}
