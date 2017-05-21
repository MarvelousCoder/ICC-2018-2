#ifndef ENDSTATEHPP
#define ENDSTATEHPP

#include "Sprite.hpp"
#include "Music.hpp"
#include "Text.hpp"
#include "State.hpp"

typedef struct StateData {
    bool playerVictory;
} StateData;

class EndState : public State {
private:
    Sprite bg;
    Music music;
    Text instruction = Text("font/Call me maybe.ttf", 40, Text::TextStyle::BLENDED,
                            "Press space to restart and ESC to title screen", SDL_Color{255, 255, 0, 255}, 0, 0);

public:

    EndState(StateData stateData);

    void update(float dt);
    void render();

    void pause();
    void resume();

};

#endif // ENDSTATEHPP
