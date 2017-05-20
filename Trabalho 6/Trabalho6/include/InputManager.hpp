#ifndef INPUTMANAGERHPP
#define INPUTMANAGERHPP

#import <SDL_keycode.h>
#import <unordered_map>
#define INPUT_MANAGER_MOUSE_STATE_SIZE 6
#define LEFT_ARROW_KEY SDLK_LEFT
#define RIGHT_ARROW_KEY SDLK_RIGHT
#define UP_ARROW_KEY SDLK_UP
#define DOWN_ARROW_KEY SDLK_DOWN
#define ESCAPE_KEY SDLK_ESCAPE
#define LEFT_MOUSE_BUTTON SDL_BUTTON_LEFT
#define RIGHT_MOUSE_BUTTON SDL_BUTTON_RIGHT
#define KEY_LOW_CASE_W SDLK_w
#define KEY_LOW_CASE_S SDLK_s
#define KEY_LOW_CASE_A SDLK_a
#define KEY_LOW_CASE_D SDLK_d
#define SPACE_BAR SDLK_SPACE
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
