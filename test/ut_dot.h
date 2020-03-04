#include "../src/dot.h"
#include <gtest/gtest.h>
TEST(Math, dot) {
    double u[2] = {1, 0};
    double v[2] = {1, 1};
    ASSERT_EQ(1, dot(u, 2, v, 2));
}