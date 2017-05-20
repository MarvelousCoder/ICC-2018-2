#include "Sprite.hpp"
#include "Game.hpp"
#include <iostream>
#include "Resources.hpp"
#define PI 3.14159265358979323846

using std::cout;
Sprite::Sprite() {
    construct(1, std::numeric_limits<float>::infinity());
}

Sprite::Sprite(string file, int frameCount, float frameTime) {
    construct(frameCount, frameTime);
    open(file);
}

void Sprite::construct(int frameCount,float frameTime) {
    texture = nullptr;
    scaleX = 1.0;
    scaleY = 1.0;

    currentFrame = 0;
    timeElapsed = 0.0;

    this->frameCount = frameCount;
    this->frameTime = frameTime;

    center = nullptr;
}

Sprite::~Sprite() {
    if (center != nullptr)
        delete center;
}

bool Sprite::IsOpen() {
    return texture != nullptr;
}

int Sprite::GetWidth() const{
    return width*scaleX;
}

int Sprite::GetHeight() const {
    return height*scaleY;
}

void Sprite::open(string file) {
    texture = Resources::getImage(file);

    if (!texture) {
        cout << SDL_GetError() << endl;
    }
    SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
    frameWidth = width / this->frameCount;
    frameHeight = height;
    SetClip(0, 0, frameWidth, height);
}

void Sprite::SetClip(int x, int y, int w, int h) {
    clipRect.x = x;
    clipRect.y = y;
    clipRect.w = w;
    clipRect.h = h;
}

void Sprite::Render(int x, int y, float angle) {
    dst_rect.x = x;
    dst_rect.y = y;
    dst_rect.w = clipRect.w * scaleX;
    dst_rect.h = clipRect.h * scaleY;

    if (center) {
        SDL_Point c;
        c.x = center->x * scaleX;
        c.y = center->y * scaleY;
        SDL_RenderCopyEx(Game::GetInstance().GetRenderer(), texture, &clipRect, &dst_rect, angle * 180.0 / M_PI, &c,
                         SDL_FLIP_NONE);
    } else {
        SDL_RenderCopyEx(Game::GetInstance().GetRenderer(), texture, &clipRect, &dst_rect, angle * 180.0 / M_PI,
                         nullptr,
                         SDL_FLIP_NONE);
    }
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

void Sprite::update(float dt) {
    timeElapsed += dt;

    if (timeElapsed > frameTime) {
        timeElapsed = 0.0;
        currentFrame = (currentFrame + 1) % frameCount;
        SetClip(currentFrame * frameWidth, 0, frameWidth, frameHeight);
    }
}

void Sprite::setFrame(int frame) {
    this->currentFrame = frame;
    if (frame >= frameCount)
        cout << "Frame idx greater than frame count\n";

    currentFrame = (frame) % frameCount;

    SetClip(currentFrame * frameWidth, 0, frameWidth, frameHeight);
}

void Sprite::incFrame() {
    setFrame((currentFrame + 1)%frameCount);
}

void Sprite::setFrameCount(int frameCount) {
    this->frameCount = frameCount;
}

void Sprite::setFrameTime(float frameTime) {
    this->frameTime = frameTime;
}

int Sprite::getFrameWidth() {
    return frameWidth;
}

Vec2 Sprite::getDimensions() const {
    return Vec2(width, height);
}

void Sprite::setCenter(Vec2 c) {
    if (center != nullptr)
        delete center;

    center = new SDL_Point();
    center->x = c.x;
    center->y = c.y;

}

Sprite::Sprite(const Sprite &sp) {
    texture = sp.texture;
    scaleX = sp.scaleX;
    scaleY = sp.scaleY;

    currentFrame = 0;
    timeElapsed = 0;

    this->frameCount = sp.frameCount;
    this->frameTime = sp.frameTime;

    this->center = sp.center;

    frameWidth = sp.width;
    frameHeight = sp.height;

    SetClip(0, 0, frameWidth, height);
}
