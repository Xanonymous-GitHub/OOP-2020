#include "../src/math_vector.h"
#include <iostream>
using namespace std;
class VectorTest : public ::testing::Test {
protected:
    void SetUp() override {
        entries1 = new double[]{1, 2, 3, 4};
        entries2 = new double[]{1, 3, 3, 7};
        entries3 = new double[]{5, 7, 1, 2};
        entries4 = new double[]{2, 1, 13, 94};
        entries5 = new double[]{7, 0, 2, 0};
        entries6 = new double[]{4, 0, 2, 0};
        entries7 = new double[]{8, 4, 3, 6, 1};
        entries8 = new double[]{3, 8, 33, 5, 4};
        entries9 = new double[]{0, 3, 4, 1, 0};
        entries0 = new double[]{3, 3, 4, 1, 2};
    }
    double *entries1, *entries2, *entries3, *entries4, *entries5, *entries6, *entries7, *entries8, *entries9, *entries0;
    void TearDown() override {
        delete[] entries1;
        delete[] entries2;
        delete[] entries3;
        delete[] entries4;
        delete[] entries5;
        delete[] entries6;
        delete[] entries7;
        delete[] entries8;
        delete[] entries9;
        delete[] entries0;
    }
};

TEST_F(VectorTest, MathVector_default_constructor) {
    MathVector mathvector;
    ASSERT_EQ(0, mathvector.dimension());
}

TEST_F(VectorTest, MathVector_normal_constructor) {
    MathVector mathvector(entries1, 4);
    ASSERT_EQ(4, mathvector.dimension());
    for (int i = 0; i < 4; i++) {
        ASSERT_NEAR(0.0, entries1[i] - mathvector[i], 0.001);
    }
}

TEST_F(VectorTest, MathVector_zero_constructor) {
    MathVector mathvector(9487);
    ASSERT_EQ(9487, mathvector.dimension());
    for (int i = 0; i < 9487; i++) {
        ASSERT_NEAR(0.0, mathvector[i], 0.001);
    }
}

TEST_F(VectorTest, copy_constructor) {
    MathVector mathvector1(entries2, 4);
    MathVector mathvector2(mathvector1);
    ASSERT_EQ(4, mathvector2.dimension());
    for (int i = 0; i < 4; i++) {
        ASSERT_NEAR(0.0, entries2[i] - mathvector2[i], 0.001);
    }
}

TEST_F(VectorTest, Object_assignment) {
    MathVector mathvector1(entries3, 4);
    MathVector mathvector2 = mathvector1;
    ASSERT_EQ(4, mathvector2.dimension());
    for (int i = 0; i < 4; i++) {
        ASSERT_NEAR(0.0, entries3[i] - mathvector2[i], 0.001);
    }
}

TEST_F(VectorTest, Object_assignment2) {
    MathVector mathvector1(entries8, 5);
    MathVector mathvector2 = mathvector1;
    ASSERT_EQ(5, mathvector2.dimension());
    for (int i = 0; i < 5; i++) {
        ASSERT_NEAR(0.0, entries8[i] - mathvector2[i], 0.001);
    }
}

TEST_F(VectorTest, operator_add) {
    MathVector mathvector1(entries3, 4), mathvector3(entries5, 4);
    MathVector mathvector2(entries6, 4);
    mathvector2 = mathvector2 + mathvector1 + mathvector3;
    ASSERT_EQ(4, mathvector2.dimension());
    for (int i = 0; i < 4; i++) {
        ASSERT_NEAR(0.0, (entries3[i] + entries5[i] + entries6[i]) - mathvector2[i], 0.001);
    }
}

TEST_F(VectorTest, add_normal) {
    MathVector mathvector1(entries4, 4), mathvector3(entries5, 4);
    MathVector mathvector2(entries6, 4);
    mathvector2 = mathvector2 + mathvector1 + mathvector3;
    ASSERT_EQ(4, mathvector2.dimension());
    for (int i = 0; i < 4; i++) {
        ASSERT_NEAR(0.0, (entries4[i] + entries5[i] + entries6[i]) - mathvector2[i], 0.001);
    }
}

TEST_F(VectorTest, add_exception) {
    MathVector mathvector1(entries4, 4), mathvector3(entries5, 4);
    MathVector mathvector2(entries9, 5);
    ASSERT_ANY_THROW(mathvector2 + mathvector1 + mathvector3);
}

TEST_F(VectorTest, scale) {
    MathVector mathvector(entries1, 4);
    ASSERT_EQ(4, mathvector.dimension());
    mathvector = mathvector.scale(241.34);
    for (int i = 0; i < 4; i++) {
        ASSERT_NEAR(entries1[i] * 241.34, mathvector[i], 0.001);
    }
}