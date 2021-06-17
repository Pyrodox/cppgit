#include <iostream>
#include <iomanip>
#include <string>
using std::cout; using std::endl; using std::setw; using std::to_string; using std::setprecision; using std::showpoint;
//very frustrating experience
int main()
{
    for (double i = 1.0; i < 1000.0; ++i){
        cout << showpoint << setprecision(to_string(int(i)).size() + 1) << i;
        cout << setprecision(to_string(int(i * i)).size() + 1) << setw(30 - to_string(i).size()) << i * i << endl;
    }
}