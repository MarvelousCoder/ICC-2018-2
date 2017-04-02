//
// Created by jasf on 3/16/16.
//

#ifndef IDJ201601T1_STATE_H
#define IDJ201601T1_STATE_H


#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include <memory>

#include "Sprite.h"
#include "GameObject.h"

class State {
protected:
    bool quitRequested;
    Sprite bg;
    std::vector<std::unique_ptr<GameObject>> objectArray;

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
