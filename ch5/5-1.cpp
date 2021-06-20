#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
using std::cout; using std::endl; using std::cin; using std::string; using std::vector; using std::sort; using std::iterator;

bool compare(string a, string b)
{
    return a < b;
}

int main()
{
    int amntphrases;
    cout << "Enter how many phrases you want: ";
    cin >> amntphrases;
    cout << endl;

    int amntwords;
    string word;
    vector<string> words, phrasesvec;
    for (int i = 0; i < amntphrases; i++) {
        cout << "How many words do you want for phrase " << i << " ?: ";
        cin >> amntwords;
        cout << endl;

        string word2 = "";
        for (int t = 0; t < amntwords; t++) {
            cout << "Enter a word: ";
            cin >> word;
            word2 += word + " ";
            words.push_back(word);
            cout << endl;
        }
        phrasesvec.push_back(word2);

        for (int e = 0; e < amntwords - 1; e++) { //each phrase rotation
            word2 = "";
            for (int a = e + 1; a < amntwords; a++) {
                word2 += words[a] + " ";
            }

            word2 += "&";

            for (int o = 0; o < e + 1; o++) {
                word2 += words[o] + " ";
            }

            phrasesvec.push_back(word2);
        }

        words.clear();
    }

    sort(phrasesvec.begin(), phrasesvec.end(), compare);

    vector<int> separatorvec, beginspacesvec;
    vector<string> finalphrases, finalphrases_spaces;
    int separator, maxlen = 0;
    string substr1, substr2, wholestr = "";
    for (auto line : phrasesvec) {
        if (line.find("&") < line.length()) {
            separator = line.find("&");
            int secondsep = line.size() - separator;
            substr1 = line.substr(separator + 1, secondsep - 2);
            wholestr += substr1 + string(5, ' ');
            substr2 = line.substr(0, separator - 1);
            wholestr += substr2;

            beginspacesvec.push_back(substr1.size());

            if (substr1.size() > maxlen) {
                maxlen = substr1.size();
            }

            finalphrases.push_back(wholestr);
        }
        else {
            finalphrases.push_back(string(5, ' ') + line);
            beginspacesvec.push_back(0);
        }
        wholestr = "";
    }

    for (int i = 0; i < finalphrases.size(); i++) {
        finalphrases_spaces.push_back(string(maxlen - beginspacesvec[i], ' ') + finalphrases[i]);
    }

    for (auto line : finalphrases_spaces) {
        cout << line << endl;
    }

    return 0;
}