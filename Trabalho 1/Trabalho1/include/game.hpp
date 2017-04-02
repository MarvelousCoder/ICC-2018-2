#ifndef GAMEHPP
#define GAMEHPP

#include "SDL.h"
#include "SDL_image.h"
#include "state.hpp"
#include <string>
#include <iostream>
using namespace std;

class Game {
    static Game* instance;
    SDL_Window* window;
    SDL_Renderer* renderer;
    State* state;
public:
    void Run();
    SDL_Renderer* GetRenderer();
    State& GetState();
    static Game& GetInstance();
    ~Game();
    Game(string title, int width, int height);
};

#endif
