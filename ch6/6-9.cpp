#include <iostream>
#include <vector>
#include <string>
#include <numeric>
using std::cout; using std::vector; using std::string; using std::accumulate;

int main()
{
    vector<string> vecstr;
    vecstr.push_back("a");
    vecstr.push_back("b");
    vecstr.push_back("c");

    string result, emptystring = "";
    result = accumulate(vecstr.begin(), vecstr.end(), emptystring);

    cout << result;

    return 0;
}