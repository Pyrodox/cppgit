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

bool not_url_char(char c)
{   
    static const string url_ch = "~;/?:@=&$-_.+!*'(),";     
    return !(isalnum(c) || find(url_ch.begin(), url_ch.end(), c) != url_ch.end());
}

string::const_iterator url_end(string::const_iterator b, string::const_iterator e)
{    
    return find_if(b, e, not_url_char);
}

string::const_iterator url_beg(string::const_iterator b, string::const_iterator e)
{   static const string sep = "://";    
    typedef string::const_iterator iter;    
    iter i = b;    
    while ((i = search(i, e, sep.begin(), sep.end())) != e) {        
        if (i != b && i + sep.size() != e) {            
            iter beg = i;            
            
            while (beg != b && isalpha(beg[-1]))                
                --beg;

            if (beg != i && !not_url_char(i[sep.size()]))                
                return beg;        
        }

        i += sep.size();    
    }

    return e;
}

vector<string> find_urls(const string& s)
{   
    vector<string> ret;    
    typedef string::const_iterator iter;
    iter b = s.begin(), e = s.end(); 

    while (b != e) {             
      b = url_beg(b, e);             
      if (b != e) {                  
        iter after = url_end(b, e);                       
        ret.push_back(string(b, after));                      
        b = after;        
      }    
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
    map<string, vector<int> > ret = xref(cin, find_urls);

    tosort pairstosort;
    copy(ret.begin(), ret.end(), back_inserter(pairstosort));
    sort(pairstosort.begin(), pairstosort.end(), compare);

    cout << endl;

    for (tosort::const_iterator it = pairstosort.begin(); it != pairstosort.end(); ++it) {
        
        string lineorlines = "line";
        if (it->second.size() > 1) {
            lineorlines = "line(s)";
        }

        cout << it->first << " occurs on " << lineorlines << ": ";

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