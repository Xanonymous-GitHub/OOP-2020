#include "../src/dot.h"
#include <gtest/gtest.h>
TEST(InnerProduct, Dot1) {
    double u[] = {1, 0, 2, 9, 4, 5};
    double v[] = {1, 1, 3, 98, 21, 34};
    ASSERT_EQ(1143, dot(u, 6, v, 6));
}

TEST(InnerProduct, Dot2) {
    double u[] = {1, 0, 2, 9, 4, 5};
    double v[] = {1, 1, 3, 98, 21};
    try {
        dot(u, 6, v, 5);
    } catch (...) {
        ASSERT_TRUE(true);
    }
}