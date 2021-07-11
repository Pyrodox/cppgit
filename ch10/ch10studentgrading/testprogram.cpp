#include <iostream>
#include <vector>
using std::cout; using std::vector;

int main()
{
    int arr[] = { 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << n << "\n";


    vector<int> *v;
    (*v).push_back(1);
    (*v).push_back(2);
    cout << v;

    return 0;
}