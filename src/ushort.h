#ifndef U_SHORT_H
#define U_SHORT_H

#include "binary.h"

class uShort
{
private:
  Binary _b;
  unsigned short __pow(int base, int exponent) const
  {
    unsigned short result = 1;
    for (int i = 0; i < exponent; i++)
    {
      result *= base;
    }
    return (unsigned short)result;
  }

public:
  static bool canConvert(Binary const &bits)
  {
    return bits.size() <= 16;
  }

  uShort(Binary const &bits)
  {
    if (!(canConvert(bits)))
    {
      throw string("can't convert!");
    }
    _b = bits;
  }

  unsigned short toDec()
  {
    unsigned short result = 0;
    for (int i = _b.size() - 1, j = 0; i >= 0; i--, j++)
    {
      result += _b.at(i) * __pow(2, j);
    }
    return (unsigned short)result;
  }
};

#endif
