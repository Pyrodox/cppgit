#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <string>
#include <iterator>
using std::cout; using std::endl; using std::vector; using std::domain_error;
using std::string; using std::back_inserter; using std::sort; using std::ostream_iterator;
using std::swap; using std::istream_iterator; using std::cin; using std::isspace;
//stl algorithm templates will be named with a number after the name to avoid ambiguity
template<class T> T median(vector<T> v)
{
    typedef typename vector<T>::size_type vec_sz;
    vec_sz size = v.size();

    if (size == 0) {
        throw domain_error("median of an empty vector");
    }

    sort(v.begin(), v.end());
    vec_sz mid = size/2;

    return size % 2 == 0 ? (v[mid] + v[mid-1]) / 2 : v[mid];
}

template<class T> T max1(const T& left, const T& right)
{
    return left > right ? left : right;
}

template <class In, class X> In find1(In begin, In end, const X& x)
{
    while (begin != end && *begin != x) {
        ++begin;
    }

    return begin;
}

template <class In, class X> In find2(In begin, In end, const X& x)
{    
    if (begin == end || *begin == x) {
        return begin;    
    }
    begin++;    
    
    return  find(begin, end, x);
}

template<class In, class Out>Out copy1(In begin, In end, Out dest)
{    
    while (begin != end) {
        *dest++ = *begin++;
    }

    return dest;
}

template<class For, class X>void replace1(For beg, For end, const X& x, const X& y)
{    
    while (beg != end) {        
        if (*beg == x) {            
            *beg = y;
        }         
         
        ++beg;
    }
}

template<class Bi> void reverse1(Bi begin, Bi end)
{    
    while (begin != end) {        
        --end;        
        if (begin != end) {            
            swap(*begin++, *end);
        }
    }
}

template<class Ran, class X>bool binary_search1(Ran begin, Ran end, const X& x)
{   while (begin < end) {        
        Ran mid = begin + (end - begin) / 2;        
        
        if (x < *mid) {
            end = mid;
        }       
        else if (*mid < x) {            
            begin = mid + 1;
        }
        else { 
            return true;
        }
    }    

    return false;
}

bool spaceq(char c)
{
    return isspace(c);
}

bool notspaceq(char c)
{
    return !isspace(c);
}

template <class Out> void split(const string& str, Out os)
{
    typedef string::const_iterator iter;
    iter i = str.begin();    
    while (i != str.end()) {        
        i = find_if(i, str.end(), notspaceq);        
        iter j = find_if(i, str.end(), spaceq);

        if (i != str.end()) {
            *os++ = string(i, j);
        }
        
        i = j;
    }
}

int main()
{
    vector<int> a{1, 2, 3};
    cout << median(a) << endl;

    cout << max1(5, 6) << endl;
    
    string b = find1(a.begin(), a.end(), 5) != a.end() ? "found" : "not found";
    cout << b << endl;

    string c = find2(a.begin(), a.end(), 2) != a.end() ? "found" : "not found";
    cout << c << endl;

    vector<int> d;
    copy1(a.begin(), a.end(), back_inserter(d));
    copy1(d.begin(), d.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    replace1(d.begin(), d.end(), 3, 4);
    copy1(d.begin(), d.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    reverse1(d.begin(), d.end());
    copy1(d.begin(), d.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    string e = binary_search1(a.begin(), a.end(), 2) ? "found" : "not found";
    cout << e << endl;

    vector<int> v;
    copy(istream_iterator<int>(cin),  istream_iterator<int>(), back_inserter(v));
    copy1(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    string s;  
    while (getline(cin, s)) {        
        split(s, ostream_iterator<string>(cout, "\n"));
    }
    cout << endl;

    return 0;
}