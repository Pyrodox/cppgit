#include <iostream>
#include <string>
#include <list>
#include <cctype>
using std::cout; using std::endl; using std::cin; using std::string; using std::list;

int main()
{
    cout << "Enter your letters: " << endl;
    string letters;
    cin >> letters;

    typedef list<char> lstchar;
    lstchar lowercase, uppercase;

    for (int i = 0; i < letters.size(); i++) {
        if (isupper(letters[i])) {
            uppercase.push_back(letters[i]);
        }
        else if (islower(letters[i])) {
            lowercase.push_back(letters[i]);
        }
    }

    cout << "lowercase" << endl;
    for (auto chara : lowercase) {
        cout << chara;
    }

    cout << "\nuppercase" << endl;
    for (auto chara: uppercase) {
        cout << chara;
    }

    return 0;
}