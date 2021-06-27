#include <iostream>
#include <vector>
#include <algorithm>
using std::cout; using std::vector; using std::copy;

int main()
{
    //Prediction: This program will copy the contents of vector u (which has 10 and 100 as its elements) to vector v.
    //correction after testing: vector u has 10 one hundreds.

    vector<int> u(10, 100);
    vector<int> v;
    copy(u.begin(), u.end(), v.begin());


    for (auto line : v) {
        cout << line << "\n";
    }

    //Result: It seems that the vector v did not get anything copied to it since it is empty. Copy /= insert.
    //I have learned that copy doesn't change lengths; it just overwrites the current values.
    //6-3 is complete and I can assume the above assumptions apply to copy_if as well.

    return 0;
}