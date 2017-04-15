#ifndef GAMEHPP
#define GAMEHPP

#include <SDL.h>
#include <SDL_image.h>
#include "State.hpp"
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Game {
    static Game* instance;
    SDL_Window* window;
    SDL_Renderer* renderer;
    State* state;
    unsigned int frameStart;
    float dt;
    void CalculateDeltaTime();
public:
    float getDeltaTime();
    void Run();
    SDL_Renderer* GetRenderer();
    State& GetState();
    static Game& GetInstance();
    ~Game();
    Game(string title, int width, int height);
};

#endif

