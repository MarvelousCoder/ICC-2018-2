//
// Created by jasf on 3/25/16.
//

#ifndef IDJ201601T1_INPUTMANAGER_H
#define IDJ201601T1_INPUTMANAGER_H

#define INPUT_MANAGER_MOUSE_STATE_SIZE 6

#import <unordered_map>

class InputManager {
private:
    InputManager();
    ~InputManager();

    bool mouseState[INPUT_MANAGER_MOUSE_STATE_SIZE];
    int mouseUpdate[INPUT_MANAGER_MOUSE_STATE_SIZE];

    std::unordered_map<int, bool> keyState;
    std::unordered_map<int, int> keyUpdate;

    bool quitRequested;

    int updateCounter;

    int mouseX;
    int mouseY;


public:
    void update();

    bool keyPress(int key);
    bool keyRelease(int key);
    bool isKeyDown(int key);

    bool mousePresse(int button);
    bool mouseRelease(int button);
    bool isMouseDown(int button);

    int getMouseX();
    int getMouseY();

    bool getQuitRequested();

    static InputManager& getInstance();





};


#endif //IDJ201601T1_INPUTMANAGER_H
