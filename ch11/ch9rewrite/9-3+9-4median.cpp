#include <algorithm>
#include <stdexcept>
#include "vec.h"
using std::domain_error; using std::sort;

double median(Vec<double> vec)
{
    typedef Vec<double>::size_type vec_sz;

    vec_sz size = vec.size();

    sort(vec.begin(), vec.end());

    vec_sz mid = size / 2;

    return size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
}