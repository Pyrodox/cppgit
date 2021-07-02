#include <map>
#include <iostream>
#include <list>
#include <string>
#include <iterator>
#include <algorithm>
#include <cstdlib>
#include <vector>
using std::map; using std::cout; using std::endl; using std::rand; using std::string;
using std::iterator; using std::istream; using std::logic_error; using std::pair;
using std::cin; using std::domain_error; using std::list; using std::advance; using std::vector;

typedef list<string> Rule;
typedef list<Rule> Rule_collection;
typedef map<string, Rule_collection> Grammar;

bool space(char c)
{
    return isspace(c);
}

bool not_space(char c)
{
    return !isspace(c);
}

list<string> split(const string& str)
{
    typedef string::const_iterator iter;
    list<string> ret;
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
    if (n <= 0 || n > RAND_MAX) {
        throw domain_error("Argument to nrand is out of range");    
    }

    const int bucket_size = RAND_MAX / n;    
    int r;    
    do {
        r = rand() / bucket_size;
    }    
    while (r >= n);

    return r;
}

void gen_aux(const Grammar& g, const string& word, list<string>& ret)
{    
    if (!bracketed(word)) {        
        ret.push_back(word);    
    }
    else {        
        Grammar::const_iterator it = g.find(word);        
        if (it == g.end()) {         
            throw logic_error("empty rule");
        }    
       
        const Rule_collection& c = it->second;        
        Rule_collection::const_iterator it2 = c.begin();
        advance(it, nrand(c.size()));
        const Rule& r = *it2;  
        
        for (Rule::const_iterator i = r.begin(); i != r.end(); ++i) {            
            gen_aux(g, *i, ret);
        }    
    }
}

list<string> gen_sentence(const Grammar& g)
{    
    list<string> ret;
    gen_aux(g, "<sentence>", ret);    

    return ret;
}

Grammar read_grammar(istream& in)
{
    Grammar ret;
    string line;

    while (getline(in, line)) {
        list<string> entry = split(line);

        if (!entry.empty()) {
            ret[*entry.begin()].push_back(Rule(++entry.begin(), entry.end()));
        }
    }

    return ret;
}

int main()
{    
    list<string> sentence = gen_sentence(read_grammar(cin));    
        
    list<string>::const_iterator it = sentence.begin();   
    if (!sentence.empty()) {
        cout << *it;        
        ++it;    
    }    
         
    while (it != sentence.end()) {        
        cout << " " << *it;        
        ++it;    
    }    
    
    cout << endl;    
    
    return 0;
}