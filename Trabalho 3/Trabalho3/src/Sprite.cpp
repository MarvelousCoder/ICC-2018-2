#include "Sprite.hpp"
#include "Game.hpp"
#include <iostream>
#include "Resources.hpp"

using std::cout;
Sprite::Sprite() {
    texture = nullptr;
}

Sprite::Sprite(string file) {
    texture = nullptr;
    open(file);
}

Sprite::~Sprite() {
    // texture agora tratará de desalocações
}

bool Sprite::IsOpen() {
    return texture != nullptr;
}

int Sprite::GetWidth() {
    return width;
}

int Sprite::GetHeight() {
    return height;
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

void Sprite::Render(int x, int y) {
    SDL_Rect dstrec;
    dstrec.x = x;
    dstrec.y = y;
    dstrec.w = clipRect.w;
    dstrec.h = clipRect.h;

    SDL_RenderCopy(Game::GetInstance().GetRenderer(), texture, &clipRect, &dstrec);
}
