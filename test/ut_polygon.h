#ifndef UT_POLYGON_H
#define UT_POLYGON_H

#include "../src/polygon.h"
#include "../src/vector.h"
#include <vector>

TEST(POLYGON, point) {
    double d1[] = {1, 2}, d2[] = {3, 4}, d3[] = {-2, -3};
    Vector v1(d1, 2), v2(d2, 2), v3(d3, 2);
    Vector vectors[] = {v1, v2, v3};
    Polygon p1(vectors, 3), p2(vectors, 3);
    for (int i = 0; i < 3; i++) {
        ASSERT_TRUE(p1.point(i + 1) == p2.point(i + 1));
    }
}

TEST(POLYGON, sides) {
    double d1[] = {1, 2}, d2[] = {3, 4}, d3[] = {-2, -3};
    Vector v1(d1, 2), v2(d2, 2), v3(d3, 2);
    Vector vectors[] = {v1, v2, v3};
    Polygon p1(vectors, 3);
    ASSERT_EQ(3, p1.sides());
    double d4[] = {-1.1, 2, 8}, d5[] = {1.2, 2.3, -3};
    Vector v4(d4, 3), v5(d2, 3);
    Vector vectors2[] = {v4, v5};
    Polygon p2(vectors2, 2);
    ASSERT_EQ(2, p2.sides());
}

TEST(POLYGON, perimeter) {
    double d1[] = {1, 2}, d2[] = {3, 4}, d3[] = {-2, -3};
    Vector v1(d1, 2), v2(d2, 2), v3(d3, 2);
    Vector vectors[] = {v1, v2, v3};
    Polygon p1(vectors, 3);
    ASSERT_NEAR(2.82843 + 8.60233 + 5.83095, p1.perimeter(), 0.001);
}

TEST(POLYGON, area) {
    double d1[] = {0, 0}, d2[] = {2, 0}, d3[] = {3, 1}, d4[] = {2, 2};
    Vector v1(d1, 2), v2(d2, 2), v3(d3, 2), v4(d4, 2);
    Vector vectors[] = {v1, v2, v3, v4};
    Polygon p1(vectors, 4);
    ASSERT_NEAR(3, p1.area(), 0.001);
    double d5[] = {0, 0}, d6[] = {2, 0}, d7[] = {1, 3}, d8[] = {2, 2}, d9[] = {3, 1};
    Vector v5(d5, 2), v6(d6, 2), v7(d7, 2), v8(d8, 2), v9(d9, 2);
    Vector vectors2[] = {v5, v6, v7, v8, v9};
    Polygon p2(vectors2, 5);
    ASSERT_NEAR(5, p2.area(), 0.001);
}

TEST(POLYGON, findAll) {
    double d1[] = {1, 2}, d2[] = {1.2, 4}, d3[] = {-2, -3};
    Vector v1(d1, 2), v2(d2, 2), v3(d3, 2);
    Vector vectors[] = {v1, v2, v3};
    Polygon *p1 = new Polygon(vectors, 3);
    double d4[] = {-1.1, 2, 8}, d5[] = {1.2, 2.3, -3};
    Vector v4(d4, 3), v5(d2, 3);
    Vector vectors2[] = {v4, v5};
    Polygon *p2 = new Polygon(vectors2, 2);
    double d6[] = {-1.1, 2, 8}, d7[] = {1.9, 2.3, -3}, d8[] = {4, 4, 4};
    Vector v6(d6, 3), v7(d7, 3), v8(d8, 3);
    Vector vectors3[] = {v6, v7, v8};
    Polygon *p3 = new Polygon(vectors3, 3);
    vector<Polygon *> pp{p1, p2, p3};
    vector<Polygon *> pp2{p1, p3};
    vector<Polygon *> pp3{p1, p2};
    ASSERT_TRUE(pp2 == findAll(pp.begin(), pp.end(), [](Polygon *p) {
                    return p->sides() == 3;
                }));
    ASSERT_TRUE(pp3 == findAll(pp.begin(), pp.end(), [](Polygon *p) {
                    return p->point(2).at(1) == 1.2;
                }));
}

#endif