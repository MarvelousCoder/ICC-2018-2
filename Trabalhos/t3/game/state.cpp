//
// Created by jasf on 3/16/16.
//

#include <Game.h>
#include "State.h"
#include "Face.h"
#include "Util.h"

#define TILE_HEIGHT 64
#define TILE_WIDTH 64
State::State() : quitRequested(false), bg("img/ocean.jpg"), tileSet(TILE_WIDTH, TILE_HEIGHT, "img/tileset.png"),
    tileMap("map/tileMap.txt", &tileSet){

}

State::~State() {
    objectArray.clear();

}

void State::Update(float dt) {

    Input();

    std::vector<int> toBeDeleted;
    //collect index to all objects that need to be deleted
    for(int i = 0; i < objectArray.size(); i++)
        if(objectArray[i]->IsDead())
            toBeDeleted.push_back(i);
    //delete them
    auto objArrayBegin = objectArray.begin();
    for(auto it = toBeDeleted.rbegin(); it != toBeDeleted.rend()  ; ++it)
        objectArray.erase(objArrayBegin + *it);

}


bool State::QuitRequested() {
    return quitRequested;
}

void State::Render() {
    bg.render(0, 0);

    tileMap.renderLayer(0, 0, 0);

    for(auto it = objectArray.begin(); it != objectArray.end(); ++it)
        (*it)->Render();

    tileMap.renderLayer(1, 0, 0);
}

Sprite State::getBg(){
    return bg;
}
void State::AddObject(float mouseX, float mouseY){
    objectArray.emplace_back(new Face(Vec2(mouseX, mouseY) + Vec2::getVec2FromPolar(200, Util::deg2rad(rand()%360))));
}
