//
// Created by jasf on 3/16/16.
//

#include <Game.h>
#include "Face.h"
#include "Util.h"
#include "InputManager.h"
#include "defines.h"
#include "Camera.h"
#include "Alien.h"

#define TILE_HEIGHT 64
#define TILE_WIDTH 64

State::State() : quitRequested(false), bg("img/ocean.jpg"), tileSet(TILE_WIDTH, TILE_HEIGHT, "img/tileset.png"),
                 tileMap("map/tileMap.txt", &tileSet) {

    objectArray.emplace_back(new Alien(512, 300, 6));

}

State::~State() {
    objectArray.clear();

}

void State::Update(float dt) {
    InputManager &im = InputManager::getInstance();

    if (im.keyPress(ESCAPE_KEY) | im.getQuitRequested())
        quitRequested = true;

    if (im.keyPress(SDL_SCANCODE_3)) {
        AddObject((float) im.getMouseX(), (float) im.getMouseY());
    }

    Camera::update(dt);

    for (int obj_idx = 0; obj_idx < objectArray.size(); obj_idx++)
        objectArray[obj_idx]->update(dt);


    std::vector<int> toBeDeleted;
    //collect index to all objects that need to be deleted
    for (unsigned int i = 0; i < objectArray.size(); i++)
        if (objectArray[i]->isDead())
            toBeDeleted.push_back(i);
    //delete them
    auto objArrayBegin = objectArray.begin();
    for (auto it = toBeDeleted.rbegin(); it != toBeDeleted.rend(); ++it)
        objectArray.erase(objArrayBegin + *it);

}


bool State::QuitRequested() {
    return quitRequested;
}

void State::Render() {
    bg.render(0, 0, 0);

    tileMap.renderLayer(0, Camera::getPos(1));

    for (auto it = objectArray.begin(); it != objectArray.end(); ++it)
        (*it)->render();

    tileMap.renderLayer(1, Camera::getPos(2));
}

Sprite State::getBg() {
    return bg;
}

void State::AddObject(float mouseX, float mouseY) {

    objectArray.emplace_back(new Face(
            Vec2(mouseX, mouseY) + Vec2::getVec2FromPolar(200, Util::deg2rad(rand() % 360)) - Camera::getPos(1)));
}

void State::addObject(GameObject *o) {
    objectArray.emplace_back(o);

}
