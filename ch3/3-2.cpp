#include <iostream>
#include <string>
#include <iomanip>
#include <ios>
#include <vector>
#include <algorithm>
#include <experimental/iterator>
using std::cout; using std::string; using std::endl; using std::cin;
using std::setprecision; using std::streamsize; using std::vector; using std::sort;

int main(){

    double x;
    vector<double> values;

    cout << "How many numbers are you entering? " << endl;
    int num_of_inputs;
    cin >> num_of_inputs;

    for (int i = 0; i < num_of_inputs; ++i) {
        cin >> x;
        values.push_back(x);
    }

    if (num_of_inputs < 4 || num_of_inputs % 4 != 0) {
        cout << "Enter at least 4 numbers please and have your number of values be a multiple of 4. " << endl;
        return 1;
    }

    typedef vector<double>::size_type vec_sz;
    vec_sz quartile = values.size() / 4;

    sort(values.begin(), values.end());
    cout << "Greatest quartile: ";
    for(int t = quartile; t > 0; --t) {
        cout << values[num_of_inputs - t] << ", ";
    }
    cout << endl;
    cout << "Second greatest quartile: ";
    for(int t = quartile; t > 0; --t) {
        cout << values[num_of_inputs - t - quartile] << ", ";
    }
    cout << endl;
    cout << "Second smallest quartile: ";
    for(int t = quartile; t > 0; --t) {
        cout << values[num_of_inputs - t - quartile * 2] << ", ";
    }
    cout << endl;
    cout << "Smallest quartile: ";
    for(int t = quartile; t > 0; --t) {
        cout << values[num_of_inputs - t - quartile * 3] << ", ";
    }
    
    return 0;
}