#include <iostream>
#include <string>
int main()
{    
    std::cout << "What is your name? ";    
    std::string name;
    std::cin >> name;    
    std::cout << "Hello, " << name              
              << std::endl << "And what is yours? ";    
    std::cin >> name;    
    std::cout << "Hello, " << name              
              << "; nice to meet you too!" << std::endl;
    return 0;
}
/*My prediction is this: the program will take only Samuel for the first std::cin >> bame, because std::cin ignores whitespaces, and then std::cin will
give Beckett to the second part, which makes the user not be able to enter another input. I was right.*/