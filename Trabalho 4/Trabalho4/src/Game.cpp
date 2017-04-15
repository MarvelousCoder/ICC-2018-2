#include "Game.hpp"
#include <iostream>
#include <string>
#include <SDL_render.h>
#include "Resources.hpp"
#include "InputManager.hpp"
#include "Camera.hpp"


#include <algorithm>
using namespace std;

Game *Game::instance = nullptr;

Game::Game(string title, int width, int height) {
    srand(time(NULL));
    dt = 0.0;
    frameStart = SDL_GetTicks();

    if(!instance) {
        instance = this;
    } else {
        cout << "Ja ha uma instancia da classe Game rodando\n";
        exit(0);
    }
    if((SDL_Init((SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER)) != 0)) {
        cout << "Falha para inicializacao da SDL_Init\n" << SDL_GetError() << endl;
        exit(0);
    } else
        SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER);
    if((IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF)) == 0) {
        cout << "Falha para inicializacao da IMG_Init\n";
        exit(0);
    } else
        IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF);
    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);

    if(window == nullptr) {
        cout << "Falha em SDL_CreateWindow\n";
        exit(0);
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(renderer == nullptr) {
        cout << "Falha em SDL_CreateRenderer\n";
        exit(0);
    }
    state = new State();
    Camera::setLvsOfParalax(3, std::vector<float>{0.9, 1.0, 1.2});
}

Game::~Game() {
    delete state;
    IMG_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}


Game& Game::GetInstance() {
    return *instance;
}

State& Game::GetState() {
     return *(this->state);
}

SDL_Renderer* Game::GetRenderer() {
   return this->renderer;
}

void Game::CalculateDeltaTime() {

    unsigned int tmp = frameStart;
    frameStart = SDL_GetTicks();
    dt = max((frameStart - tmp)/1000.0, 0.001);

}

float Game::getDeltaTime() {
    return dt;
}

void Game::Run() {
    float dt = 0.1;

    InputManager& im = InputManager::getInstance();
    CalculateDeltaTime();
    while (!state->QuitRequested()) {
        CalculateDeltaTime();
        im.Update();
        state->Update(getDeltaTime());
        state->Render();
        SDL_RenderPresent(renderer);
        // SDL_Delay(33);
    }
    Resources::clearImages();
}
