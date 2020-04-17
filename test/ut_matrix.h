#include "../src/math_vector.h"
#include "../src/matrix.h"

class MatrixTest : public ::testing::Test {
protected:
    void SetUp() override {
        entries1 = new double[4]{1, 2, 3, 4};
        entries2 = new double[4]{1, 3, 3, 7};
        entries3 = new double[4]{5, 7, 1, 2};
        entries4 = new double[4]{1, -1, 2, 4};
        entries5 = new double[4]{2, -1, 2, 1};
        entries6 = new double[4]{5, -3, 6, 6};
        entries_a = new double[5]{1, 2, 4, 1, 3};
        entries_b = new double[5]{2, -1, 1, 3, 7};
        entries_c = new double[5]{-4, 7, 5, -7, 4};
        entries7 = new double[5]{8, 4, 3, 6, 1};
        entries8 = new double[5]{3, 8, 33, 5, 4};
        entries9 = new double[5]{0, 3, 4, 1, 0};
        entries0 = new double[5]{3, 3, 4, 1, 2};
    }
    double *entries_a, *entries_b, *entries_c, *entries1, *entries2, *entries3, *entries4, *entries5, *entries6, *entries7, *entries8, *entries9, *entries0;
    void TearDown() override {
        delete[] entries_a;
        delete[] entries_b;
        delete[] entries_c;
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

TEST_F(MatrixTest, Matrix_constructor) {
    MathVector *m = new MathVector[3];
    m[0] = MathVector(entries3, 4);
    m[1] = MathVector(entries1, 4);
    m[2] = MathVector(entries2, 4);
    Matrix matrix(m, 3, 4);
    ASSERT_NEAR(5, matrix.at(1, 1), 0.01);
    ASSERT_NEAR(2, matrix.at(2, 2), 0.01);
    ASSERT_NEAR(3, matrix.at(3, 3), 0.01);
}

TEST_F(MatrixTest, Matrix_constructor_exception) {
    MathVector *m = new MathVector[3];
    m[0] = MathVector(entries0, 4);
    m[1] = MathVector(entries9, 5);
    m[2] = MathVector(entries2, 4);
    ASSERT_ANY_THROW(Matrix matrix(m, 3, 4));
}

TEST_F(MatrixTest, copy_constructor) {
    MathVector *m1 = new MathVector[3], *m2 = new MathVector[3];
    m1[0] = MathVector(entries1, 4);
    m1[1] = MathVector(entries2, 4);
    m1[2] = MathVector(entries3, 4);
    Matrix matrix(m1, 3, 4);
    Matrix matrix_copy(matrix);
    ASSERT_NEAR(1, matrix_copy.at(1, 1), 0.01);
    ASSERT_NEAR(3, matrix_copy.at(2, 2), 0.01);
    ASSERT_NEAR(1, matrix_copy.at(3, 3), 0.01);
}

TEST_F(MatrixTest, row_reduction) {
    MathVector *m = new MathVector[3];
    m[0] = MathVector(entries1, 4);
    m[1] = MathVector(entries2, 4);
    m[2] = MathVector(entries3, 4);
    Matrix matrix(m, 3, 4);
    matrix.rowReduction();
    ASSERT_NEAR(4, matrix.at(1, 4), 0.01);
    ASSERT_NEAR(3, matrix.at(2, 4), 0.01);
    ASSERT_NEAR(0.64285714, matrix.at(3, 4), 0.01);
}

TEST_F(MatrixTest, back_substitution) {
    MathVector *m = new MathVector[3];
    m[0] = MathVector(entries1, 4);
    m[1] = MathVector(entries2, 4);
    m[2] = MathVector(entries3, 4);
    Matrix matrix(m, 3, 4);
    matrix.backSubstitution();
    ASSERT_NEAR(-4, matrix.at(1, 4), 0.01);
    ASSERT_NEAR(1, matrix.at(2, 4), 0.01);
    ASSERT_NEAR(2, matrix.at(3, 4), 0.01);
}

TEST_F(MatrixTest, gaussian_elimination_normal1) {
    MathVector *m = new MathVector[3];
    m[0] = MathVector(entries1, 4);
    m[1] = MathVector(entries2, 4);
    m[2] = MathVector(entries3, 4);
    Matrix matrix(m, 3, 4);
    matrix.gaussianElimination();
    ASSERT_NEAR(-3.92857143, matrix.at(1, 4), 0.01);
    ASSERT_NEAR(3, matrix.at(2, 4), 0.01);
    ASSERT_NEAR(0.64285714, matrix.at(3, 4), 0.01);
}

TEST_F(MatrixTest, gaussian_elimination_normal2) {
    MathVector *m = new MathVector[4];
    m[0] = MathVector(entries7, 5);
    m[1] = MathVector(entries8, 5);
    m[2] = MathVector(entries9, 5);
    m[3] = MathVector(entries0, 5);
    Matrix matrix(m, 4, 5);
    matrix.gaussianElimination();
    ASSERT_NEAR(0.66666667, matrix.at(1, 5), 0.01);
    ASSERT_NEAR(0.04356636, matrix.at(2, 5), 0.01);
    ASSERT_NEAR(0.17730496, matrix.at(3, 5), 0.01);
    ASSERT_NEAR(-0.83991895, matrix.at(4, 5), 0.01);
}

TEST_F(MatrixTest, gaussian_elimination_infinite_solution) {
    MathVector *m = new MathVector[3];
    m[0] = MathVector(entries4, 4);
    m[1] = MathVector(entries5, 4);
    m[2] = MathVector(entries6, 4);
    Matrix matrix(m, 3, 4);
    ASSERT_ANY_THROW(matrix.gaussianElimination());
}

TEST_F(MatrixTest, gaussian_elimination_no_solution) {
    MathVector *m = new MathVector[4];
    m[0] = MathVector(entries_a, 5);
    m[1] = MathVector(entries_b, 5);
    m[2] = MathVector(entries_c, 5);
    m[3] = MathVector(entries_c, 5);
    Matrix matrix(m, 4, 5);
    ASSERT_ANY_THROW(matrix.gaussianElimination());
}