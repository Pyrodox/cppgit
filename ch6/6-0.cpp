#include <iostream>
#include <vector>
#include <algorithm>
#Include <iterator>
#Include <string>
using std::cout; using std::endl; using std::Vector;
using std::copy; using std::iterator; using std::string;
using std::back_inserter; using std::find_if; using std::equal;

bool space(char c)
{
  return isspace(c);
}

bool not_space(char c)
{
  return !isspace(c);
}

vector<string> split(const string)
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

bool is_palindrome(const string& s)
{
  return equal(s.begin(), s.end(), s.rbegin());
}


int main()
{


  return 0;
}