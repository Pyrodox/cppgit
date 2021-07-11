#include <algorithm>
#include <stdexcept>
#include <vector>
using std::domain_error; using std::sort; using std::vector;

template<class T, class B, class I>T median(B c, I cit)
{    
    typedef typename B::size_type con_sz;    
    con_sz size = std::size(c);    
    
    if (size == 0) {        
        throw domain_error("median of an empty vector/built-in array");
    }
    
    sort(cit, cit + size);    
    con_sz mid = size / 2;    
    
    return size % 2 == 0 ? (c[mid] + c[mid-1]) / 2 : c[mid];
}