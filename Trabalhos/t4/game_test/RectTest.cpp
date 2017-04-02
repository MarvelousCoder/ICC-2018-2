//
// Created by jasf on 3/23/16.
//

#include "Rect.h"
#include "Vec2.h"
#include "TestUtil.h"

#include <vector>


void test_basic_right() {

    Rect r(0,0,1,1);
    Rect m(1,0,1,1);

    std::vector<Vec2> corners = r.getCorners();

    assert_equals_vec2( Vec2(0,0), corners[0]);
    assert_equals_vec2( Vec2(0,1), corners[1]);
    assert_equals_vec2( Vec2(1,1), corners[2]);
    assert_equals_vec2( Vec2(1,0), corners[3]);

    assert_equals_vec2( Vec2(0.5,0.5), r.getCenter());

    assert_equals_float( 1.0, Rect::distanceFromRectCenters(r, m));

    //test for outer points
    std::vector<Vec2> p_out = {Vec2(2,0), Vec2(1, 1.1), Vec2(-1, 0)};
    for(auto p : p_out)
        assert_true(!r.isPointInside(p));

    //test for inner points (inclusing extremities)
    std::vector<Vec2> p_in;
    for (int i = 0 ; i <= 20; i++ )
        for (int j = 0 ; j <= 20; j++ )
            p_in.push_back(Vec2(1/20.0*i, 1/20.0*j));

    for(auto p : p_in)
        assert_true(r.isPointInside(p));


}

int main() {

    test_basic_right();
}

