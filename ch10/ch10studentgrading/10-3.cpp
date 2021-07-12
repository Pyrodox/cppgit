#include <iostream>
#include <vector>
#include "10-2median.h"
using std::cout; using std::vector;

int main()
{
    int size = 10;
    int* arr = new int[size] {0, 2, 3, 4, 1, 6, 7, 5, 9, 8};
    vector<double> vd{1, 2, 3};
    auto a = median(9.1, size, arr, arr);
    auto d = median(9.1, vd.size(), vd, vd.begin());
    cout << a << "\n";
    cout << d << "\n";
    delete[] arr;

    return 0;
}