#include "State.hpp"
#include "Game.hpp"
#include "InputManager.hpp"
#include "Collision.hpp"
#include "Defines.hpp"

State::State() {
    quitRequested = false;
    popRequested = false;
}

State::~State() {

}

bool State::getPopRequested() {
    return popRequested;
}

bool State::getQuitRequested() {
    return quitRequested;
}

void State::updateArray(float dt) {
    for (unsigned int obj_idx = 0; obj_idx < objectArray.size(); obj_idx++)
        objectArray[obj_idx]->update(dt);
}

void State::renderArray() {
    for (auto it = objectArray.begin(); it != objectArray.end(); ++it)
        (*it)->render();
}

void State::AddObject(GameObject *obj) {
    objectArray.emplace_back(obj);
}
