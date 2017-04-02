//
// Created by jasf on 3/16/16.
//

#include <Game.h>
#include "Util.h"
#include "InputManager.h"
#include "defines.h"
#include "Camera.h"
#include "Alien.h"
#include "Penguins.h"
#include "Collision.h"

#define TILE_HEIGHT 64
#define TILE_WIDTH 64

State::State() : quitRequested(false), bg("img/ocean.jpg"), tileSet(TILE_WIDTH, TILE_HEIGHT, "img/tileset.png"),
                 tileMap("map/tileMap.txt", &tileSet) {

    Penguins *player = new Penguins(704, 640);
    Camera::follow(player);
    objectArray.emplace_back(new Alien(512, 300, 6));
    objectArray.emplace_back(player);

}

State::~State() {
    objectArray.clear();

}

void State::Update(float dt) {
    InputManager &im = InputManager::getInstance();

    if (im.keyPress(ESCAPE_KEY) | im.getQuitRequested())
        quitRequested = true;

    Camera::update(dt);

    for (int obj_idx = 0; obj_idx < objectArray.size(); obj_idx++)
        objectArray[obj_idx]->update(dt);

    //test for collision

    for (int i = objectArray.size() - 1; i >= 0; i--) {
        if (objectArray[i]->is("Animation"))
            continue;
        for (int j = 0; j < i; j++) {
            if (objectArray[j]->is("Animation"))
                continue;
            if (Collision::IsColliding(objectArray[i]->getBox(), objectArray[j]->getBox(),
                                       objectArray[i]->getRotation(), objectArray[j]->getRotation())) {
                objectArray[i]->notifyCollision(*objectArray[j]);
                objectArray[j]->notifyCollision(*objectArray[i]);

            }

        }

    }


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

    tileMap.renderLayer(0, Camera::getPos(Camera::PLAYER_GROUND_VIEW));

    for (auto it = objectArray.begin(); it != objectArray.end(); ++it)
        (*it)->render();

    tileMap.renderLayer(1, Camera::getPos(Camera::TOPGROUND_VIEW));
}

Sprite State::getBg() {
    return bg;
}

void State::AddObject(float mouseX, float mouseY) {

}

void State::addObject(GameObject *o) {
    objectArray.emplace_back(o);

}
