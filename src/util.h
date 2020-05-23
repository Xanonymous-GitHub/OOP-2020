#ifndef UTIL_H
#define UTIL_H

#include <vector>

template <class RandomAccessIterator, class Condition>
std::vector<Binary*> findAll(RandomAccessIterator begin, RandomAccessIterator end, Condition cond){}

template <class T>
std::vector<T> convertAll(std::vector<Binary*> const & bins){}

#endif
