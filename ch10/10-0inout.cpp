#include <fstream>
#include <string>
using std::ifstream; using std::ofstream; using std::string; using std::endl; using std::getline;

int main()
{    
    ifstream infile("in");    
    ofstream outfile("out");    
    
    string s;    
    while (getline(infile, s)) {      
        outfile << s << endl;
    }
    
    return 0;
}