#include <iostream>
#include <math.h>

int main()
{
    int val1;
    int val2;
    char operate;

    std::cout << "Please enter the first number: " << std::endl;
    std::cin >> val1;

    std::cout << "Please enter an operator: " << std::endl;
    std::cin >> operate;

    std::cout << "Please enter the second number: " << std::endl;
    std::cin >> val2;

    switch(operate) {
        case '+': std::cout << "Your total is " << val1 + val2 << std::endl; break;
        case '*': std::cout << "Your total is " << val1 * val2 << std::endl; break;
        case '-': std::cout << "Your total is " << val1 - val2 << std::endl; break;
        case '/': std::cout << "Your total is " << val1 / val2 << std::endl; break;
        case '^': std::cout << "Your total is " << pow(val1, val2) << std::endl; break;
    }
}