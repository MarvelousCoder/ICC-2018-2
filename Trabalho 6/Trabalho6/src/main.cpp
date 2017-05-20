#include <iostream>
#include "Game.hpp"

using namespace std;

int main(int argc, char **argv) {
    cout << "Starting Game..." << endl;
    Game g = Game("Raphael Soares 14/0160299", 1024, 600);
    g.Run();
    cout << "Game Over..." << endl;
    return 0;
}
