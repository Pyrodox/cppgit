#include <map>
#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include <algorithm>
using std::map; using std::cout; using std::endl; using std::cin; using std::transform;
using std::string; using std::iterator; using std::vector; using std::find;
using std::istream; using std::sort; using std::pair; using std::copy; using std::back_inserter;

typedef vector<pair<string, vector<int> > > tosort;

bool space(char c)
{
    return isspace(c);
}

bool not_space(char c)
{
    return !isspace(c);
}

bool compare(pair<string, vector<int> >& it, pair<string, vector<int> >& it2)
{
    return it.second.size() < it2.second.size();
}

vector<string> split(const string& str)
{
    typedef string::const_iterator iter;
    vector<string> ret;
    iter i = str.begin();
    while (i != str.end()) {
        i = find_if(i, str.end(), not_space);

        iter j = find_if(i, str.end(), space);

        if (i != str.end()) {
            ret.push_back(string(i, j));
        }

        i = j;
    }

    return ret;
}

map<string, vector<int> > xref(istream& in, vector<string> find_words(const string&) = split)
{
    string line;
    int line_number = 0;
    map<string, vector<int> > ret;

    while (getline(in, line)) {
        ++line_number;

        vector<string> words = find_words(line);
        for (auto it = words.begin(); it != words.end(); ++it) {
            if (find(ret[*it].begin(), ret[*it].end(), line_number) == ret[*it].end()) {
                ret[*it].push_back(line_number);
            }    
        }
    }

    return ret;
}



int main()
{
    map<string, vector<int> > ret = xref(cin);

    tosort pairstosort;
    copy(ret.begin(), ret.end(), back_inserter(pairstosort));
    sort(pairstosort.begin(), pairstosort.end(), compare);

    for (tosort::const_iterator it = pairstosort.begin(); it != pairstosort.end(); ++it) {
        cout << it->first << " occurs on line(s): ";

        vector<int>::const_iterator line_it = it->second.begin();
        cout << *line_it;

        ++line_it;

        vector<int>::const_iterator next = it->second.begin() + 20;
        while (line_it != it->second.end()) {
            cout << ", "; 
            
            if (line_it == next) {
                next += 20;
                cout << "\n\n";
            }

            cout << *line_it;

            ++line_it;
        }

        cout << endl;
    }

    cout << endl;

    return 0;
}