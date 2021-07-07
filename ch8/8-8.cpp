#include <iostream>
#include <vector>
using std::cout; using std::vector;

template<class Ran, class X>bool binary_search(Ran begin, Ran end, const X& x)
{    
    while (begin < end) {        
        // find the midpoint of the range        
        Ran mid = begin + (end - begin) / 2; //(begin + end) / 2 causes massive errors
        //I suppose the reason why the correct way is begin + (end - begin) / 2 is because that end doesn't refer to any value within the container,
        //so adding another iterator to it would just make no sense since it doesn't refer to any value, and the original way pinpoints the midpoint.       
        // see which part of the range contains x; keep looking only in that part         
        if (x < *mid) {            
            end = mid;
        }
        else if (*mid < x) {            
            begin = mid + 1;
        }
        // if we got here, then *mid == x so we're done         
        else {
            return true;
        }    
    }    
    
    return false;
}

int main()
{
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    bool find = binary_search(v.begin(), v.end(), 10);
    if (find) {
        cout << "found 10\n";
    }

    return 0;
}