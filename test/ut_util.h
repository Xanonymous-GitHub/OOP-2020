#include "../src/binary.h"
#include "../src/uint.h"
#include "../src/ushort.h"
#include "../src/uchar.h"
#include "../src/util.h"

#include <vector>

class UtilTest : public ::testing::Test
{
protected:
  void SetUp()
  {
    int b1[] = {1, 0, 0, 0};
    int b2[] = {0, 1, 1, 1, 0, 0, 1, 1};
    int b3[] = {0, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1};
    int b4[] = {0, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1};
    int b5[] = {0, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 0, 1};
    bins.push_back(new Binary(b1, 4));
    bins.push_back(new Binary(b2, 8));
    bins.push_back(new Binary(b3, 16));
    bins.push_back(new Binary(b4, 32));
    bins.push_back(new Binary(b5, 34));
  }

  void TearDown()
  {
    for (Binary *b : bins)
    {
      delete b;
    }
    bins.clear();
  }
  std::vector<Binary *> bins;
};

TEST_F(UtilTest, findAllByCanConvertToIntTest)
{
  std::vector<Binary *> result = findAll(bins.begin(), bins.end(), [](Binary *b) {
    return uInt::canConvert(*b);
  });
  ASSERT_EQ(4, result.size());
  ASSERT_EQ(8, result[0]->toDec());
  ASSERT_EQ(115, result[1]->toDec());
  ASSERT_EQ(29555, result[2]->toDec());
  ASSERT_EQ(1936946035, result[3]->toDec());
}

TEST_F(UtilTest, findAllByCanConvertToShortTest)
{
  std::vector<Binary *> result = findAll(bins.begin(), bins.end(), [](Binary *b) {
    return uShort::canConvert(*b);
  });
  ASSERT_EQ(3, result.size());
  ASSERT_EQ(8, result[0]->toDec());
  ASSERT_EQ(115, result[1]->toDec());
  ASSERT_EQ(29555, result[2]->toDec());
}

TEST_F(UtilTest, findAllByCanConvertToCharTest)
{
  std::vector<Binary *> result = findAll(bins.begin(), bins.end(), [](Binary *b) {
    return uChar::canConvert(*b);
  });
  ASSERT_EQ(2, result.size());
  ASSERT_EQ(8, result[0]->toDec());
  ASSERT_EQ(115, result[1]->toDec());
}

TEST_F(UtilTest, converallToShortTest)
{
  std::vector<uShort> result = convertAll<uShort>(bins);
  ASSERT_EQ(3, result.size());
  ASSERT_EQ(8, result[0].toDec());
  ASSERT_EQ(115, result[1].toDec());
  ASSERT_EQ(29555, result[2].toDec());
}

TEST_F(UtilTest, converallToCharTest)
{
  std::vector<uChar> result = convertAll<uChar>(bins);
  ASSERT_EQ(2, result.size());
  ASSERT_EQ(8, result[0].toChar());
  ASSERT_EQ(115, result[1].toChar());
}
TEST_F(UtilTest, converallToIntTest)
{
  std::vector<uInt> result = convertAll<uInt>(bins);
  ASSERT_EQ(4, result.size());
  ASSERT_EQ(8, result[0].toDec());
  ASSERT_EQ(115, result[1].toDec());
  ASSERT_EQ(29555, result[2].toDec());
  ASSERT_EQ(1936946035, result[3].toDec());
}