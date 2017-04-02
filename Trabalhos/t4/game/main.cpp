#include <iostream>
#include "GameException.h"
#include "Game.h"
#include "CommandLineParser.h"
#include "GameException.h"
#include "GameConfig.h"

using namespace std;

int main(int argc, char **argv) {
    cout << "Game Starting..." << endl;

    CommandLineParser clp;

    clp.addBoolArg("debug", false, false);

    clp.parseCommandLine(argc, argv);

    GameConfig::setDebugMode(clp.getBoolVal("debug"));

    try {

        Game g = Game("Juarez Aires 11/0032829", 1024, 600);
        g.Run();

    }catch(GameException e){
        cout << "Error!" << endl;
        cout << e.what() << endl;
    }catch(exception e){
        cout << "Error!" << endl;
        cout << e.what() << endl;
    }


    cout << "Game Over..." << endl;
    return 0;
}
