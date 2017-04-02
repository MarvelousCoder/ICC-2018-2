//
// Created by jasf on 3/23/16.
//

#ifndef IDJ201601T1_FACE_H
#define IDJ201601T1_FACE_H


#include <Sprite.h>
#include "GameObject.h"

class Face : public GameObject{

protected:
    int hitpoints;
    Sprite sp;
    Vec2 currentPos;

    void construct(float x, float y);

    static std::vector<std::string> angryMsgs;
    static std::vector<std::string> eliminatedMsgs;
    static unsigned int angryMsgIdx;
    static unsigned int eliminatedMsgIdx;

    static std::string getNextAngryMsg();
    static std::string getNextEliminatedMsg();

public:
    /***
     * x and y are the coordinates of the center
     */
    Face(float x, float y);
    Face(Vec2 pos);
    void Damage(int damage);
    void update(float dt);
    void render();
    bool isDead();


};


#endif //IDJ201601T1_FACE_H
