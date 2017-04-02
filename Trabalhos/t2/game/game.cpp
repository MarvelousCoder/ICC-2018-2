//
// Created by jasf on 3/15/16.
//

#include "Game.h"
#include "GameException.h"
#include <SDL_render.h>
#include <SDL_image.h>

#include <vector>
#include <algorithm>
#include <functional>
#include <map>


Game *Game::instance = nullptr;

Game::Game(string name, int width, int height) {
    srand(time(NULL));
    if (!instance) {
        instance = this;
    }

    //initialize SDL
    bool success = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) == 0;

    if (!success) {
        string error_msg(error_msg = SDL_GetError());
        error_msg = "Could not initialize SDL:\n" + error_msg;
        throw GameException(error_msg);
    }

    //initialize image module and check if process went OK
    map<int, string> code_name_map = {{IMG_INIT_TIF, "tif"},
                                      {IMG_INIT_JPG, "jpg"},
                                      {IMG_INIT_PNG, "png"}};
    vector<int> image_formats{IMG_INIT_TIF, IMG_INIT_JPG, IMG_INIT_PNG};
    //or between all desired formats
    int image_settings = accumulate(image_formats.begin(),
                                    image_formats.end(),
                                    0,
                                    [](const int &a, const int &b) {
                                        return a | b;
                                    }
    );
    int obtained_image_settings = IMG_Init(image_settings);
    if (image_settings != obtained_image_settings) {
        string error_msg_main = SDL_GetError();
        string error_msg = "Could not initiazlie image libary for type:";
        for (auto format : image_formats)
            if ((format & obtained_image_settings) == 0) {
                error_msg += code_name_map[format];
            }
        error_msg += "\n";
        error_msg = error_msg_main + error_msg;
        throw GameException(error_msg);
    }

    //create window for game

    window = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);

    if (!window)
        throw GameException("Could not load window!");

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (!renderer)
        throw GameException("Could not load renderer!");

    state = new State();

}


SDL_Renderer *Game::GetRenderer() {
    return this->renderer;
}

SDL_Window* Game::GetWindow(){
    return this->window;
}

Game &Game::GetInstance() {
    return *instance;
}

State &Game::GetState() {
    return *(this->state);
}

Game::~Game() {
    delete state;
    //shut img library down
    IMG_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    //shut sdl down
    SDL_Quit();

}

void Game::Run() {
    float dt = 0.1;

    while (!state->QuitRequested()) {

        state->Update(dt);
        state->Render();
        SDL_RenderPresent(renderer);

        SDL_Delay(33);



    }


}
