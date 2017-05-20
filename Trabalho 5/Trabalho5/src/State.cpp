#include "State.hpp"
#include "Game.hpp"
#include "Face.hpp"
#include "Camera.hpp"
#include "InputManager.hpp"
#include "Alien.hpp"

State::State() : quitRequested(false), bg("img/ocean.jpg"), tileSet(64, 64, "img/tileset.png"),
    tileMap("map/tileMap.txt", &tileSet) {

    objectArray.emplace_back(new Alien(512, 300, 6));

}

State::~State() {
    objectArray.clear();
}

void State::Update(float dt) {
    InputManager &im = InputManager::getInstance();

    if(im.keyPress(ESCAPE_KEY) | im.getQuitRequested())
        quitRequested = true;

    if (im.keyPress(SDL_SCANCODE_3))
        addObject((float) im.getMouseX(), (float) im.getMouseY());

    Camera::Update(dt);

    std::vector<int> toBeDeleted;
    for(unsigned int i = 0; i < objectArray.size(); i++)
        if(objectArray[i]->isDead())
            toBeDeleted.push_back(i);
    auto objArrayBegin = objectArray.begin();
    for(auto it = toBeDeleted.rbegin(); it != toBeDeleted.rend(); ++it)
        objectArray.erase(objArrayBegin + *it);
}

bool State::QuitRequested() {
    return quitRequested;
}

void State::Render() {
    bg.Render(0, 0);
    tileMap.RenderLayer(0, Camera::getPos(1));
    for (auto it = objectArray.begin(); it != objectArray.end(); ++it)
        (*it)->render();
    tileMap.RenderLayer(1, Camera::getPos(2));
}

Sprite State::getBg() {
    return bg;
}


void State::AddObject(GameObject *o) {
    objectArray.emplace_back(o);
}

void State::addObject(float mouseX, float mouseY) {
objectArray.emplace_back(new Face
                             (Vec2(mouseX, mouseY)
                              + Vec2::getVec2FromPolar(200, (rand()%360)*3.14159265358979323846/180.0) - Camera::getPos(1)));
}
