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
        data4 = new int[14]{1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0};       //10922
        data5 = new int[16]{1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1}; //60075
        data6 = new int[17]{1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0};
        data7 = new int[31]{1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1};       //1431655765
        data8 = new int[32]{1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1};    //3579139413
        data9 = new int[33]{1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0};
    }
    int
        *data1,
        *data2,
        *data3,
        *data4,
        *data5,
        *data6,
        *data7,
        *data8,
        *data9;
    void TearDown()
    {
        delete[] data1;
        delete[] data2;
        delete[] data3;
        delete[] data4;
        delete[] data5;
        delete[] data6;
        delete[] data7;
        delete[] data8;
        delete[] data9;
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

TEST_F(NumericTest, uShortCanConvert)
{
    Binary b4(data4, 14);
    Binary b5(data5, 16);
    Binary b6(data6, 17);
    ASSERT_TRUE(uShort::canConvert(b4));
    ASSERT_TRUE(uShort::canConvert(b5));
    ASSERT_FALSE(uShort::canConvert(b6));
}

TEST_F(NumericTest, uShortConstructorCanNotConvert)
{
    Binary b1(data6, 17);
    ASSERT_ANY_THROW(uShort s1(b1));
}

TEST_F(NumericTest, uShortToDec)
{
    Binary b4(data4, 14);
    Binary b5(data5, 16);
    uShort s1(b4);
    uShort s2(b5);
    ASSERT_EQ(10922, s1.toDec());
    ASSERT_EQ(60075, s2.toDec());
}

TEST_F(NumericTest, uIntCanConvert)
{
    Binary b7(data7, 31);
    Binary b8(data8, 32);
    Binary b9(data9, 33);
    ASSERT_TRUE(uInt::canConvert(b7));
    ASSERT_TRUE(uInt::canConvert(b8));
    ASSERT_FALSE(uInt::canConvert(b9));
}

TEST_F(NumericTest, uIntConstructorCanNotConvert)
{
    Binary b1(data9, 33);
    ASSERT_ANY_THROW(uInt s1(b1));
}

TEST_F(NumericTest, uIntToDec)
{
    Binary b7(data7, 31);
    Binary b8(data8, 32);
    uInt s1(b7);
    uInt s2(b8);
    ASSERT_EQ(1431655765, s1.toDec());
    ASSERT_EQ(3579139413, s2.toDec());
}