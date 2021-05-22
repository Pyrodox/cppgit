#include <iostream>
#include <string>
using std::cout; using std::endl; using std::string; using std::cin;

int main()
{
    cout << "Please enter the first number: " << endl;
    int firstnum;
    cin >> firstnum;

    cout << "Please enter the second number: " << endl;
    int secondnum;
    cin >> secondnum;

    if (firstnum > secondnum) {
        cout << firstnum << " is greater than " << secondnum;
    }
    else {
        cout << secondnum << " is greater than " << firstnum;
    }

    return 0;
}