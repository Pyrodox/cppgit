#include <iostream>
using std::cout;

int main()
{
    int product = 1;
    for (int i = 1; i < 10; ++i) {
        product *= i;
    }

    cout << product;

    return 0;
}