#include <iostream>
#include <string>
#include "vec.h"
#include <memory>
using std::cout; using std::string; using std::endl; 
using std::max; using std::cin;
typedef Vec<string> vecstr;

string::size_type width(const vecstr& v)
{
    string::size_type maxlen = 0;
    for (vecstr::size_type i = 0; i != v.size(); ++i)
        maxlen = max(maxlen, v[i].size());
    return maxlen;
}
alloc<string> a;
template <class T> typename Vec<T>::const_iterator insert2(vecstr out, const T* p1, const T* p2)
{
    while (p1 != p2) {
        out.push_back(*p1);
        ++p1;
    }

    return p1;
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

    insert2(ret, bottom.begin(), bottom.end());
    
    return ret;
}

vecstr hcat(const vecstr& left, const vecstr& right)
{
    vecstr ret;

    string::size_type width1 = width(left) + 1;

    vecstr::size_type i = 0, j = 0;
    
    //5-8 Prediction: if s was defined outside of the while loop, then the ret vector would be the same until the left vector reaches it's final size, 
    //and then the spaces and right vector bottom parts of ret would be much larger since s isn't reset.
    //Ok so it threw a length error, which means I was partly right since the bottom parts became "much larger", so an error was called.
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
//The property of a picture that could use the center well would have words that are around the same size, and this can be verified by eyeballing.
vecstr center(const vecstr &centervec)
{
    int maxlen = width(centervec);

    vecstr newcentervec;
    int secondspaces;
    for (string i : centervec) {
        secondspaces = maxlen - i.size() - ((maxlen - i.size()) / 2);
        newcentervec.push_back("* " + string((maxlen - i.size()) / 2, ' ') + i + string(secondspaces, ' ') + " *");
    }

    return newcentervec;
}

int main()
{
    //5-7 Prediction: The frame function calls the width function, but the width function's for loop will just cancel when initiated since v is an empty vector. 
    //Since v is an empty vector, the frame function's for loop will not add anything to vector ret, and printing ret out will result in nothing.
    Vec<string> v;
    auto ret = frame(v);

    //testing my prediction
    for (auto line : ret) {
        cout << line << endl;
    }
    //It seems that I was incorrect.
    //Looking back at it now, I understand why I was wrong: I forgot to consider the borders that were always added to the ret vector no matter what.
    //Second time running; it should print out just the border parts frame(v). Correct.

    cout << "How many words do you want to frame?: ";
    int amnt;
    cin >> amnt;
    cout << "\n";

    if (amnt < 1) {
        return 1;
    }

    vecstr wordvec;
    string word;
    for (int i = 0; i < amnt; i++) {
        cout << "Enter a word: ";
        cin >> word;
        wordvec.push_back(word);
        cout << "\n";
    }

    cout << "frame\n" << endl;

    const vecstr newvec = frame(wordvec);
    for (string line : newvec) {
        cout << line << endl;
    }

    cout << endl;

    cout << "vertical cocatenation frame number 2\n" << endl;

    const int newvecsz = newvec.size();
    vecstr topvec, botvec;
    insert2(topvec, newvec.begin(), newvec.begin() + newvecsz / 2);
    insert2(botvec, newvec.begin() + newvecsz / 2, newvec.end());
    
    vecstr vervec = vcat(topvec, botvec);
    for (string line : vervec) {
        cout << line << endl;
    }

    cout << "\n";

    cout << "vertical cocatenation\n" << endl;

    vervec = vcat(wordvec, frame(wordvec));
    for (string line: vervec) {
      cout << line << endl;
    }

    cout << endl;

    cout << "horizontal cocatentation\n" << endl;

    const vecstr horvec = hcat(wordvec, frame(wordvec));
    for (string line : horvec) {
        cout << line << endl;
    }

    cout << "center\n" << endl;

    const vecstr cenvec = center(wordvec);
    for (string line : cenvec) {
        cout << line << endl;
    }

   return 0;
}