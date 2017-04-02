//
// Created by jasf on 3/16/16.
//

#include "Game.h"
#include "State.h"
#include "Face.h"
#include "Util.h"

State::State() : quitRequested(false), bg("img/ocean.jpg") {

}

State::~State() {
    objectArray.clear();

}

void State::Update(float dt) {

    Input();

    for(auto it = objectArray.begin(); it != objectArray.end(); it++)
        (*it)->Update(dt);

    for(unsigned int i = 0; i < objectArray.size(); i++)
        if(objectArray[i]->IsDead()) {
            objectArray.erase(objectArray.begin() + i);
            i -= 1;
        }

}


bool State::QuitRequested() {
    return quitRequested;
}

void State::Render() {
    bg.Render(0,0);

    for(auto it = objectArray.begin(); it != objectArray.end(); ++it)
        (*it)->Render();
}

Sprite State::getBg(){
    return bg;
}
void State::AddObject(float mouseX, float mouseY){
    objectArray.emplace_back(new Face(Vec2(mouseX, mouseY) + Vec2::getVec2FromPolar(200, Util::deg2rad(rand()%360))));
}
