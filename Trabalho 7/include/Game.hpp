#ifndef GAMEHPP
#define GAMEHPP

#include <string>
#include <stack>
#include <iostream>
#include <cstdlib>
#include <ctime>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "State.hpp"
using namespace std;

class Game {
    static Game* instance;

    SDL_Window* window;
    SDL_Renderer* renderer;
    State* storedState;
    void CalculateDeltaTime();
    float dt;

    unsigned int frameStart;
    int screenHeight;
    int screenWidth;

    bool gameQuitRequested;

    std::stack<std::shared_ptr<State>> stateStack;
public:
    Game(string title, int width, int height);

    virtual ~Game();

    void Run();

    SDL_Renderer* GetRenderer();
    SDL_Window* GetWindow();

    float getDeltaTime();
    State& getCurrentState();

    static Game& GetInstance();
    Vec2 getScreenDimensions();

    void push(State* state);
    void requestQuit();
};

#endif

