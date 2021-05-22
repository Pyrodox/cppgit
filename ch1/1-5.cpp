#include <iostream>
#include <string>
int main()
{    
    { std::string s = "a string";    
     std::string x = s + ", really";    
    std::cout << s << std::endl;     
    std::cout << x << std::endl;    
    }    
    return 0;
}
//At first, no, because the innermost brackets contain variable x, which means that the outer scopes cannot x. Simply removing those brackets will be a fix.