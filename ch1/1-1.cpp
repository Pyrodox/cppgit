#include <iostream>

int main()
{
    const std::string hello = "Hello";
    const std::string message = hello + ", world" + "!";

    return 0;
}
//Yes, because variables hello and message are not being changed.