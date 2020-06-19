#include <gtest/gtest.h>
#include "../src/circle.h"
#include "../src/convexPolygon.h"
#include "../src/util.h"
#include "../src/vector.h"

#include <cmath>

class IOTest : public ::testing::Test {
protected:
    void SetUp() {
        double v1[] = {0, -1};
        double v2[] = {2, 0};
        double v3[] = {1, 1};
        vecs1 = {
            *(new Vector(v1, 2)),
            *(new Vector(v2, 2)),
            *(new Vector(v3, 2))};

        double v4[] = {1, 0};
        double v5[] = {1, 4};
        double v6[] = {-2, 2};
        vecs2 = {
            *(new Vector(v4, 2)),
            *(new Vector(v5, 2)),
            *(new Vector(v6, 2)),
        };

        shapes.push_back(new Circle(2, "c1"));
        shapes.push_back(new Circle(1.5, "c2"));
        shapes.push_back(new ConvexPolygon(vecs1, "p1"));
        shapes.push_back(new ConvexPolygon(vecs2, "p2"));
    }

    void TearDown() {
        for (Shape *shape : shapes)
            delete shape;
    }

    std::vector<Vector> vecs1;
    std::vector<Vector> vecs2;
    std::vector<Shape *> shapes;
};

TEST_F(IOTest, test_area_ascending) {
    std::vector<Shape *> result = handleSort(shapes, "area", "inc");

    ASSERT_EQ("p1", result[0]->name());
    ASSERT_EQ("p2", result[1]->name());
    ASSERT_EQ("c2", result[2]->name());
    ASSERT_EQ("c1", result[3]->name());
}

TEST_F(IOTest, test_area_descending) {
    std::vector<Shape *> result = handleSort(shapes, "area", "dec");

    ASSERT_EQ("c1", result[0]->name());
    ASSERT_EQ("c2", result[1]->name());
    ASSERT_EQ("p2", result[2]->name());
    ASSERT_EQ("p1", result[3]->name());
}

TEST_F(IOTest, test_perimeter_ascending) {
    std::vector<Shape *> result = handleSort(shapes, "perimeter", "inc");

    ASSERT_EQ("p1", result[0]->name());
    ASSERT_EQ("c2", result[1]->name());
    ASSERT_EQ("p2", result[2]->name());
    ASSERT_EQ("c1", result[3]->name());
}

TEST_F(IOTest, test_perimeter_descending) {
    std::vector<Shape *> result = handleSort(shapes, "perimeter", "dec");

    ASSERT_EQ("c1", result[0]->name());
    ASSERT_EQ("p2", result[1]->name());
    ASSERT_EQ("c2", result[2]->name());
    ASSERT_EQ("p1", result[3]->name());
}

TEST_F(IOTest, handle_input_circle) {
    std::vector<Shape *> shape = handleInput("shape_data_1");

    ASSERT_EQ(1, shape.size());
    ASSERT_EQ("big", shape[0]->name());
}

TEST_F(IOTest, handle_input_convex_polygon) {
    std::vector<Shape *> shape = handleInput("shape_data_2");

    ASSERT_EQ(1, shape.size());
    ASSERT_EQ("anonymous", shape[0]->name());
}

TEST_F(IOTest, handle_input_multi_shapes) {
    std::vector<Shape *> shape = handleInput("shape_data_3");

    ASSERT_EQ(4, shape.size());
    ASSERT_EQ("c1", shape[0]->name());
    ASSERT_EQ("c2", shape[1]->name());
    ASSERT_EQ("p1", shape[2]->name());
    ASSERT_EQ("p2", shape[3]->name());
}

TEST_F(IOTest, handle_output_circie) {
    handleOutput("output_shape_data", shapes);

    std::vector<Shape *> shape = handleInput("output_shape_data");
    ASSERT_EQ(4, shape.size());
    ASSERT_EQ("c1", shape[0]->name());
    ASSERT_EQ("c2", shape[1]->name());
    ASSERT_EQ("p1", shape[2]->name());
    ASSERT_EQ("p2", shape[3]->name());
}
