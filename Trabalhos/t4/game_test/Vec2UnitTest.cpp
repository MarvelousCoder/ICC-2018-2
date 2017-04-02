//
// Created by jasf on 3/22/16.
//
#include "Vec2.h"

#include <iostream>
#include <cassert>
#include <cmath>
#include <boost/assert.hpp>
#include <boost/format.hpp>

#include "TestUtil.h"

void test_overload_operators() {
    Vec2 a;
    Vec2 b(1, 0);
    Vec2 c(0, 1);
    Vec2 d;
    d = c + b;

    assert(a.x == 0);
    assert(a.y == 0);

    assert(b.x == 1);
    assert(b.y == 0);

    assert(d.x == 1);
    assert(d.y == 1);

    d += c;

    assert(d.x == 1);
    assert(d.y == 2);

    d -= c;

    assert(d.x == 1);
    assert(d.y == 1);

    Vec2 e = a + b + c;
    assert(e.x == 1);
    assert(e.y == 1);

    assert(Vec2(0, 0) == Vec2(0, 0));
    assert(Vec2(1, 0) != Vec2(0, 0));

    assert(Vec2(1, 2) * 2 == Vec2(2, 4));

    assert(Vec2::getVec2FromPolar(1, 0) == Vec2(1, 0));
    assert(Vec2::getVec2FromPolar(1, M_PI) == Vec2(-1, 0));
    assert(Vec2::getVec2FromPolar(1, M_PI_2) == Vec2(0, 1));

    assert(Vec2::directionOfLineThrough(Vec2(0,0), Vec2(1,0)) == 0);

    assert_equals_float(M_PI_2, Vec2::directionOfLineThrough(Vec2(0,0), Vec2(0,1)));

    assert_equals_float(M_PI_2, Vec2::directionOfLineThrough(Vec2(0,0), Vec2(0,1)));

    assert_equals_vec2(Vec2(-1,0), Vec2(0,1).rotated(M_PI_2));
    assert_equals_vec2(Vec2(0,-1), Vec2(-1,0).rotated(M_PI_2));
    assert_equals_vec2(Vec2(sqrt(2)/2.0,sqrt(2)/2.0), Vec2(1,0).rotated(M_PI_4));


}

void test_vec2_algebra(){
    assert(Vec2(1,0).magnitude() == 1);
    assert(Vec2(0,0).magnitude() == 0);

    assert(Vec2(1,1).magnitude() == (float)sqrt(2));

    assert(Vec2(10,0).getNormalizedVector() == Vec2(1,0));

    assert(Vec2::distanceBetweenPoints(Vec2(0,0), Vec2(1,1)) == (float)sqrt(2));

}


int main() {

    test_overload_operators();

    test_vec2_algebra();


    return 0;

}
