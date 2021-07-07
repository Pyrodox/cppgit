#include <iostream>
#include <vector>
using std::cout; using std::vector; using std::swap;

template<class Bi> void reverse(Bi begin, Bi end)
{    
    while (begin != end) {        
        --end;

        if (begin != end) {            
            swap(*begin++, *end);
        }    
    }
}

template<class Bi> void reverse2(Bi begin, Bi end)
{   
    int tempbegin;
    while (begin != end) {        
        --end;

        if (begin != end) {
            tempbegin = *begin;
            *begin++ = *end;
            *end = tempbegin;
        }    
    }
}

int main()
{
    //It's easy to see why swap was used instead of changing the values of begin and end directly.
    //First of all, swap is less code.
    //The second reason is that the programmer has to create temporary variables which is annoying.
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "original reverse\n";
    reverse(v.begin(), v.end());

    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << "\n";
    }
    
    cout << "\n\n";
    cout << "reverse suggested that we try out in 8-4\n";
    reverse2(v.begin(), v.end());

    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << "\n";
    }
    
    return 0;
}