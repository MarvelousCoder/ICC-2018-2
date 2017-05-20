#ifndef ALIENHPP
#define ALIENHPP

#include <queue>
#include "GameObject.hpp"
#include "Sprite.hpp"
#include "Minion.hpp"

class Alien : public GameObject {

private:
    class Action {
    public:
        enum ActionType {
            MOVE, SHOOT
        };

        Action(ActionType type, float x, float y);
        Action(ActionType type, Vec2 pos);


        ActionType type;
        Vec2 pos;

    };
    Sprite sp;
    Vec2 speed;
    Vec2 center_LT_displacement;
    static float VELOCITY_CONST;
    int hp;
    std::queue<Action> taskQueue;
    std::vector<Minion> minionArray;
    float angular_velocity;
public:
    Alien(float x, float y, int nMinions);
    virtual ~Alien();
    void update(float dt);
    void render();
    bool isDead();
};
#endif // ALIENHPP
