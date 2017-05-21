#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

#include "Game.hpp"
#include "StageState.hpp"
#include "TitleState.hpp"

using namespace std;

int main(int argc, char **argv) {
    cout << "Starting Game..." << endl;
    Game g = Game("Raphael Soares 14/0160299", 1024, 600);
    g.push(new TitleState());
    g.Run();
    cout << "Game Over..." << endl;
    return 0;
}
