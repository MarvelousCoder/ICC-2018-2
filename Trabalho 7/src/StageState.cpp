#include "Game.hpp"
#include "InputManager.hpp"
#include "Defines.hpp"
#include "Camera.hpp"
#include "Alien.hpp"
#include "Penguins.hpp"
#include "Collision.hpp"
#include "StageState.hpp"
#include "EndState.hpp"

#define TILE_HEIGHT 64
#define TILE_WIDTH 64

StageState::StageState() : bg("img/ocean.jpg"), tileSet(TILE_WIDTH, TILE_HEIGHT, "img/tileset.png"),
                           tileMap("map/tileMap.txt", &tileSet), gameBackroundMusic("audio/stageState.ogg") {

    Penguins *player = new Penguins(704, 640);
    Camera::Follow(player);
    objectArray.emplace_back(new Alien(512, 300, 6));
    objectArray.emplace_back(&(*player));

    gameBackroundMusic.play(-1);


}

StageState::~StageState() {
    objectArray.clear();

}

Sprite StageState::getBg() {
    return bg;
}


void StageState::update(float dt) {
    InputManager &im = InputManager::getInstance();

    if (im.keyPress(ESCAPE_KEY) | im.getQuitRequested())
        popRequested = true;

    Camera::Update(dt);

    updateArray(dt);

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

    if( Alien::getAlientCount() <= 0){
        popRequested = true;
        Game::GetInstance().push(new EndState(StateData{true}));
    }




}

void StageState::render() {
    bg.Render(0, 0, 0);

    tileMap.RenderLayer(0, Camera::getPos(Camera::PLAYER_GROUND_VIEW));

    renderArray();

    tileMap.RenderLayer(1, Camera::getPos(Camera::TOPGROUND_VIEW));

}

void StageState::pause() {

}

void StageState::resume() {

}
