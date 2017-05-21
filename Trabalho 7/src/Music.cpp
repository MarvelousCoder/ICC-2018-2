#include <iostream>

#include "Music.hpp"
#include "Resources.hpp"
#include "Game.hpp"

Music::Music() : music(nullptr) {

}

Music::Music(std::string file) {

    open(file);

}

void Music::play(int times) {

    if (music)
        Mix_PlayMusic(music, times);
    else {
        std::cerr << "Calling play with invalid music" << std::endl;
    }

}

void Music::stop() {

    Mix_FadeOutMusic(500);

}

void Music::open(std::string fle) {

    music = Resources::getMusic(fle);

    if (music == nullptr){
        std::cerr << "Requesting quit because music could not be loaded!" << std::endl;
        Game::GetInstance().requestQuit();
    }

}

bool Music::isOpen() {
    return music != nullptr;
}
