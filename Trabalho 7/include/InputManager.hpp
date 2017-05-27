#ifndef INPUTMANAGERHPP
#define INPUTMANAGERHPP

#import <SDL_keycode.h>
#import <unordered_map>
#include "Defines.hpp"
#include "Vec2.hpp"

class InputManager {
    InputManager();
    bool mouseState[INPUT_MANAGER_MOUSE_STATE_SIZE];
    int mouseUpdate[INPUT_MANAGER_MOUSE_STATE_SIZE];
    std::unordered_map<int, bool> keyState;
    std::unordered_map<int, int> keyUpdate;
    bool quitRequested;
    int updateCounter;
    int mouseX;
    int mouseY;
public:
    virtual ~InputManager();
    void Update();
    bool keyPress(int key);
    bool keyRelease(int key);
    bool isKeyDown(int key);
    bool mousePress(int button);
    bool mouseRelease(int button);
    bool isMouseDown(int button);
    int getMouseX();
    int getMouseY();
    bool getQuitRequested();
    static InputManager& getInstance();
    Vec2 getMouse();
};

#endif // INPUTMANAGERHPP
