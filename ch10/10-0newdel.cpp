#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using std::cout; using std::copy; using std::string; using std::strlen;

char* duplicate_chars(const char* p)
{    
    // allocate enough space; remember to add one for the null    
    size_t length = strlen(p) + 1;    
    char* result = new char[length];    
    // copy into our newly allocated space and return pointer to first element 
    copy(p, p + length, result);    
    
    return result;
}

int* pointer_to_static()
{
    static int x;

    return &x;
}

int main()
{
    cout << pointer_to_static << "\n";
    const char p[] = "abc";
    const char* p1 = "abc";
    cout << duplicate_chars(p) << "\n";
    cout << *p << " " << p << " " << p1[1] << *p1 << "\n";

    return 0;
}