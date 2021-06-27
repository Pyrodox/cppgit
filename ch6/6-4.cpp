#include <iostream>
#include <vector>
#include <algorithm>
using std::cout; using std::vector; using std::copy;

int main()
{
    //First way: Make vector v's size 10.
    //Pros: faster, succint code, probably best way to do it.
    //Cons: you can only use v(10) when instantiating v; otherwise you'll have to use .resize() which takes up more room.
    vector<int> u(10, 100);
    vector<int> v(10);
    copy(u.begin(), u.end(), v.begin());

    for (auto line : v) {
        cout << line << "\n";
    }

    //Second way: insert some arbitrary values and then copy.
    //Pros: code remains same whether instantiating v or not; you'll just have to instantiate it above and then clear.
    //Cons: Way Slower, more code than necessary, v.clear() can be unnecessary.
    v.clear();

    for (int i = 0; i < u.size(); i++) {
        v.push_back(1);
        
    
    copy(u.begin(), u.end(), v.begin());

    for (auto line : v) {
        cout << line << "\n";
    }

    return 0;
}