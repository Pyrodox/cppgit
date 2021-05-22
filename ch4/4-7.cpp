#include <iostream>
#include <vector>
using std::cout; using std::vector; using std::endl; using std::cin;

int main()
{
    vector<double> numbers;

    cout << "How many numbers do you want to be averaged?" << endl;
    int divide;
    cin >> divide;

    int userinput;
    int total = 0;
    for (int i = 0; i < divide; ++i) {
        cout << "Enter a number: " << endl;
        cin >> userinput;
        numbers.push_back(userinput);
        total += userinput;
    }

    cout << double(total) / divide;

    return 0;
}