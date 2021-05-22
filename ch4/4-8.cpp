#include <iostream>
#include <vector>
using std::cout; using std::vector;

//We can infer that f() returns a vector.

vector<int> f() {
    vector<int> a;

    a.push_back(1);
    a.push_back(2);
    a.push_back(3);

    return a;
}
int main()
{
    int n = 0;
    double d = f()[n];
    cout << d;

    return 0;
}