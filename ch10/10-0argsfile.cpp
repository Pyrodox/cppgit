#include <fstream>
#include <string>
#include <iostream>
using std::ifstream; using std::string; using std::cout;
using std::endl; using std::cerr;

int main(int argc, char **argv){
    int fail_count = 0;    
    // for each file in the input list    
    for (int i = 1; i < argc; ++i) {        
        ifstream in(argv[i]);        
        // if it exists, write its contents, otherwise generate an error message        
        if (in) {            
            string s;            
            
            while (getline(in, s)) {         
                cout << s << endl;
            }      
        } 
        else {            
            cerr << "cannot open file " << argv[i] << endl;            
            ++fail_count;        
        }    
    }    
    
    return fail_count;
}