#ifndef SPRITEHPP
#define SPRITEHPP

#include <SDL.h>
#include <string>
#include <SDL_rect.h>
#include <SDL_render.h>
#include <SDL_image.h>
#include "Vec2.hpp"
using namespace std;

class Sprite{
protected:
    SDL_Texture* texture;
    SDL_Rect clipRect, dst_rect;
    SDL_Point *center;

    int width;
    int height;

    float scaleX, scaleY;
    float timeElapsed, frameTime;

    int frameCount, currentFrame;
    int frameWidth, frameHeight;

    void construct(int frameCount, float frameTime);
public:
    Sprite();
    Sprite(const Sprite &sp);
    Sprite(string file, int frameCount = 1, float frameTime = 1.0);
    virtual ~Sprite();

    void open(string file);
    void setCenter(Vec2 c);
    void SetClip(int x, int y, int w, int h);
    void Render(int x, int y, float angle = 0);

    int GetWidth() const;
    int GetHeight() const;
    Vec2 getDimensions() const;
    bool IsOpen();
    SDL_Texture *getTexture();

    void setScaleX(float scale);

    void setScaleY(float scale);

    void update(float dt);

    void setFrame(int frame);
    void incFrame();

    void setFrameCount(int frameCount);
    void setFrameTime(float frameTime);

    int getFrameWidth();
};

#endif
