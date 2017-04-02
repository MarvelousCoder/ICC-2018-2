#ifndef SPRITEHPP
#define SPRITEHPP

#include "SDL.h"
#include <string>
#include "SDL_rect.h"
#include "SDL_render.h"
#include "SDL_image.h"
using namespace std;

class Sprite{
    SDL_Texture* texture;
    int width;
    int height;
    SDL_Rect clipRect;
public:
    Sprite();
    Sprite(string file);
    ~Sprite();
    void open(string file);
    void SetClip(int x, int y, int w, int h);
    void Render(int x, int y);
    int GetWidth();
    int GetHeight();
    bool IsOpen();
};

#endif