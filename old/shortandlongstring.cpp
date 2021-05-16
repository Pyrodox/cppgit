#include <iostream>
#include <string>
#include <iomanip>
#include <ios>
#include <vector>
#include <algorithm>
#include <experimental/iterator>
using std::cout; using std::string; using std::endl; using std::cin;
using std::setprecision; using std::streamsize; using std::vector; using std::sort;

int main() {
    vector<string> strvector;
    vector<double> sizes;
    string inputstr;
    int amount;
    cout << "How many strings?" << endl;
    cin >> amount;
    if (amount < 1) {
        return 1;
    }

    for (int i = 0; i < amount; ++i) {
        cout << "Enter a string: " << endl;
        cin >> inputstr;
        strvector.push_back(inputstr);
        sizes.push_back(inputstr.size());
    }

    sort(sizes.begin(), sizes.end());
    //vector<string> sortedstrvector;
    //for (double i = 0; i < amount; ++i) {
        //for ( double t = 0; t < amount; ++t) {
            //if (strvector[t].size() == sizes[i]) {
                //sortedstrvector.push_back(strvector[t]);
            //}
        //}
    //}
    cout << "The length of the smallest string is " << sizes[0] << " and the length of the largest string is " << sizes[sizes.size() - 1] << ".";

    return 0;
}