#include <iostream>
#include <vector>
//#include <algorithm>
#include <stdexcept>
#include <string>
using std::cout; using std::endl; using std::vector; using std::domain_error; using std::string;

/*template<class T> T median(vector<T> v)
{
    typedef typename vector<T>::size_type vec_sz;
    vec_sz size = v.size();

    if (size == 0) {
        throw domain_error("median of an empty vector");
    }

    sort(v.begin(), v.end());
    vec_sz mid = size/2;

    return size % 2 == 0 ? (v[mid] + v[mid-1]) / 2 : v[mid];
}*/

template<class T> T max(const T& left, const T& right)
{
    return left > right ? left : right;
}

template <class In, class X> In find(In begin, In end, const X& x)
{
    while (begin != end && *begin != x) {
        ++begin;
    }

    return begin;
}

int main()
{
    vector<int> a{1, 2, 3};

    //cout << median(a) << endl;

    cout << max(5, 6) << endl;

    //tested ambiguous find by commenting out algorithm and median parts.
    string b = find(a.begin(), a.end(), 5) != a.end() ? "found" : "not found";
    cout << b << endl;

    return 0;
}