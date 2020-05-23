#ifndef U_INT_H
#define U_INT_H

#include "binary.h"

class uInt
{
private:
  Binary _b;
  unsigned int __pow(int base, int exponent) const
  {
    unsigned int result = 1;
    for (int i = 0; i < exponent; i++)
    {
      result *= base;
    }
    return (unsigned int)result;
  }

public:
  static bool canConvert(Binary const &bits)
  {
    return bits.size() <= 32;
  }

  uInt(Binary const &bits)
  {
    if (!(canConvert(bits)))
    {
      throw string("can't convert!");
    }
    _b = bits;
  }

  unsigned int toDec()
  {
    unsigned int result = 0;
    for (int i = _b.size() - 1, j = 0; i >= 0; i--, j++)
    {
      result += _b.at(i) * __pow(2, j);
    }
    return (unsigned int)result;
  }

  static int getSize()
  {
    return 4;
  }
};

#endif
