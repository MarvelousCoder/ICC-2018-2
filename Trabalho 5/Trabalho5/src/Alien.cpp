#include "Alien.hpp"
#include "InputManager.hpp"
#include "Camera.hpp"
#include <SDL.h>
#define LEFT_ARROW_KEY SDLK_LEFT
#define RIGHT_ARROW_KEY SDLK_RIGHT
#define UP_ARROW_KEY SDLK_UP
#define DOWN_ARROW_KEY SDLK_DOWN
#define ESCAPE_KEY SDLK_ESCAPE
#define LEFT_MOUSE_BUTTON SDL_BUTTON_LEFT
#define RIGHT_MOUSE_BUTTON SDL_BUTTON_RIGHT
#define SPACE_BAR SDLK_SPACE
#define PI_4 0.785398163397448309616
#define PI 3.14159265358979323846

float Alien::VELOCITY_CONST = 150;

Alien::Alien(float x, float y, int nMinions) {
    hp = 20;
    angular_velocity = -1 * PI_4;
    sp.open("img/alien.png");

    int width = sp.GetWidth();
    int height = sp.GetHeight();

    pos = Vec2(x, y);
    speed = Vec2::getVec2FromPolar(0, 0);
    center_LT_displacement = -1 * Vec2(64, 79);

    box = Rect(Vec2(x, y) + center_LT_displacement, height, width);

    float offset = 0;
    for (int i = 0; i < nMinions; i++) {
        minionArray.emplace_back(this, offset);
        offset += 2 * PI / nMinions;
    }

}

Alien::~Alien() {

}

void Alien::update(float dt) {
    auto im = InputManager::getInstance();

    if (im.mousePress(RIGHT_MOUSE_BUTTON)) {
        this->taskQueue.emplace(Action::ActionType::MOVE, im.getMouse() - Camera::getPos(1));
    }
    if (im.mousePress(LEFT_MOUSE_BUTTON)) {
        this->taskQueue.emplace(Action::ActionType::SHOOT, im.getMouse() - Camera::getPos(1));
    }

    if (!taskQueue.empty()) {
        Action &a = taskQueue.front();

        if (a.type == Action::ActionType::MOVE) {
            if ((a.pos - pos).magnitude() < 5) {
                pos = a.pos;
                speed = Vec2(0, 0);
                taskQueue.pop();
            }
            else
                speed = (a.pos - pos).getNormalizedVector() * Alien::VELOCITY_CONST;

        }
        else if (a.type == Action::ActionType::SHOOT) {
            //find minion closest to target point
            float target_angle = (a.pos - this->getCenterPos()).ang_rad();
            int idx = 0;
            float min = 2 * PI;
            float x;
            for (int i = 0; i < minionArray.size(); i++) {
                x = abs((minionArray[i].getCenterPos() - this->getCenterPos()).ang_rad() - target_angle);
                if (x < min) {
                    idx = i;
                    min = x;
                }
            }

            minionArray[idx].shoot(a.pos);
            taskQueue.pop();
        }

    }

    pos += speed * dt;

    rotation += angular_velocity * dt;

    for (vector<Minion>::iterator m = minionArray.begin(); m != minionArray.end(); m++)
        m->update(dt);
}

void Alien::render() {
    Vec2 c = pos + Camera::getPos(1) + center_LT_displacement;
    sp.Render(c.x, c.y, rotation);

    for (vector<Minion>::iterator m = minionArray.begin(); m != minionArray.end(); m++)
        m->render();


}

bool Alien::isDead() {
    return hp <= 0;
}

Alien::Action::Action(Alien::Action::ActionType type, float x, float y) :
        type(type), pos(x, y) { }

Alien::Action::Action(Alien::Action::ActionType type, Vec2 pos) : type(type),
                                                                  pos(pos) {

}

