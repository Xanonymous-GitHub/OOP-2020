#include "../src/math_vector.h"
#include "../src/matrix.h"

class MatrixTest : public ::testing::Test {
protected:
    void SetUp() override {}
};

TEST_F(MatrixTest, no) {
    ASSERT_TRUE(true);
}