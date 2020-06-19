#include <gtest/gtest.h>
#include "../src/circle.h"

TEST(CircleTest, test_constructor) {
    double v[] = {-10, 10};
    Vector vec(v, 2);
    Circle circle(10, "circle", vec);
    ASSERT_EQ(
        "circle {\n"
        "circle\n"
        "(-10,10)\n"
        "10\n"
        "}\n",
        circle.toString());
}

TEST(CircleTest, test_default_param) {
    Circle circle(10);
    ASSERT_EQ(
        "circle {\n"
        "anonymous\n"
        "(0,0)\n"
        "10\n"
        "}\n",
        circle.toString());
}

TEST(CircleTest, test_perimeter) {
    Circle circle(5);
    ASSERT_NEAR(31.4159265, circle.perimeter(), 0.001);
}

TEST(CircleTest, test_area) {
    Circle circle(10);
    ASSERT_NEAR(314.159265, circle.area(), 0.001);
}
