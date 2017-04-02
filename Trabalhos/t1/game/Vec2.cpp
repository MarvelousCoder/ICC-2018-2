//
// Created by jasf on 3/22/16.
//

#include "Vec2.h"

Vec2::Vec2() : x(0), y(0) {

}

Vec2::Vec2(float x, float y) : x(x), y(y) {

}

Vec2::Vec2(const Vec2 &a){
    x = a.x;
    y = a.y;
}

Vec2 &Vec2::operator=(Vec2 arg) {
    if (this == &arg)
        return *this;

    x = arg.x;
    y = arg.y;
    return *this;

}

Vec2 &Vec2::operator+=(const Vec2 &rhs) {
    this->x += rhs.x;
    this->y += rhs.y;
    return *this;
}

Vec2 &Vec2::operator-=(const Vec2 &rhs) {
    this->x -= rhs.x;
    this->y -= rhs.y;
    return *this;
}

Vec2 Vec2::operator+(const Vec2 &rhs) const {
    Vec2 out(*this);
    out += rhs;

    return out;
}

Vec2 Vec2::operator-(const Vec2 &rhs) const {
    Vec2 out(*this);
    out -= rhs;

    return out;
}

std::ostream &operator<<(std::ostream &os, const Vec2 &obj) {
    // write obj to stream
    os << "(" << obj.x << "," << obj.y << ")";
    return os;
}

std::ostream &operator<<(std::ostream &os, Vec2 &obj) {
    // write obj to stream
    os << "(" << obj.x << "," << obj.y << ")";
    return os;
}

bool operator==(const Vec2 &lhs, const Vec2 &rhs) {
    return lhs.x == rhs.x && lhs.y == rhs.y;
}

Vec2 operator*(const Vec2 &lhs, const float &c) {
    Vec2 out(lhs.x, lhs.y);
    out.x *= c;
    out.y *= c;
    return out;
}

Vec2 operator* (const float &c, const Vec2 &rhs) {
    return rhs * c;
}

float Vec2::magnitude(){
    return std::sqrt(x*x + y*y);
}
Vec2 Vec2::getNormalizedVector(){
    Vec2 out(*this);
    out = out * (1.0/out.magnitude());
    return out;
}

float distanceBetweenPoints(const Vec2 &a, const Vec2 &b){
    return (a - b).magnitude();
}

float Vec2::ang_rad(){
    return atan2(y, x);
}
float Vec2::ang_deg(){
    return ang_rad() * 180.0 / M_PI;
}
