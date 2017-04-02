#include <iostream>
#include "GameException.h"
#include "Game.h"
#include "CommandLineParser.h"
#include "GameException.h"
#include "GameConfig.h"
#include "Logger.h"

using namespace std;

int main(int argc, char **argv) {
    Logger::log("Game Starting...");

    CommandLineParser clp;

    clp.addBoolArg("debug", false, false);

    clp.parseCommandLine(argc, argv);

    GameConfig::setDebugMode(clp.getBoolVal("debug"));

    try {

        Game g = Game("Juarez Aires 11/0032829", 1024, 600);
        g.Run();

    }catch(GameException e){
        Logger::log("Error!");
        Logger::log(e.what());
    }catch(exception e){
        Logger::log("Error!");
        Logger::log(e.what());
    }


    Logger::log("Game Over...");
    return 0;
}
