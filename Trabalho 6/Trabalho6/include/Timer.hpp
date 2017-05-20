#ifndef TIMERHPP
#define TIMERHPP

class Timer {
    float time;
public:
    Timer();
    void update(float dt);
    void restart();
    float get();
};
#endif // TIMERHPP
