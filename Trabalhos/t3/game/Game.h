//
// Created by jasf on 3/15/16.
//
#ifndef IDJ201601T1_GAME_H
#define IDJ201601T1_GAME_H

#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "State.h"

using namespace std;

class Game {
protected:
    static Game* instance;
    SDL_Window* window;
    SDL_Renderer* renderer;
    State* state;

public:
    Game(string name, int width, int height);

    virtual ~Game();

    void Run();

    SDL_Renderer* GetRenderer();
    SDL_Window* GetWindow();

    State& GetState();

    static Game& GetInstance();
};


#endif //IDJ201601T1_GAME_H
