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
    cout << "How many words do you want to enter? ";
    int amount_of_words;
    cin >> amount_of_words;

    if (amount_of_words <= 0) {
        return 1;
    }
    cout << "Enter a string of words (use enter to separate the words): " << endl;
    string words; vector<string> wordvector;

    for (int i = 0; i < amount_of_words; ++i) {
        cin >> words;
        wordvector.push_back(words);
    }

    int distinctwords = 0; int count_to_check = 0;
    vector<string> firstdistinct;
    firstdistinct.push_back(wordvector[0]);

    for (double i = 0; i < amount_of_words; ++i) {
        for (double t = 0; t < firstdistinct.size(); ++t) {
            if (firstdistinct[t] != wordvector[i]) {
                cout << firstdistinct[t] << wordvector[i]; 
                ++count_to_check;
                cout << " ";                    
            }
        }
        if (count_to_check == firstdistinct.size()) {
                firstdistinct.push_back(wordvector[i]);
                ++distinctwords;
            }
        count_to_check = 0;
    }

    cout << endl;
    ++distinctwords;
    cout << distinctwords << " distinct words.";
    
    return 0;
}