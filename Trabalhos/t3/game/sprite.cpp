//
// Created by jasf on 3/17/16.
//

#include <Game.h>
#include <GameException.h>
#include <iostream>
#include "Sprite.h"
#include "Resources.h"
#include <GameConfig.h>

int Sprite::getWidth() const {
    return width;
}

int Sprite::getHeight() const {
    return height;
}

SDL_Texture *Sprite::getTexture(){
    return texture;
}


bool Sprite::isOpen() {
    return texture != nullptr;
}

Sprite::Sprite() {
    texture = nullptr;
}

Sprite::Sprite(string filename) {
    texture = nullptr;
    open(filename);
}

Sprite::~Sprite() {
    //texture is now free by resources

}

void Sprite::open(string filename) {
    texture = Resources::getImage(filename);


    int attempts_left = 5;
     while((SDL_QueryTexture(texture, nullptr, nullptr, &width, &height) < 0) && attempts_left > 0){
         std::cerr << SDL_GetError() << std::endl;
         attempts_left --;
     }

    setClip(0, 0, width, height);
}

void Sprite::setClip(int x, int y, int w, int h) {
    clipRect.x = x;
    clipRect.y = y;
    clipRect.w = w;
    clipRect.h = h;
}

void Sprite::render(int x, int y) {
    SDL_Rect dstrec;
    dstrec.x = x;
    dstrec.y = y;
    dstrec.w = clipRect.w;
    dstrec.h = clipRect.h;

    SDL_RenderCopy(Game::GetInstance().GetRenderer(), texture, &clipRect, &dstrec);

    if (GameConfig::debugMode)
        SDL_RenderPresent(Game::GetInstance().GetRenderer());

}

