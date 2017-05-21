#include "InputManager.hpp"
#include "Game.hpp"
#include "StageState.hpp"
#include "EndState.hpp"
#include "Defines.hpp"

EndState::EndState(StateData stateData)  {

    if (stateData.playerVictory){
        bg.open("img/win.jpg");
        music.open("audio/endStateWin.ogg");
    }else{
        bg.open("img/lose.jpg");
        music.open("audio/endStateLose.ogg");
    }

    instruction.setPos(300, 500, false, false);


}

void EndState::update(float dt) {

    InputManager &im = InputManager::getInstance();

    if (im.keyPress(ESCAPE_KEY)){
        popRequested = true;
    }
    if (im.keyPress(SPACE_BAR)){
        popRequested = true;

        Game::GetInstance().push(new StageState());
    }

}

void EndState::render() {

    bg.Render(0, 0, 0);

    instruction.render();
}

void EndState::pause() {

}

void EndState::resume() {

}
