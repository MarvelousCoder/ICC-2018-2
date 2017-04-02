//
// Created by jasf on 4/21/16.
//

#ifndef IDJ201601T1_ALIEN_H
#define IDJ201601T1_ALIEN_H


#include <queue>
#include "GameObject.h"
#include "Sprite.h"
#include "Minion.h"

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


#endif //IDJ201601T1_ALIEN_H
