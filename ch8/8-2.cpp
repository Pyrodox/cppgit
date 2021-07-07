#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <string>
#include <numeric>
#include <string>
using std::equal; using std::find; using std::copy; using std::remove_copy; using std::transform;
using std::accumulate; using std::search; using std::find_if; using std::remove_copy; using std::remove;
using std::partition; using std::cout; using std::endl; using std::vector; using std::back_inserter;
using std::string;
//input iterators, output iterators, forward and bidirectional iterators, bidirectional iterators, and random-access iterators
int add(int i)
{
    return ++i;
}

bool even(int i)
{
    return i % 2 == 0;
}

bool isten(int i)
{
    return i == 10;
}

int main()
{
    vector<int> a{1, 2, 3};
    vector<int> b{1, 2, 3};
    //equal uses forward and bidirectional and input iterators, likely uses unary *, ==, and ++
    cout << equal(a.begin(), a.end(), b.begin(), b.end()) << endl;
    //find uses input and forward and bidirectional iterators, likely uses unary *, ==, and ++
    string ab = find(a.begin(), a.end(), 1) != a.end() ? "found" : "not found";
    cout << ab << endl;
    //copy uses output and forward and bidirectional iterators, likely uses ++
    copy(a.begin(), a.end(), back_inserter(b));
    //remove_copy uses output and forward and bidirectional iterators, likely uses ++ and unary *
    vector<int> c;
    remove_copy(b.begin(), b.end(), back_inserter(c), 1);
    for (int i = 0; i < c.size(); ++i) {
        cout << c[i] << endl;
    }
    cout << endl;
    //transform uses output, forward and bidirectional iterators, likely uses ++
    transform(a.begin(), a.end(), a.begin(), add);
    for (int i = 0; i < a.size(); ++i) {
        cout << a[i] << endl;
    }
    cout << endl;
    //accumulate uses forward and bidirectional and maybe output iterators, likely uses unary *, ++
    int total = accumulate(a.begin(), a.end(), 0);
    cout << total << endl;
    //search uses forward and bidirectional and maybe input iterators, likely uses unary *, ++, and ==
    ab = search(c.begin(), c.end(), b.begin(), b.end()) != c.end() ? "found" : "not found";
    cout << ab << endl;
    //find_if uses forward and bidirectional and input iterators, likely uses ++ and unary *
    ab = find_if(c.begin(), c.end(), even) != c.end() ? "found" : "not found";
    cout << ab << endl;
    //remove_copy uses forward and bidirectional and output iterators, likely uses ++, unary *, and ==
    vector<int> d{2, 2, 1, 2, 1, 1};
    vector<int> e;
    remove_copy(d.begin(), d.end(), back_inserter(e), 1);
    for (int i = 0; i < e.size(); ++i) {
        cout << e[i] << endl;
    }
    cout << endl;
    //remove uses forward and bidirectional and output iterators, likely uses ++, ==, and unary *
    vector<int> f{1, 1, 1, 10, 5, 10, 5, 4, 5, 6, 7, 2, 10, 10, 1, 3, 6, 3, 5, 10, 10};
    remove(f.begin(), f.end(), 10);
    for (int i = 0; i < f.size(); ++i) {
        cout << f[i] << endl;
    }
    cout << endl;
    //partition uses forward, maybe bidrectional, output, and maybe random-access iterators, likely uses ++, ==, and unary *
    partition(f.begin(), f.end(), isten);
    for (int i = 0; i < f.size(); ++i) {
        cout << f[i] << endl;
    }

    return 0;
}