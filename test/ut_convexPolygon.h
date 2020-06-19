#include <gtest/gtest.h>
#include "../src/convexPolygon.h"

#include <cmath>
#include <vector>

TEST(ConvexPolygonTest, test_perimeter) {
    double v1[] = {1, 0};
    double v2[] = {2, 2};
    double v3[] = {-1, 0};
    Vector vec1(v1, 2);
    Vector vec2(v2, 2);
    Vector vec3(v3, 2);

    std::vector<Vector> vecs = {vec1, vec2, vec3};

    ConvexPolygon polygon(vecs, "triangle");
    ASSERT_EQ(2 + sqrt(5) + sqrt(13), polygon.perimeter());
}

TEST(ConvexPolygonTest, test_area) {
    double v1[] = {0, 1};
    double v2[] = {-1, 2};
    double v3[] = {-2, 1};
    double v4[] = {-1, 0};
    Vector vec1(v1, 2);
    Vector vec2(v2, 2);
    Vector vec3(v3, 2);
    Vector vec4(v4, 2);

    std::vector<Vector> vecs = {vec1, vec2, vec3, vec4};

    ConvexPolygon polygon(vecs, "square");
    ASSERT_NEAR(2, polygon.area(), 0.001);
}

TEST(ConvexPolygonTest, test_area_2) {
    double v1[] = {1, -2};
    double v2[] = {3, -1};
    double v3[] = {2, 2};
    double v4[] = {0, 3};
    double v5[] = {-2, 1};
    double v6[] = {-1, -1};
    Vector vec1(v1, 2);
    Vector vec2(v2, 2);
    Vector vec3(v3, 2);
    Vector vec4(v4, 2);
    Vector vec5(v5, 2);
    Vector vec6(v6, 2);

    std::vector<Vector> vecs = {vec1, vec2, vec3, vec4, vec5, vec6};
    ConvexPolygon polygon(vecs, "polygon");

    ASSERT_NEAR(15.5, polygon.area(), 0.001);
}

TEST(ConvexPolygonTest, test_to_string) {
    double v1[] = {2, -4};
    double v2[] = {5, -2};
    double v3[] = {3, 2};
    double v4[] = {1, 2};
    double v5[] = {-3, 0};
    Vector vec1(v1, 2);
    Vector vec2(v2, 2);
    Vector vec3(v3, 2);
    Vector vec4(v4, 2);
    Vector vec5(v5, 2);

    std::vector<Vector> vecs = {vec1, vec2, vec3, vec4, vec5};
    ConvexPolygon polygon(vecs, "polygon");

    ASSERT_EQ(
        "convex polygon {\n"
        "polygon\n"
        "(2,-4)\n"
        "(5,-2)\n"
        "(3,2)\n"
        "(1,2)\n"
        "(-3,0)\n"
        "}\n",
        polygon.toString());
}
