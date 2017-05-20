#include "Sprite.hpp"
#include "Game.hpp"
#include <iostream>
#include "Resources.hpp"
#define PI 3.14159265358979323846

using std::cout;
Sprite::Sprite() {
    texture = nullptr;
    scaleX = 1.0;
    scaleY = 1.0;
}

Sprite::Sprite(string file) {
    construct();
    open(file);
}

void Sprite::construct() {
    texture = nullptr;
    scaleX = 1.0;
    scaleY = 1.0;

}


Sprite::~Sprite() {
    // texture agora tratará de desalocações
}

bool Sprite::IsOpen() {
    return texture != nullptr;
}

int Sprite::GetWidth() {
    return width*scaleX;
}

int Sprite::GetHeight() {
    return height*scaleY;
}

void Sprite::open(string file) {
    texture = Resources::getImage(file);

    if (!texture) {
        cout << SDL_GetError() << endl;
    }

    SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
    SetClip(0, 0, width, height);
}

void Sprite::SetClip(int x, int y, int w, int h) {
    clipRect.x = x;
    clipRect.y = y;
    clipRect.w = w;
    clipRect.h = h;
}

void Sprite::Render(int x, int y, float angle) {
    SDL_Rect dstrec;
    dstrec.x = x;
    dstrec.y = y;
    dstrec.w = clipRect.w;
    dstrec.h = clipRect.h;
    SDL_RenderCopyEx(Game::GetInstance().GetRenderer(), texture, &clipRect, &dstrec, angle*180.0/PI, nullptr, SDL_FLIP_NONE);
}


void Sprite::setScaleX(float scale) {
    scaleX = scale;
}

void Sprite::setScaleY(float scale) {
    scaleY = scale;
}

SDL_Texture *Sprite::getTexture(){
    return texture;
}
