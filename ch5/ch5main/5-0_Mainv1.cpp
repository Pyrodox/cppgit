#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <stdexcept>
#include <ios>
#include "grade.h"
#include "Student_info.h"
using std::cout; using std::vector; using std::endl; using std::max; using std::string;
using std::sort; using std::streamsize; using std::setprecision; using std::domain_error; using std::cin;

bool fgrade(Student_info& s)
{    
    return grade(s) < 60;
}

vector<Student_info> extract_fails(vector<Student_info>& students)
{    
    vector<Student_info> pass, fail;    
    for (auto i : students)
        if (fgrade(i)) {           
            fail.push_back(i);
        }       
        else {           
            pass.push_back(i);
        }

    students = pass;

    return fail;
}

int main()
{
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;

    cout << "Enter name, midterm grade, finals grade, and homework grades." << endl;
    while (read(cin, record)) {
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
    }

    sort(students.begin(), students.end(), compare);

    vector<Student_info> fail = extract_fails(students);

    cout << "Passing: " << endl;

    double final_grade;
    for (auto i : students) {
        cout << i.name << string(maxlen - i.name.size() + 1, ' ');

        try {
            final_grade = grade(i);
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade << setprecision(prec);
        } catch (domain_error e) {
            cout << e.what();
        }
        cout << endl;
    }

    cout << "Failed: " << endl;

    for (auto i : fail) {
        cout << i.name << string(maxlen - i.name.size() + 1, ' ');

        try {
            final_grade = grade(i);
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade << setprecision(prec);
        } catch (domain_error e) {
            cout << e.what();
        }
        cout << endl;
    }

    return 0;
}