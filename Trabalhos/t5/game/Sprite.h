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

    float scaleX, scaleY;

    void construct();

public:

    Sprite();

    Sprite(string filename);

    virtual ~Sprite();

    void open(string filename);

    void setClip(int x, int y, int w, int h);

    void render(int x, int y, float angle = 0.0);

    bool isOpen();

    int getWidth() const;

    int getHeight() const;

    SDL_Texture *getTexture();

    void setScaleX(float scale);

    void setScaleY(float scale);


};


#endif //IDJ201601T1_SPRITE_H
