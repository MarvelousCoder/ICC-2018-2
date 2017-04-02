//
// Created by jasf on 3/16/16.
//

#ifndef IDJ201601T1_STATE_H
#define IDJ201601T1_STATE_H


#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include <memory>

#include "Sprite.h"
#include "GameObject.h"
#include "TileSet.h"
#include "TileMap.h"

class State {
protected:
    Sprite bg;
    bool quitRequested;
    std::vector<std::unique_ptr<GameObject>> objectArray;
    TileSet tileSet;
    TileMap tileMap;

public:
    State();

    bool QuitRequested();

    void Update(float dt);

    void Render();

    virtual ~State();

    Sprite getBg();

    void Input();

    void AddObject(float mouseX, float mouseY);


};


#endif //IDJ201601T1_STATE_H
