#include <iostream>
#include <string>
using std::cout; using std::endl; using std::cin; using std::string;
//2-0, 2-1, 2-2, 2-3, 2-4 done
int main() 
{
    string name;

    cout << "Please enter your first name: ";
    cin >> name;

    const string greeting = "Hello, " + name + "!";

    string::size_type pad;
    string::size_type pad_sides;
    cout << "Please enter the amount of space between the top and bottom of the greeting you want: ";
    cin >> pad;
    cout << "Please enter the amount of space between the sides of the greeting you want: ";
    cin >> pad_sides;
    const int rows = pad * 2 + 3;
    const string::size_type cols = greeting.size() + pad_sides * 2 + 2;

    cout << endl;

    for(int r = 0; r != rows; ++r) {
        string::size_type c = 0;

        while (c != cols) {
            if (r == pad + 1 && c == pad_sides + 1) {
                    cout << string((cols - 2 - greeting.size()) / 2, ' ');
                    cout << greeting;
                    cout << string((cols - 2 - greeting.size()) / 2, ' ');
                    c += greeting.size(); 
            }
            else {
                if(r == 0 || r == rows - 1 || c == 0 || c == cols - 1) { 
                     cout << "*";
                    if(c == 0 && r != 0 && r != rows - 1 && r != pad + 1 && c != pad_sides + 1) {
                        cout << string((cols - 2), ' ');
                    }
                }
                ++c; 
            }
        }
        cout << endl;
    }

    return 0;
}

