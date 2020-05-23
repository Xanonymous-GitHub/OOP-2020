#ifndef BINARY_H
#define BINARY_H

#include <cmath>

class Binary{
public:
    Binary():_bits(nullptr),_size(0){}

    Binary(int bits[],int size):_bits(nullptr),_size(size){}

    ~Binary(){}

    Binary(Binary const & b){}

    Binary & operator=(Binary const & b){}

    int at(int i) const{}

    int size() const{}

    Binary fillWithZero(int n) const{}

    unsigned int toDec() const{}
private:
    int* _bits;
    int _size;
};

#endif
