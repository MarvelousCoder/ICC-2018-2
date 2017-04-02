#ifndef STATEHPP
#define STATEHPP

#include "sprite.hpp"
#include "SDL.h"
#include "SDL_image.h"


class State {
    Sprite bg;
    bool quitRequested;
public:
    State();
    bool QuitRequested();
    void Update(float dt);
    void Render();
    Sprite getBg();
    virtual ~State();
};

#endif
