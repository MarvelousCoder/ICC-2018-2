#include <SDL.h>
#include <SDL_mixer.h>
#include "Sound.hpp"
#include "Game.hpp"
#include "Resources.hpp"

Sound::Sound() {

}

Sound::Sound(std::string file) {

}

void Sound::play(int times) {
    if (chunk)
        channel = Mix_PlayChannel(-1, chunk, times);
    else{
        std::cerr << "Trying to playan unnoped chunk" << std::endl;
        Game::GetInstance().requestQuit();
    }


}

void Sound::stop() {

    Mix_HaltChannel(channel);

}

void Sound::open(std::string file) {

    chunk = Resources::getSound(file);

}

bool Sound::isOpen() {
    return false;
}
