#ifndef MUSICHPP
#define MUSICHPP

#include <SDL.h>
#include <SDL_mixer.h>
#include <string>

class Music {
    Mix_Music *music;
public:
    Music();

    Music(std::string file);

    void play(int times);

    void stop();

    void open(std::string fle);

    bool isOpen();

};


#endif // MUSICHPP
