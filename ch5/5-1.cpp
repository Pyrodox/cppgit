#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
using std::cout; using std::endl; using std::cin; using std::string; 
using std::vector; using std::sort; using std::list;

bool compare(string a, string b)
{
    return a < b;
}

list<string> readwords(const int amntphrases, const int amntwords, list<string> &phrases)
{
    string word;
    vector<string> words;

    string word2 = "";
    cout << "Enter your string: ";
    for (int t = 0; t < amntwords; t++) {
        cin >> word;
        word2 += word + " ";
        words.push_back(word);
    }

    cout << endl;

    phrases.push_back(word2);

    for (int e = 0; e < amntwords - 1; e++) {
        word2 = "";

        for (int a = e + 1; a < amntwords; a++) {
            word2 += words[a] + " ";
        }

        word2 += "&";

        for (int o = 0; o < e + 1; o++) {
            word2 += words[o] + " ";
        }

        phrases.push_back(word2);
    }

    return phrases;
}

vector<string> separatefunc(const string line, vector<int> &beginspacesvec, int &maxlen, vector<string> &finalphrases)
{
    string wholestr = "";
    if (line.find("&") < line.length()) {
            const int separator = line.find("&");
            int secondsep = line.size() - separator;

            const string substr1 = line.substr(separator + 1, secondsep - 2);
            wholestr += substr1 + string(5, ' ');
            const string substr2 = line.substr(0, separator - 1);
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

    return finalphrases;
}

list<string> spaceout(const vector<string> finalphrases, const int maxlen, const vector<int> beginspaces)
{
    list<string> finalphrases2;
    for (int i = 0; i < finalphrases.size(); i++) {
        finalphrases2.push_back(string(maxlen - beginspaces[i], ' ') + finalphrases[i]);
    }

    return finalphrases2;
}

int main()
{
    int amntphrases;
    cout << "Enter how many phrases you want: ";
    cin >> amntphrases;
    cout << endl;

    list<string> phrases;
    for (int i = 0; i < amntphrases; i++) {
        int amntwords;
        cout << "How many words do you want for phrase " << i << "?: ";
        cin >> amntwords;
        cout << endl;

        readwords(amntphrases, amntwords, phrases);
    }

    phrases.sort(compare);

    vector<int> beginspacesvec;
    vector<string> finalphrases;
    int maxlen = 0;

    for (auto line : phrases) {
        separatefunc(line, beginspacesvec, maxlen, finalphrases);
    }

    list<string> finalphrases_spaces = spaceout(finalphrases, maxlen, beginspacesvec);

    cout << endl;
    for (auto line : finalphrases_spaces) {
        cout << line << endl;
    }
    cout << endl;

    return 0;
}