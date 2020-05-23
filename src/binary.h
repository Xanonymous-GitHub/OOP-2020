#ifndef BINARY_H
#define BINARY_H

#include <cmath>
#include <iostream>
using namespace std;

class Binary
{
private:
    int *_bits;
    int _size;

    unsigned int __pow(int base, int exponent) const
    {
        int result = 1;
        for (int i = 0; i < exponent; i++)
        {
            result *= base;
        }
        return (unsigned int)result;
    }

public:
    Binary() : _bits(nullptr), _size(0) {}

    Binary(int bits[], int size)
    {
        _size = size;
        _bits = new int[_size];
        for (int i = 0; i < _size; i++)
        {
            if ((bits[i]) && bits[i] != 1)
            {
                throw string("not bin!");
            }

            _bits[i] = bits[i];
        }
    }

    ~Binary()
    {
        if (_bits != nullptr)
        {
            delete[] _bits;
        }
    }

    Binary(Binary const &b)
    {
        _size = b._size;
        _bits = new int[_size];
        for (int i = 0; i < _size; i++)
        {
            _bits[i] = b._bits[i];
        }
    }

    Binary &operator=(Binary const &b)
    {
        _size = b._size;
        _bits = new int[_size];
        for (int i = 0; i < _size; i++)
        {
            _bits[i] = b._bits[i];
        }
        return *this;
    }

    int at(int i) const
    {
        if (i >= _size || i < 0)
        {
            throw string("out of range");
        }
        return _bits[i];
    }

    int size() const
    {
        return _size;
    }

    Binary fillWithZero(int n)
    {
        if (n < _size)
        {
            throw string("size is smaller then original binary size");
        }
        int new_zero_size = n - _size;
        int tmp[_size];
        for (int i = 0; i < _size; i++)
        {
            tmp[i] = _bits[i];
        }
        _bits = new int[n];
        int i;
        for (i = 0; i < new_zero_size; i++)
        {
            _bits[i] = 0;
        }
        for (; i < n; i++)
        {
            _bits[i] = tmp[i - new_zero_size];
        }
        _size = n;
        return *this;
    }

    unsigned int toDec() const
    {
        unsigned int result = 0;
        for (int i = _size - 1, j = 0; i >= 0; i--, j++)
        {
            result += _bits[i] * __pow(2, j);
        }
        return result;
    }

    Binary shrimSize(int new_size)
    {
        int tmp[new_size];
        for (int i = _size - new_size, j = 0; i < _size; i++, j++)
        {
            tmp[j] = _bits[i];
        }
        int *new_bits = new int[new_size];
        for (int i = 0; i < new_size; i++)
        {
            new_bits[i] = tmp[i];
        }
        return *new Binary(new_bits, new_size);
    }
};

#endif
