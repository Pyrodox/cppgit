#include <iostream>
#include <algorithm>
using std::cout; using std::max;

int main()
{
    
    int maxlen;
    //s.name.size() can be any int that is positive, so 3 will substitute s.name.size()
    cout << max(3, maxlen);
    //Yes, it does work, because an undefined value from maxlen will generate an arbitrary value that is still an int. 
    // If there is an issue, then I can simply asssign an int value to maxlen;
    
    return 0;
}