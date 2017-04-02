//
// Created by jasf on 3/22/16.
//

#ifndef IDJ201601T1_VEC2_H
#define IDJ201601T1_VEC2_H

#include <iostream>
#include <cmath>

class Vec2 {
public:
    float x, y;

    Vec2();

    Vec2(float x, float y);

    Vec2(const Vec2 &a);

    Vec2 &operator=(Vec2 arg);

    Vec2 &operator+=(const Vec2 &rhs);

    Vec2 &operator-=(const Vec2 &rhs);

    Vec2 operator+(const Vec2 &rhs) const;

    Vec2 operator-(const Vec2 &rhs) const;

    float magnitude();

    Vec2 getNormalizedVector();

    float ang_rad();

    float ang_deg();



};

std::ostream &operator<<(std::ostream &os, const Vec2 &obj);

std::ostream &operator<<(std::ostream &os, Vec2 &obj);

bool operator==(const Vec2 &lhs, const Vec2 &rhs);

inline bool operator!=(const Vec2 &lhs, const Vec2 &rhs) { return !(lhs == rhs); }

Vec2 operator*(const Vec2 &lhs, const float &c);

Vec2 operator*(const float &c, const Vec2 &rhs);

float distanceBetweenPoints(const Vec2 &a, const Vec2 &b);

#endif //IDJ201601T1_VEC2_H
