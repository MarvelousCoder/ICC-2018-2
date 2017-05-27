#ifndef TITLESTATLEHPP
#define TITLESTATEHPP

#include "State.hpp"
#include "Sprite.hpp"
#include "Text.hpp"
#include "Timer.hpp"

class TitleState : public State {

private:
    Sprite bg;
    Text infoText;
    bool shouldDisplayInfoText;
    Timer timer;

public:
    TitleState();
    void update(float);
    void render();
    void pause();
    void resume();
};
#endif // TITLESTATLEHPP
