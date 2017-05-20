#include "Alien.hpp"
#include "InputManager.hpp"
#include "Camera.hpp"
#include <SDL.h>
#include "Bullet.hpp"
#include "Game.hpp"
#include "Animation.hpp"

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
int Alien::alientCount = 0;
float Alien::alienCoolDownTime = 1.5;

Alien::Alien(float x, float y, int nMinions) {
    alientCount++;
    hp = 100;
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
        minionArray.push_back(new Minion(this, offset));
        offset += 2 * M_PI / nMinions;
    }

    state = AlientState::RESTING;
    restTimer.restart();
}

Alien::~Alien() {
    for (int i = 0; i < minionArray.size(); i++)
        delete minionArray[i];
    minionArray.clear();
    alientCount--;
}

void Alien::update(float dt) {
    auto im = InputManager::getInstance();

    switch (state) {
        case (AlientState::RESTING):
            restTimer.update(dt);
            if (restTimer.get() > alienCoolDownTime) {
                GameObject *playerPtr = Camera::getPlayer();

                if (playerPtr != nullptr) {
                    destination = playerPtr->getCenterPos();

                    speed = (destination - pos).getNormalizedVector() * VELOCITY_CONST;
                    state = AlientState::MOVING;

                }
            }

            break;
        case (AlientState::MOVING):
            if ((destination - pos).magnitude() < 5) {
                pos = destination;
                speed = Vec2(0, 0);

                GameObject *player = Camera::getPlayer();

                if (player) {
                    Vec2 shotTarget = player->getCenterPos();
                    float target_angle = (shotTarget - this->getCenterPos()).ang_rad();
                    //find minion closest to target point
                    int idx = 0;
                    float min = 2 * M_PI;
                    float x;
                    for (int i = 0; i < minionArray.size(); i++) {
                        x = abs((minionArray[i]->getCenterPos() - this->getCenterPos()).ang_rad() - target_angle);
                        if (x < min) {
                            idx = i;
                            min = x;
                        }

                    }

                    minionArray[idx]->shoot(shotTarget);
                    restTimer.restart();
                    state = AlientState::RESTING;

                }
            }
            else {
                pos += speed * dt;
            }

            box.setLT(pos + center_LT_displacement);

            break;
        default:
            std::cout<< "Invalid alien state!\n";
            break;
    }
    rotation += angular_velocity * dt;

    for (int i = 0; i < minionArray.size(); i++)
        minionArray[i]->update(dt);
}

void Alien::render() {
    Vec2 c = pos - Camera::getPos(Camera::PLAYER_GROUND_VIEW) + center_LT_displacement;
    sp.Render(c.x, c.y, rotation);

    for (int i = 0; i < minionArray.size(); i++)
        minionArray[i]->render();
}

bool Alien::isDead() {
    return hp <= 0;
}

void Alien::notifyCollision(GameObject &other) {
    if (other.is("Bullet") && !((Bullet &) other).getTargetsPlayer()) {
        damage(10);
    }
}

bool Alien::is(std::string type) {
    return type == "Alien";
}

void Alien::damage(int dm) {
    hp -= dm;

    if (hp <= 0) {
        static float step = 0.1;
        static int frameCount = 4;
        static int repeat = 3;

        Game::GetInstance().GetState().AddObject(
                   new Animation(pos.x, pos.y, 0, "img/aliendeath.png", repeat*step*frameCount, true, frameCount, step));
    }
}
