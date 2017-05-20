#ifndef STATEHPP
#define STATEHPP

#include "Sprite.hpp"
#include "GameObject.hpp"
#include "TileSet.hpp"
#include "TileMap.hpp"
#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include <memory>

class State {
protected:
    Sprite bg;
    bool quitRequested;
    std::vector<std::unique_ptr<GameObject>> objectArray;
    TileSet tileSet;
    TileMap tileMap;
public:
    void AddObject(GameObject *o);
    void addObject(float mouseX, float mouseY);
    State();
    ~State();
    bool QuitRequested();
    void Update(float dt);
    void Render();
    Sprite getBg();
};

#endif
