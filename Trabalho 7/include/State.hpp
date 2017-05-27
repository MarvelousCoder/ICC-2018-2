#ifndef STATEHPP
#define STATEHPP

#include "GameObject.hpp"
#include <memory>

class State {
protected:
    bool popRequested, quitRequested;
    std::vector <std::unique_ptr<GameObject>> objectArray;
public:
    void AddObject(GameObject *obj);
    State();
    virtual ~State();

    virtual void update(float dt) = 0;
    virtual void render() = 0;
    virtual void pause() = 0;
    virtual void resume() = 0;

    bool getPopRequested();
    bool getQuitRequested();
    virtual void updateArray(float dt);
    virtual void renderArray();
};

#endif
