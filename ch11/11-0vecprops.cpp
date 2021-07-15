#include <iostream>
#include <vector>
#include <string>
using std::cout; using std::vector;
using std::string;

class Student_info {
    public:
        string name() {
            return "name placeholder";
        };
};

int main()
{
    // construct a vector
    vector<Student_info> vs;        
    // empty vector
    vector<double> v(100);
    vector<Student_info> v2(10);        
    //  vector with 100 elements
    vs.insert(vs.begin(), v2.begin(), v2.end());
    // obtain the names of the types used by the vector
    vector<Student_info>::const_iterator b, e;
    vector<Student_info>::size_type i = 0;
    // use size and the index operator to look at each element in the vector
    for (i = 0; i != vs.size(); ++i) {
        cout << vs[i].name();
    } 
    // return iterators positioned on the first and one past the last element
    b = vs.begin(); e = vs.end();

    return 0;
}