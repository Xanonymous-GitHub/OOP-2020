#include <gtest/gtest.h>
#include "../src/vector.h"

TEST(VectorTest, test_default_constructor) {
    Vector vec;
    ASSERT_EQ(-1, vec.dim());
    ASSERT_ANY_THROW(vec.at(0));
}

TEST(VectorTest, test_constructor) {
    double v[] = {-1, 6, 5.1, 0, -3, 4, -0.2};
    Vector vec(v, 7);

    ASSERT_EQ(7, vec.dim());
    ASSERT_EQ(-1, vec.at(0));
    ASSERT_EQ(6, vec.at(1));
    ASSERT_EQ(5.1, vec.at(2));
    ASSERT_EQ(0, vec.at(3));
    ASSERT_EQ(-3, vec.at(4));
    ASSERT_EQ(4, vec.at(5));
    ASSERT_EQ(-0.2, vec.at(6));
}

TEST(VectorTest, test_constructor_dimension_only) {
    Vector vec(4);
    ASSERT_EQ(4, vec.dim());
    ASSERT_EQ(0, vec.at(0));
    ASSERT_EQ(0, vec.at(1));
    ASSERT_EQ(0, vec.at(2));
    ASSERT_EQ(0, vec.at(3));
}

TEST(VectorTest, test_operator_add) {
    double v1[] = {1, 2.21, 2};
    double v2[] = {2.4, -3, 0};

    Vector vec1(v1, 3);
    Vector vec2(v2, 3);
    Vector result = vec1 + vec2;

    ASSERT_EQ(3, result.dim());
    ASSERT_EQ(3.4, result.at(0));
    ASSERT_EQ(-0.79, result.at(1));
    ASSERT_EQ(2, result.at(2));
}

TEST(VectorTest, test_operator_add_exception) {
    double v1[] = {1, 0, 2};
    double v2[] = {-2, 3, 4, 1};

    Vector vec1 = Vector(v1, 3);
    Vector vec2 = Vector(v2, 4);

    ASSERT_ANY_THROW(vec1 + vec2);
}

TEST(VectorTest, test_operator_subtract) {
    double v1[] = {1, 2, 2.09};
    double v2[] = {2, -3, 0};

    Vector vec1(v1, 3);
    Vector vec2(v2, 3);
    Vector result = vec2 - vec1;

    ASSERT_EQ(3, result.dim());
    ASSERT_EQ(1, result.at(0));
    ASSERT_EQ(-5, result.at(1));
    ASSERT_EQ(-2.09, result.at(2));
}

TEST(VectorTest, test_operator_subtract_exception) {
    double v1[] = {-2, 0, -1, 0};
    double v2[] = {-9, 1, 4};

    Vector vec1(v1, 4);
    Vector vec2(v2, 3);

    ASSERT_ANY_THROW(vec2 - vec1);
}

TEST(VectorTest, test_length) {
    double v[] = {4, 0, -3};
    Vector vec(v, 3);
    ASSERT_EQ(5, vec.length());
}

TEST(VectorTest, test_angle) {
    double v1[] = {1, 1};
    double v2[] = {1, -1};
    double v3[] = {1, 0};
    double v4[] = {-1, 1};

    Vector vec1(v1, 2);
    Vector vec2(v2, 2);
    Vector vec3(v3, 2);
    Vector vec4(v4, 2);

    ASSERT_EQ(M_PI * 3 / 2, vec1.angle(vec2));
    ASSERT_EQ(M_PI * 1 / 2, vec2.angle(vec1));
    ASSERT_EQ(M_PI * 3 / 4, vec3.angle(vec4));
    ASSERT_EQ(M_PI * 5 / 4, vec4.angle(vec3));
    ASSERT_NEAR(M_PI, vec2.angle(vec4), 0.001);
}

TEST(VectorTest, test_area) {
    double v1[] = {3, 0};
    double v2[] = {3, 10};

    Vector vec1(v1, 2);
    Vector vec2(v2, 2);

    ASSERT_NEAR(15, vec1.area(vec2), 0.001);
}

TEST(VectorTest, test_area_2) {
    double v1[] = {-1, -2};
    double v2[] = {10, -2};

    Vector vec1(v1, 2);
    Vector vec2(v2, 2);

    ASSERT_NEAR(11, vec1.area(vec2), 0.001);
}

TEST(VectorTest, test_to_string) {
    double v[] = {3, -4};

    Vector vec(v, 2);

    ASSERT_EQ("(3,-4)", vec.toString());
}
