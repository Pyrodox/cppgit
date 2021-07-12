#ifndef GUARD_MEDIAN_H
#define GUARD_MEDIAN_H

#include <vector>
#include <iterator>
#include <algorithm>
#include <stdexcept>

template<class T, class I2, class B, class I>T median(T type, I2 size, B c, I cit)
{ 
    if (size == 0) {        
        throw std::domain_error("median of an empty vector/built-in array");
    }
    
    std::sort(cit, cit + size);    
    int mid = size / 2;    
    
    return size % 2 == 0 ? (c[mid] + c[mid-1]) / 2 : c[mid];
}

#endif