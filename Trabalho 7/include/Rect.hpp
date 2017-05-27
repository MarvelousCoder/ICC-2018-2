#ifndef RECTHPP
#define RECTHPP

#include "Vec2.hpp"
#include <vector>
#include <cmath>
#include <algorithm>

class Rect {
    bool hasBeenUpdated;
    std::vector<Vec2> corners;
    float rotation;
    void construct();
public:
    float x;
    float y;
    float w;
    float h;

    Rect(float x, float y, float w, float h);
    Rect();
    Rect(Vec2 LT, float h, float w);

    Vec2 getTopLeft();
    Vec2 getCenter() const;

    bool IsInside(const Vec2 & p);
    bool IsInside(const float& x, const float& y);

    std::vector<Vec2> getCorners();
    static double distanceFromRectCenters(const Rect & A, const Rect & B);
    void setLT(Vec2 lt);
    void setRotation(float rot);
};

#endif // RECTHPP
