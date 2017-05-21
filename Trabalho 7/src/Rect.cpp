#include "Rect.hpp"

Rect::Rect(float x, float y, float h, float w): x(x), y(y), h(h), w(w){
    construct();
}

Rect::Rect(): x(-1), y(-1), h(-1), w(-1){
    construct();
}

Rect::Rect(Vec2 LT, float h, float w) : x(LT.x), y(LT.y), h(h), w(w) {
    construct();
}

void Rect::construct() {
    hasBeenUpdated = true;
}

void Rect::setLT(Vec2 lt) {
    x = lt.x;
    y = lt.y;
    hasBeenUpdated = true;

}


Vec2 Rect::getTopLeft(){
    Vec2 c = getCenter();
    return Vec2(x,y).rotatedAroundCenter(getCenter(), rotation);
}

Vec2 Rect::getCenter() const{
    return Vec2(x + w/2.0, y + h/2.0);
}

bool Rect::IsInside(const Vec2 & p) {
    auto vertices = getCorners();
    auto LT = vertices[0];
    auto RB = vertices[2];

    float xmin = std::min(LT.x, RB.x);
    float xmax = std::max(LT.x, RB.x);

    float ymin = std::min(LT.y, RB.y);
    float ymax = std::max(LT.y, RB.y);

    // works for axis aligned rectangle
    if (p.x < xmin || p.x > xmax || p.y < ymin || p.y > ymax) {
        return false;
    }
    return true;

}

bool Rect::IsInside(const float &x, const float &y) {
    return IsInside(Vec2(x,y));
}

std::vector<Vec2> Rect::getCorners() {
    if(hasBeenUpdated){
        corners.clear();
        hasBeenUpdated = false;
    }
    if(corners.empty()) {
        auto c = getCenter();
        corners.push_back((c + Vec2(-0.5*w, -0.5*h)).rotatedAroundCenter(c, rotation));
        //BL
        corners.push_back((c + Vec2(-0.5*w, +0.5*h)).rotatedAroundCenter(c, rotation));
        //BR
        corners.push_back((c + Vec2(+0.5*w, +0.5*h)).rotatedAroundCenter(c, rotation));
        //TR
        corners.push_back((c + Vec2(+0.5*w, -0.5*h)).rotatedAroundCenter(c, rotation));

    }
    return corners;
}

double Rect::distanceFromRectCenters(const Rect & A, const Rect & B){
    return Vec2::distanceBetweenPoints(A.getCenter(), B.getCenter());
}

void Rect::setRotation(float rot) {
    rotation = rot;
    hasBeenUpdated = true;
}
