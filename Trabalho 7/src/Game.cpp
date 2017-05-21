#include <vector>
#include <algorithm>
#include <functional>
#include <SDL_render.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

#include "Game.hpp"
#include "Resources.hpp"
#include "InputManager.hpp"
#include "Camera.hpp"


Game *Game::instance = nullptr;

Game::Game(string title, int width, int height) {
    gameQuitRequested = false;

    screenWidth = width;
    screenHeight = height;
    srand(time(NULL));
    dt = 0.0;
    frameStart = SDL_GetTicks();

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "");
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


    int audio_modules = MIX_INIT_OGG;
    int res;
    if ((res = Mix_Init(audio_modules)) != audio_modules) {
        if ((MIX_INIT_OGG & res ) == 0 ){
            cerr << "OGG flag not in res!" << endl;
        }
        if ((MIX_INIT_MP3 & res ) == 0 ){
            cerr << "MP3 flag not in res!" << endl;
        }
        cout << "Problem when initiating SDL audio!";
    }

    if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) != 0) {
        cout << "Problem when initiating SDL audio!";

    }

    if(TTF_Init() != 0) {
        cerr << "Could not initialize TTF module!" << std::endl;
        requestQuit();
    }


    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);

    if(window == nullptr) {
        cout << "Falha em SDL_CreateWindow\n";
        exit(0);
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(renderer == nullptr) {
        cout << "Falha em SDL_CreateRenderer\n";
        exit(0);
    }
    Camera::setLvsOfParalax(3, std::vector<float>{0.9, 1.0, 1.2});
}

SDL_Renderer *Game::GetRenderer() {
    return this->renderer;
}

SDL_Window *Game::GetWindow() {
    return this->window;
}

Game &Game::GetInstance() {
    return *instance;
}

State &Game::getCurrentState() {
    return *stateStack.top();
}

Game::~Game() {
    while (!stateStack.empty())
        stateStack.pop();

    //shut img library down
    IMG_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    Mix_CloseAudio();
    Mix_Quit();

    TTF_Quit();
    //shut sdl down
    SDL_Quit();

}

void Game::Run() {
    if (storedState) {
        stateStack.emplace(&(*storedState));
        storedState = nullptr;
    }
    else {
        cerr << "Invalid initial state!";
        return;
    }

    InputManager &im = InputManager::getInstance();

    CalculateDeltaTime();

    while (!stateStack.empty() && !stateStack.top()->getQuitRequested() && !gameQuitRequested) {


        CalculateDeltaTime();

        im.Update();
        stateStack.top()->update(getDeltaTime());
        stateStack.top()->render();
        SDL_RenderPresent(renderer);

        if (stateStack.top()->getPopRequested()) {
            stateStack.pop();
            stateStack.top()->resume();
        }

        if (storedState) {
            stateStack.top()->pause();
            stateStack.emplace(&(*storedState));
            storedState = nullptr;

        }
        SDL_Delay(33);
    }

    Resources::clearImages();
}

void Game::CalculateDeltaTime() {

    unsigned int tmp = frameStart;
    frameStart = SDL_GetTicks();
    dt = max((frameStart - tmp) / 1000.0, 0.001);

}

float Game::getDeltaTime() {
    return dt;
}

Vec2 Game::getScreenDimensions() {
    return Vec2(screenWidth, screenHeight);
}

void Game::push(State *state) {

    storedState = state;

}

void Game::requestQuit() {
    gameQuitRequested = true;
}
