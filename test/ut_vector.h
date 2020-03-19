#include "../src/math_vector.h"
#include <gtest/gtest.h>
TEST(InnerProduct, ConstructorAnd) {
    double my_vector[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    MathVector *my_math_vector = new MathVector(my_vector, 9);
    for (int i = 0; i < 9; i++) {
        ASSERT_EQ(my_vector[i], my_math_vector->component(i + 1));
    }
}

TEST(InnerProduct, isZero) {
    double my_vector[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    MathVector *my_math_vector = new MathVector(my_vector, 9);
    ASSERT_TRUE(my_math_vector->isZero());
}

TEST(InnerProduct, length) {
    double my_vector[] = {7, 24};
    MathVector *my_math_vector = new MathVector(my_vector, 2);
    ASSERT_EQ(25, my_math_vector->length());
}

TEST(InnerProduct, getDim) {
    double my_vector[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    MathVector *my_math_vector = new MathVector(my_vector, 9);
    ASSERT_EQ(9, my_math_vector->getDim());
}