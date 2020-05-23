#include "../src/binary.h"

#include <iostream>
using namespace std;
class BinaryTest : public ::testing::Test
{
protected:
  void SetUp()
  {
    data1 = new int[4]{0, 0, 1, 0},
    data2 = new int[4]{0, 1, 0, 2};
    data3 = new int[8]{0, 0, 0, 0, 0, 0, 1, 0};
    data4 = new int[5]{1, 0, 1, 0, 1};
  }
  int
      *data1,
      *data2,
      *data3,
      *data4;
  void TearDown()
  {
    delete[] data1;
    delete[] data2;
    delete[] data3;
    delete[] data4;
  }
};

TEST_F(BinaryTest, defaultConstructor)
{
  Binary b;
  ASSERT_EQ(0, b.size());
}

TEST_F(BinaryTest, changeTypeConstructor)
{
  Binary b(data1, 4);
  ASSERT_EQ(4, b.size());
  for (int i = 0; i < 4; i++)
  {
    ASSERT_EQ(data1[i], b.at(i));
  }
}

TEST_F(BinaryTest, changeTypeConstructorDataNotCorrect)
{
  ASSERT_ANY_THROW(Binary b(data2, 4));
}

TEST_F(BinaryTest, copyConstructor)
{
  Binary b1(data1, 4);
  Binary b2(b1);
  ASSERT_EQ(4, b2.size());
  for (int i = 0; i < 4; i++)
  {
    ASSERT_EQ(data1[i], b2.at(i));
  }
}

TEST_F(BinaryTest, CopyAssignment)
{
  Binary b1(data1, 4);
  Binary b2 = b1;
  ASSERT_EQ(4, b2.size());
  for (int i = 0; i < 4; i++)
  {
    ASSERT_EQ(data1[i], b2.at(i));
  }
}

TEST_F(BinaryTest, fillWithZero)
{
  Binary b1(data1, 4);
  b1.fillWithZero(8);
  ASSERT_EQ(8, b1.size());
  for (int i = 0; i < 8; i++)
  {
    ASSERT_EQ(data3[i], b1.at(i));
  }
}

TEST_F(BinaryTest, fillWithZeroSizeError)
{
  Binary b1(data1, 4);
  ASSERT_ANY_THROW(b1.fillWithZero(3));
}

TEST_F(BinaryTest, toDec)
{
  Binary b1(data1, 4);
  Binary b2(data4, 5);
  ASSERT_EQ(2, b1.toDec());
  ASSERT_EQ(21, b2.toDec());
}

TEST_F(BinaryTest, at)
{
  Binary b(data1, 4);
  for (int i = 0; i < 4; i++)
  {
    ASSERT_EQ(data1[i], b.at(i));
  }
}

TEST_F(BinaryTest, atOutOfRange)
{
  Binary b(data1, 4);
  ASSERT_ANY_THROW(b.at(5));
  ASSERT_ANY_THROW(b.at(-87));
  ASSERT_ANY_THROW(b.at(100));
}