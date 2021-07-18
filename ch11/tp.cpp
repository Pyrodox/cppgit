#include <iostream>
#include <list>
using std::cout; using std::list;

int main()
{
    list<int> a{1, 2, 3, 4, 5, 6};
    cout << a.begin() + 3;

    return 0;
}