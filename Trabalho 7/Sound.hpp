#ifndef SOUNDHPP
#define SOUNDHPP

#include <string>
#include <iostream>

#include <SDL.h>
#include <SDL_mixer.h>

class Sound {
    Mix_Chunk *chunk;
    int channel;
public:
    Sound();

    Sound(std::string file);

    void play(int times);

    void stop();

    void open(std::string file);

    bool isOpen();
};

#endif // SOUNDHPP
