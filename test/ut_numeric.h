#include "../src/binary.h"
#include "../src/uint.h"
#include "../src/ushort.h"
#include "../src/uchar.h"

class NumericTest : public ::testing::Test
{
protected:
    void SetUp()
    {
        data1 = new int[7]{1, 1, 0, 0, 0, 0, 1}; //a
        data2 = new int[7]{1, 0, 1, 1, 0, 0, 0}; //X
        data3 = new int[9]{1, 0, 1, 1, 0, 0, 0, 0, 0};
    }
    int
        *data1,
        *data2,
        *data3;
    void TearDown()
    {
        delete[] data1;
        delete[] data2;
        delete[] data3;
        // delete[] data4;
    }
};

TEST_F(NumericTest, uCharCanConvert)
{
    Binary b1(data1, 7);
    Binary b2(data2, 7);
    Binary b3(data3, 9);
    ASSERT_TRUE(uChar::canConvert(b1));
    ASSERT_TRUE(uChar::canConvert(b2));
    ASSERT_FALSE(uChar::canConvert(b3));
}

TEST_F(NumericTest, uCharConstructorCanNotConvert)
{
    Binary b1(data3, 9);
    ASSERT_ANY_THROW(uChar c1(b1));
}

TEST_F(NumericTest, uCharToChar)
{
    Binary b1(data1, 7);
    Binary b2(data2, 7);
    uChar c1(b1);
    uChar c2(b2);
    ASSERT_EQ('a', c1.toChar());
    ASSERT_EQ('X', c2.toChar());
}