#include <iostream>
#include <string>

int main() 
{
    const int pad = 1;
    const int rows = pad * 2 + 3;

    std::cout << std::endl;
    int r = 0;

    while (r != rows) {
        std::cout << std::endl;
        ++r;
    }

    return 0;
}