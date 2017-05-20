#include "Camera.hpp"
#include "Game.hpp"
#include "InputManager.hpp"

#include <SDL.h>
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
#define M_PI 3.14159265358979323846
#define M_PI_2 1.57079632679489661923

GameObject *Camera::focus = nullptr;

Vec2 Camera::speed(0, 0);
std::vector<Vec2> Camera::paralax_pos;
bool Camera::hasBenInitialized;
std::vector<float> Camera::paralax_sinsitivity;

int Camera::BACKGROUND_VIEW = 0;
int Camera::PLAYER_GROUND_VIEW = 1;
int Camera::TOPGROUND_VIEW = 2;

void Camera::Follow(GameObject *newFocus) {
    focus = newFocus;
    paralax_pos[Camera::PLAYER_GROUND_VIEW] = -1*Game::GetInstance().getScreenDimensions() * 0.5 + focus->getCenterPos();
}

void Camera::Unfollow() {
    focus = nullptr;
}

void Camera::Update(float dt) {
    if (focus != nullptr) {
        Vec2 newPos = -1*Game::GetInstance().getScreenDimensions() * 0.5  + focus->getCenterPos();
        Vec2 ds = newPos - paralax_pos[Camera::PLAYER_GROUND_VIEW];

        for (unsigned int k = 0; k < paralax_pos.size(); k++)
            paralax_pos[k] = paralax_pos[k] + paralax_sinsitivity[k] * ds;
    }
    else {

        const float camera_sensitivity = 400.0;

        speed = Vec2(0, 0);

        if (InputManager::getInstance().isKeyDown(LEFT_ARROW_KEY)) {
            speed += Vec2::getVec2FromPolar(camera_sensitivity, 0);
        }
        if (InputManager::getInstance().isKeyDown(RIGHT_ARROW_KEY)) {
            speed += Vec2::getVec2FromPolar(camera_sensitivity, -1 * M_PI);
        }
        if (InputManager::getInstance().isKeyDown(UP_ARROW_KEY)) {
            speed += Vec2::getVec2FromPolar(camera_sensitivity, M_PI_2);
        }
        if (InputManager::getInstance().isKeyDown(DOWN_ARROW_KEY)) {
            speed += Vec2::getVec2FromPolar(camera_sensitivity, -1 * M_PI_2);
        }

        for (unsigned int k = 0; k < paralax_pos.size(); k++)
            paralax_pos[k] =  paralax_pos[k] + paralax_sinsitivity[k] * dt * speed;
    }
}

void Camera::setLvsOfParalax(unsigned int k, std::vector<float> sensitivities) {
    if (hasBenInitialized)
        cout << "levels of paralax já foram setadas";
    if (sensitivities.size() != k)
        cout << "Vetor com sensitivity precisa ter tamanho k!";
    paralax_pos.clear();
    for (unsigned int i = 0; i < k; i++)
        paralax_pos.emplace_back(0, 0);
    paralax_sinsitivity.clear();
    for (unsigned int i = 0; i < k; i++)
        paralax_sinsitivity.push_back(sensitivities[i]);
    hasBenInitialized = true;

}

Vec2 Camera::getPos(unsigned int k) {
    if (k > paralax_pos.size())
        cout << "Invalid paralax lv!";

    return paralax_pos[k];
}

GameObject *Camera::getPlayer() {
    return focus;
}
