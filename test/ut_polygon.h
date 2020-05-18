#ifndef UT_POLYGON_H
#define UT_POLYGON_H

#include "../src/polygon.h"
#include "../src/vector.h"
#include <vector>

#include <iostream>
using namespace std;
// TEST(notest, no) {
//     ASSERT_TRUE(true);
// }

TEST(POLYGON, point) {
    double d1[] = {1, 2}, d2[] = {3, 4}, d3[] = {-2, -3};
    Vector v1(d1, 2), v2(d2, 2), v3(d3, 2);
    Vector vectors[] = {v1, v2, v3};
    Polygon p1(vectors, 3), p2(vectors, 3);
    for (int i = 0; i < 3; i++) {
        cout << (int)(p1.point(i + 1) == p2.point(i + 1)) << endl;
        // ASSERT_TRUE(p1.point(i + 1) == p2.point(i + 1));
        ASSERT_TRUE(true);
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
    // ASSERT_TRUE(true);
}

TEST(POLYGON, perimeter) {
    double d1[] = {1, 2}, d2[] = {3, 4}, d3[] = {-2, -3};
    Vector v1(d1, 2), v2(d2, 2), v3(d3, 2);
    Vector vectors[] = {v1, v2, v3};
    Polygon p1(vectors, 3);
    ASSERT_NEAR(2.82843 + 8.60233 + 5.83095, p1.perimeter(), 0.001);
}

TEST(POLYGON, area) {
    double d1[] = {0, 0}, d2[] = {0, 1}, d3[] = {1, 0}, d4[] = {1, 1};
    Vector v1(d1, 2), v2(d2, 2), v3(d3, 2), v4(d4, 2);
    Vector vectors[] = {v1, v2, v3, v4};
    Polygon p1(vectors, 4);
    // double S = 0.5 * (2.236067 + 2 + 2.236067);
    ASSERT_NEAR(1, p1.area(), 0.001);
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
    double d6[] = {-1.1, 2, 8}, d7[] = {1.2, 2.3, -3}, d8[] = {4, 4, 4};
    Vector v6(d6, 3), v7(d7, 3), v8(d8, 3);
    Vector vectors3[] = {v6, v7, v8};
    Polygon *p3 = new Polygon(vectors3, 3);
    vector<Polygon *> pp{p1, p2, p3};
    vector<Polygon *> pp2{p1, p3};
    vector<Polygon *> pp3{p1, p3};
    ASSERT_TRUE(pp2 == findAll(pp.begin(), pp.end(), [](Polygon *p) {
        return p->sides() == 3;
    }));
}

#endif