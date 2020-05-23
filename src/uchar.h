#ifndef U_CHAR_H
#define U_CHAR_H

#include "binary.h"
using namespace std;

class uChar
{
private:
  Binary _b;
  char __pow(int base, int exponent) const
  {
    char result = 1;
    for (int i = 0; i < exponent; i++)
    {
      result *= base;
    }
    return (char)result;
  }

public:
  static bool canConvert(Binary const &bits)
  {
    return bits.size() <= 8;
  }

  uChar(Binary const &bits)
  {
    if (!(canConvert(bits)))
    {
      throw string("can't convert!");
    }
    _b = bits;
  }

  char toChar()
  {
    char result = 0;
    for (int i = _b.size() - 1, j = 0; i >= 0; i--, j++)
    {
      result += _b.at(i) * __pow(2, j);
    }
    return (char)result;
  }
};

#endif
