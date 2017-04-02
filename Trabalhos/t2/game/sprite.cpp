//
// Created by jasf on 3/17/16.
//

#include <iostream>
#include "Game.h"
#include "GameException.h"
#include "Sprite.h"

int Sprite::GetWidth() const {
    return width;
}

int Sprite::GetHeight() const {
    return height;
}

SDL_Texture *Sprite::getTexture(){
    return texture;
}


bool Sprite::IsOpen() {
    return texture != nullptr;
}

Sprite::Sprite() {
    texture = nullptr;
}

Sprite::Sprite(string filename) {
    texture = nullptr;
    Open(filename);
}

Sprite::~Sprite() {
    if (texture)
        SDL_DestroyTexture(texture);

}

void Sprite::Open(string filename) {
    if (texture)
        SDL_DestroyTexture(texture);

    texture = IMG_LoadTexture(Game::GetInstance().GetRenderer(), filename.c_str());

    if (!texture) {
        string msg = SDL_GetError();
        msg = "Error while loading texture on file " + filename + "\n" + msg;
        throw GameException(msg);
    }

    int attempts_left = 5;
     while((SDL_QueryTexture(texture, nullptr, nullptr, &width, &height) < 0) && attempts_left > 0){
         std::cerr << SDL_GetError() << std::endl;
         attempts_left --;
     }

    SetClip(0, 0, width, height);
}

void Sprite::SetClip(int x, int y, int w, int h) {
    clipRect.x = x;
    clipRect.y = y;
    clipRect.w = w;
    clipRect.h = h;
}

void Sprite::Render(int x, int y) {
    SDL_Rect dstrec;
    dstrec.x = x;
    dstrec.y = y;
    dstrec.w = clipRect.w;
    dstrec.h = clipRect.h;

    SDL_RenderCopy(Game::GetInstance().GetRenderer(), texture, &clipRect, &dstrec);
}

