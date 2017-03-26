#include "Vec2.hpp"

Vec2::Vec2() : x(0), y(0) {

}

Vec2::Vec2(float x, float y) : x(x), y(y) {

}

Vec2::Vec2(const Vec2 &a){
    x = a.x;
    y = a.y;
}

double Vec2::magnitude(){
    return std::sqrt(x*x + y*y);
}

double Vec2::distanceBetweenPoints(const Vec2 &a, const Vec2 &b){
    return std::sqrt(pow(b.x - a.x,2) + pow(b.y - a.y,2));
}

Vec2 Vec2::getVec2FromPolar(double mag, double theta){
    return Vec2(mag*cos(theta), mag * sin(theta));
}
Vec2 Vec2::rotated(double theta_rad){
    return Vec2(x * cos(theta_rad) - y*sin(theta_rad), y*cos(theta_rad) + x * sin(theta_rad));
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

Vec2 &Vec2::operator=(Vec2 arg) {
    if (this == &arg)
        return *this;

    x = arg.x;
    y = arg.y;
    return *this;

}

float Vec2::ang_rad(){
    return atan2(y, x);
}
float Vec2::ang_deg(){
    return ang_rad() * 180.0 / 3.14159265358979323846;
}
