#ifndef UT_VECTOR_H
#define UT_VECTOR_H

#include "../src/vector.h"

TEST(VECTOR, dim) {
    double d1[] = {1, 2}, d2[] = {1, 2, 3, 4};
    Vector v1, v2(d1, 2), v3(d2, 4);
    ASSERT_EQ(-1, v1.dim());
    ASSERT_EQ(2, v2.dim());
    ASSERT_EQ(4, v3.dim());
}

TEST(VECTOR, at) {
    double
        d1[] = {1, 2, 3, 4, 5, 6},
        d2[] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
    Vector v1(d1, 6), v2(d2, 7);
    for (int i = 0; i < 6; i++) {
        ASSERT_EQ(i + 1, v1.at(i + 1));
    }
    for (int i = 0; i < 7; i++) {
        ASSERT_EQ(d2[i], v2.at(i + 1));
    }
}

TEST(VECTOR, operatorPlus) {
    double
        d1[] = {1, 2, 3, 4, 5, 6},
        d2[] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7},
        d3[] = {-1, -2, -3, -4, -5, -6};
    Vector v3(d1, 6), v4(d2, 7), v5(d3, 6);
    Vector v3PlusV5 = v5 + v3;
    for (int i = 0; i < 6; i++) {
        ASSERT_EQ(0, v3PlusV5.at(i + 1));
    }
    ASSERT_ANY_THROW(v3 + v4);
}

TEST(VECTOR, operatorMinus) {
    double
        d1[] = {1, 2, 3, 4, 5, 6},
        d2[] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7},
        d3[] = {-1, -2, -3, -4, -5, -6};
    Vector v6(d1, 6), v7(d2, 7), v8(d3, 6);
    Vector v6PlusV8 = v6 - v8;
    for (int i = 0; i < 6; i++) {
        ASSERT_EQ(2 * (i + 1), v6PlusV8.at(i + 1));
    }
    ASSERT_ANY_THROW(v6 - v7);
}

TEST(VECTOR, length) {
    double d1[] = {3, 4}, d2[] = {7, 24};
    Vector v9(d1, 2), v10(d2, 2);
    ASSERT_EQ(5, v9.length());
    ASSERT_EQ(25, v10.length());
}

TEST(VECTOR, angle) {
    double d1[] = {3, 4}, d2[] = {7, 24};
    Vector v11(d1, 2), v12(d2, 2);
    ASSERT_NEAR(0.359707, v11.angle(v12), 0.001);
    double d3[] = {5, 12}, d4[] = {9, 40};
    Vector v14(d3, 2), v13(d4, 2);
    ASSERT_NEAR(6.1097086298276162, v13.angle(v14), 0.001);
}

#endif