#include "Student_info.h"
#include "grade.h"
using std::istream; using std::vector; using std::cout; using std::endl;

bool compare(const Student_info &x, const Student_info &y)
{
    return x.name < y.name;
}

istream& read(istream& is, Student_info &s)
{
    cout << "Enter your name: ";
    is >> s.name;
    cout << endl;

    double midterm;
    cout << "Enter midterm: ";
    is >> midterm; 
    cout << endl;

    double final;
    cout << "Enter final: ";
    is >> final;
    cout << endl;

    vector<double> homework;
    read_hw(is, homework);

    if (is) {
        s.final_grade = grade(homework, midterm, final);
    }
    
    return is;
}

istream& read_hw(istream& in, vector<double>& hw)
{
    if (in) {
        hw.clear();

        double x;
        cout << "Enter homework (separate by enter or whitespaces): ";
        cout << endl;
        while (in >> x) {
            hw.push_back(x);
        }

        in.clear();
    }

    return in;
}