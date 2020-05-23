#ifndef UTIL_H
#define UTIL_H

#include <vector>
#include "../src/binary.h"
#include "../src/uint.h"
#include "../src/ushort.h"
#include "../src/uchar.h"

template <class RandomAccessIterator, class Condition>
std::vector<Binary *> findAll(RandomAccessIterator begin, RandomAccessIterator end, Condition condition)
{
    std::vector<Binary *> result;
    for (auto i = begin; i != end; i++)
    {
        if (condition(*i))
        {
            result.push_back(*i);
        }
    }
    return result;
}

template <class T>
std::vector<T> convertAll(std::vector<Binary *> const &bins)
{
    std::vector<Binary *> canConvert = findAll(bins.begin(), bins.end(), [](Binary *binary) {
        return T::canConvert(*binary);
    });
    std::vector<T> result;
    for (auto i : canConvert)
    {
        result.push_back(T(*i));
    }
    return result;
}

#endif
