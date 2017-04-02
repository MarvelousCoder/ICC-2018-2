//
// Created by jasf on 3/16/16.
//

#ifndef IDJ201601T1_STATE_H
#define IDJ201601T1_STATE_H


#include <SDL.h>
#include <SDL_image.h>

#include "Sprite.h"

class State {
protected:
    Sprite bg;
    bool quitRequested;

public:
    State();

    bool QuitRequested();

    void Update(float dt);

    void Render();

    virtual ~State();

    Sprite getBg();


};


#endif //IDJ201601T1_STATE_H
