#include <iostream>
#include <string>
#include <list>
using std::cout; using std::endl; using std::cin; using std::string; using std::list;
//largest first palindrome detected in a 58110 word dictionary is apparently "deified".
int main()
{
    cout << "How many words do you want to enter: ";
    int amnt;
    cin >> amnt;
    cout << endl;

    string word;
    list<string> words;
    for (int i = 0; i < amnt; i++) {
        cout << "Enter a word: ";
        cin >> word;
        words.push_back(word);
        cout << endl;
    }

    int median, maxlen = 0;
    bool palinq = true;
    string lpalin;
    list<string> allpalins;
    for (auto line : words) {
        median = line.size() / 2;

        for (int i = 0; i < median; i++) {
            if (line[i] != line[line.size() - 1 - i]) {
                palinq = false;
                break;
            }
            
        }

        if (palinq) {
            allpalins.push_back(line);
            if (line.size() > maxlen) {
                maxlen = line.size();
                lpalin = line;
            }
        }

        palinq = true;
    }

    for (auto line : allpalins) {
        cout << line << endl;
    }
    cout << endl;

    cout << lpalin;

    return 0;
}