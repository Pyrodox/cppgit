#include <iostream>
#include <string>
#include <vector>
#include <iterator>
using std::cout; using std::endl; using std::cin; using std::string; using std::vector; using std::iterator;

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

        //amntwords - 1, 3
        for (int e = 0; e < 3; e++) { //each phrase rotation
            word2 = ""; 
             //amntwords, 4
             //1 needs to constantly change
            for (int a = e + 1; a < 4; a++) { //cocatenating the words: a and o loops
                word2 += words[a] + " ";
            }
            //o < x must also constantly change
            for (int o = 0; o < e + 1; o++) { //help lol
                word2 += words[o] + " ";
            }
            

            phrasesvec.push_back(word2);
        }

        words.clear();
    }

    for (auto line : phrasesvec) {
        cout << line << endl;
    }

    return 0;
}