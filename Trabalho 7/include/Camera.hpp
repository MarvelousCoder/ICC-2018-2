#ifndef CAMERAHPP
#define CAMERAHPP

#include "GameObject.hpp"

class Camera {
    static GameObject *focus;
    static Vec2 speed;
    static std::vector<Vec2> paralax_pos;
    static std::vector<float> paralax_sinsitivity;
    static bool hasBenInitialized;
public:
    static int BACKGROUND_VIEW;
    static int PLAYER_GROUND_VIEW;
    static int TOPGROUND_VIEW;

    static void setLvsOfParalax(unsigned int k, std::vector<float>);

    static void Follow (GameObject* newFocus);
    static void Unfollow();
    static void Update(float dt);

    static Vec2 getPos(unsigned int paralax_lv);

    static inline Vec2 getSpeed(){return speed;}
    static GameObject *getPlayer();
};

#endif // CAMERAHPP
