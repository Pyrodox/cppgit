#include <map>
#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <list>
using std::map; using std::cout; using std::endl; using std::rand; using std::string; using std::back_inserter;
using std::iterator; using std::istream; using std::logic_error; using std::pair; using std::list;
using std::cin; using std::domain_error; using std::advance; using std::vector; using std::ostream_iterator;

typedef vector<string> Rule;
typedef vector<Rule> Rule_collection;
typedef map<string, Rule_collection> Grammar;

bool space(char c)
{
    return isspace(c);
}

bool not_space(char c)
{
    return !isspace(c);
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

bool bracketed(const string& s)
{
    return s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>';
}

int nrand(int n)
{   
    if (n < 0) {
        throw domain_error("Argument to nrand is out of range");    
    }

    int bucket_size, r, randmulti;
    if (n <= RAND_MAX) {
        bucket_size = RAND_MAX / n;        
        do {
            r = rand() / bucket_size;
            if (n == 0) {
                r = 0;
                return r;
            }
        }    
        while (r >= n);
    }
    else {
        bucket_size = 2147483647 / n;
        do {
            //2147483647 / RAND_MAX = 65538
            r = (rand() * (65538)) / bucket_size;
        }
        while (r >= n);
    }
    //randmulti = rand() / (RAND_MAX / multn);
    //const int multn = 2147483647 / RAND_MAX;
    //both in the else loop

    return r;
}

void gen_aux(const Grammar& g, const string& word, vector<string>& ret, vector<pair<const string, Rule_collection> >& rulelst)
{    
    if (!bracketed(word)) {        
        ret.push_back(word);    
    }
    else {        
        Grammar::const_iterator it = g.find(word);        
        if (it == g.end()) {         
            throw logic_error("empty rule");
        }

        rulelst.push_back(*it);        
       
        const Rule_collection& c = it->second;

        const Rule& r = c[nrand(c.size())];
        
        for (Rule::const_iterator i = r.begin(); i != r.end(); ++i) {            
            gen_aux(g, *i, ret, rulelst);
        }
    }
}

vector<string> gen_sentence(const Grammar& g)
{    
    vector<string> ret;
    vector<pair<const string, Rule_collection> > rulelst;
    gen_aux(g, "<sentence>", ret, rulelst);    
    copy(ret.begin(), ret.end(), ostream_iterator<string>(cout, " "));

    return ret;
}

Grammar read_grammar(istream& in)
{
    Grammar ret;
    string line;

    while (getline(in, line)) {
        vector<string> entry = split(line);

        if (!entry.empty()) {
            ret[*entry.begin()].push_back(Rule(entry.begin() + 1, entry.end()));
        }
    }

    return ret;
}

int main()
{    
    vector<string> sentence = gen_sentence(read_grammar(cin));
    list<string> sentencelst;
    copy(sentence.begin(), sentence.end(), back_inserter(sentencelst));
    
    cout << endl;    
    
    return 0;
}