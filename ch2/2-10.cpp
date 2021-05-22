#include <iostream>

int main() {
    int k =  0;
        while(k != 5) {
            using std::cout; //using std::cout makes it so that cout is reserved for the character output, so you can type cout instead.
            //Also, this using statement is only inside the while loop, so it can't be used for outer scopes.
            cout << "*";
            ++k;
        }
        std::cout << std::endl; //std::cout and std::endl both use the standard library and are part of #include <iostream>, so an std:: statement is needed.
        return 0;
}