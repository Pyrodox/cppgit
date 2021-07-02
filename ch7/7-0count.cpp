#include <map>
#include <iostream>
#include <string>
#include <iterator>
#include <vector>
using std::map; using std::cout; using std::endl; using std::cin;
using std::string; using std::iterator; using std::vector;
//type CTRL + Z at the end using the control button with the z button.
int main()
{
    string s;
    map<string, int> counters;

    while (cin >> s) {
        ++counters[s];
    }

    for (map<string, int>::const_iterator it = counters.begin(); it != counters.end(); ++it) {
        cout << it->first << "\t" << it->second << endl;
    }

    return 0;
}