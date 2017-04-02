//
// Created by jasf on 3/23/16.
//

#ifndef IDJ201601T1_TESTUTIL_H
#define IDJ201601T1_TESTUTIL_H

#include "Vec2.h"

#include <iostream>
#include <cassert>
#include <cmath>
#include <boost/assert.hpp>

#define assert_equals(expected, got) BOOST_ASSERT_MSG(abs(expected - got) < ASSER_EQUALS_DOUBLE_TOLERANCE, (boost::format("Should be %f is %f") % expected % got).str().c_str());

#include <boost/format.hpp>

#define ASSER_EQUALS_DOUBLE_TOLERANCE 1e-6

#define assert_equals_float(expected, got) (BOOST_ASSERT_MSG(abs(expected - got) < ASSER_EQUALS_DOUBLE_TOLERANCE, (boost::format("Should be %f is %f") % expected % got).str().c_str()));

#define assert_equals_vec2(expected, got) (BOOST_ASSERT_MSG(expected == got, (boost::format("Should be %f is %f") % expected % got).str().c_str()));

#define assert_true(got) (BOOST_ASSERT_MSG(got, (boost::format("Should be true!")).str().c_str()))


#endif //IDJ201601T1_TESTUTIL_H
