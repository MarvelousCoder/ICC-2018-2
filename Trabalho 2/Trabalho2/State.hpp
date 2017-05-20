#ifndef STATEHPP
#define STATEHPP

#include "Sprite.hpp"
#include "GameObject.hpp"
#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include <memory>

class State {
    Sprite bg;
    bool quitRequested;
    void Input();
    void AddObject(float mouseX, float mouseY);
    std::vector<std::unique_ptr<GameObject>> objectArray;
public:
    State();
    ~State();
    bool QuitRequested();
    void Update(float dt);
    void Render();
    Sprite getBg();
};

#endif