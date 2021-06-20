#include <iostream>
#include <string>
#include <list>
using std::cout; using std::endl; using std::cin; using std::string; using std::list;
//largest first word in a 58110 word dictionary without any ascenders or desceners detected is apparently "carnivorousness". 
string wordfunc()
{
    cout << "Enter a word (if not printed, then you don't have an ascender/descender.): ";
    string word;
    cin >> word;
    cout << endl;

    for (int i = 0; i < word.size(); i++) {
        if (word[i] == 'b' || word[i] == 'd' || word[i] == 'f' || word[i] == 'h' || word[i] == 'k' || word[i] == 'l' || word[i] == 't') {
            cout << "Your word has an ascender. " << endl;
            break;
        }
    }

    for (int i = 0; i < word.size(); i++) {
        if (word[i] == 'g' || word[i] == 'j' || word[i] == 'p' || word[i] == 'q' || word[i] == 'y') {
            cout << "Your word has a descender. " << endl;
            break;
        }
    }
}

int main()
{
    wordfunc();

    cout << "dictionary time" << endl;

    cout << "How many words?: ";
    int amnt;
    cin >> amnt;
    cout << endl;

    list<string> words;
    string word;
    for (int i = 0; i < amnt; i++) {
        cout << "Enter a word: ";
        cin >> word;
        words.push_back(word);
        cout << endl;
    }

    int largest = 0;
    string largeststr;
    for (auto line : words) {
        if (!line.find('b') < line.length() && !line.find('d') < line.length() && !line.find('f') < line.length()
            && !line.find('h') < line.length() && !line.find('k') < line.length() && !line.find('l') < line.length()
            && !line.find('t') < line.length() && !line.find('g') < line.length() && !line.find('j') < line.length()
            && !line.find('p') < line.length() && !line.find('q') < line.length() && !line.find('y') < line.length()) {
                if (line.size() > largest) {
                    largest = line.size();
                    largeststr = line;
                }
        }
    }

    cout << largeststr;

    return 0;
}