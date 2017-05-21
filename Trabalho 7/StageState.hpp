#ifndef STAGESTATEHPP
#define STAGESTATEHPP

#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include <memory>

#include "Sprite.hpp"
#include "GameObject.hpp"
#include "TileSet.hpp"
#include "TileMap.hpp"
#include "State.hpp"
#include "Music.hpp"

class StageState : public State {
protected:
    Sprite bg;
    TileSet tileSet;
    TileMap tileMap;

    Music gameBackroundMusic;

public:
    StageState();

    virtual ~StageState();

    void update(float dt);
    void render();
    void pause();
    void resume();

    Sprite getBg();

};

#endif // STATESTATEHPP
