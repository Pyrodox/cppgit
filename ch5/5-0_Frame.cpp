#include <iostream>
#include <string>
#include <vector>
using std::cout; using std::string; using std::endl; 
using std::vector; using std::max; using std::cin;
typedef vector<string> vecstr;

string::size_type width(const vecstr& v)
{
    string::size_type maxlen = 0;
    for (vecstr::size_type i = 0; i != v.size(); ++i)
        maxlen = max(maxlen, v[i].size());
    return maxlen;
}

vecstr frame(const vecstr& v) {
    vecstr ret;
    string::size_type maxlen = width(v);
    string border(maxlen + 4, '*');

    ret.push_back(border);

    for (vecstr::size_type i = 0; i != v.size(); ++i) {
        ret.push_back("* " + v[i] + string(maxlen - v[i].size(), ' ') + " *");
    }

    ret.push_back(border);
    return ret;
}

vecstr vcat(const vecstr& top, const vecstr& bottom)
{
    vecstr ret = top;

    ret.insert(ret.end(), bottom.begin(), bottom.end());
    
    return ret;
}

vecstr hcat(const vecstr& left, const vecstr& right)
{
    vecstr ret;

    string::size_type width1 = width(left) + 1;

    vecstr::size_type i = 0, j = 0;

    while (i != left.size() || j != right.size()) {
        string s;

        if (i != left.size())
            s = left[i++];

        s += string(width1 - s.size(), ' ');

        if (j != right.size())
            s += right[j++];

        ret.push_back(s);
    }
    return ret;
}

int main()
{
    cout << "How many words do you want to frame?: ";
    int amnt;
    cin >> amnt;
    cout << "\n";

    if (amnt < 1) {
        return 1;
    }

    //frame

    vecstr wordvec;
    string word;
    for (int i = 0; i < amnt; i++) {
        cout << "Enter a word: ";
        cin >> word;
        wordvec.push_back(word);
        cout << "\n";
    }

    const vecstr newvec = frame(wordvec);
    for (string line : newvec) {
        cout << line << endl;
    }

    cout << endl;

    //vertical cocatenation

    const int newvecsz = newvec.size();
    vecstr topvec, botvec;
    topvec.insert(topvec.end(), newvec.begin(), newvec.begin() + newvecsz / 2);
    botvec.insert(botvec.end(), newvec.begin() + newvecsz / 2, newvec.end());
    
    vecstr vervec = vcat(topvec, botvec);
    for (string line : vervec) {
        cout << line << endl;
    }

    cout << "\n";

    vervec = vcat(wordvec, frame(wordvec));
    for (string line: vervec) {
      cout << line << endl;
    }

    cout << endl;

    //horizontal cocatenation

    const vecstr horvec = hcat(wordvec, frame(wordvec));
    for (string line : horvec) {
        cout << line << endl;
    }

   return 0;
}