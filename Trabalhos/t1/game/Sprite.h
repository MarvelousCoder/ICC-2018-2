//
// Created by jasf on 3/17/16.
//

#ifndef IDJ201601T1_SPRITE_H
#define IDJ201601T1_SPRITE_H


#include <string>
#include <SDL_rect.h>
#include <SDL_render.h>

using namespace std;

#include <SDL.h>
#include <SDL_image.h>

class Sprite {

protected:

    int width, height;
    //clipping rectangle: determine part of the image that is rendered
    SDL_Rect clipRect;
    //the image itself
    SDL_Texture *texture;

public:

    Sprite();

    Sprite(string filename);

    virtual ~Sprite();

    void Open(string filename);

    void SetClip(int x, int y, int w, int h);

    void Render(int x, int y);

    bool IsOpen();

    int GetWidth() const;

    int GetHeight() const;

    SDL_Texture* getTexture();





};


#endif //IDJ201601T1_SPRITE_H
