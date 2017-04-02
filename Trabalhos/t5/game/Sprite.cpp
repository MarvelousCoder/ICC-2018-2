//
// Created by jasf on 3/17/16.
//

#include <iostream>
#include "Game.h"
#include "GameException.h"
#include "Sprite.h"
#include "Resources.h"
#include <GameConfig.h>

int Sprite::getWidth() const {
    return width*scaleX;
}

int Sprite::getHeight() const {
    return height*scaleY;
}

SDL_Texture *Sprite::getTexture(){
    return texture;
}


bool Sprite::isOpen() {
    return texture != nullptr;
}

Sprite::Sprite() {
    construct();
}

Sprite::Sprite(string filename) {
    construct();
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

void Sprite::render(int x, int y, float angle) {
    SDL_Rect dstrec;
    dstrec.x = x;
    dstrec.y = y;
    dstrec.w = clipRect.w * scaleX;
    dstrec.h = clipRect.h * scaleY;

    SDL_RenderCopyEx(Game::getInstance().GetRenderer(), texture, &clipRect, &dstrec, angle*180.0/M_PI, nullptr, SDL_FLIP_NONE);

    if (GameConfig::debugMode)
        SDL_RenderPresent(Game::getInstance().GetRenderer());

}

void Sprite::setScaleX(float scale) {
    scaleX = scale;

}

void Sprite::setScaleY(float scale) {
    scaleY = scale;

}

void Sprite::construct() {
    texture = nullptr;
    scaleX = 1.0;
    scaleY = 1.0;

}
