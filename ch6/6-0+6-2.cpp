#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include <cctype>
using std::cout; using std::endl; using std::vector; using std::search;
using std::copy; using std::iterator; using std::string; using std::isspace;
using std::back_inserter; using std::find_if; using std::equal;

bool space(const char &c)
{
    return isspace(c);
}

bool not_space(const char &c)
{
    return !isspace(c);
}

vector<string> split(const string &str)
{
    typedef string::const_iterator iter;
    vector<string> ret;

    iter i = str.begin();
    while (i != str.end()) {
      i = find_if(i, str.end(), not_space);

      iter j = find_if(i, str.end(), space);

      if (i != str.end())
        ret.push_back(string(i, j));

      i = j;
    }

    return ret;
}

bool is_palindrome(const string &s)
{
    return equal(s.begin(), s.end(), s.rbegin());
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
//6-2
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

int main()
{
    vector<string> splitvec = split("string to split");
    for (string line : splitvec) {
        cout << line << endl;
    }

    cout << endl;

    cout << is_palindrome("civic") << endl;
    cout << is_palindrome("palindrome") << endl;
    cout << is_palindrome("huhhhhhhhuh") << endl;

    cout << endl;

    vector<string> urls = find_urls("eezzzzeeeeeeee eezeeezee://???????? omegalul ashreprintwhen://&&&&khghsdkg");
    for (string line : urls) {
        cout << line << endl;
    }

    return 0;
}