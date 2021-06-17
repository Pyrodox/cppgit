#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <stdexcept>
#include <ios>
#include <chrono>
#include "grade.h"
#include "Student_info.h"
using std::cout; using std::vector; using std::endl; using std::max; using std::string; using std::milli;
using std::sort; using std::streamsize; using std::setprecision; using std::domain_error; using std::cin;
//Note: Times always vary.
//10 inputs: 187.234 ms, 1000 inputs: 4280.88 ms, 10000 inputs: 56626.7 ms
bool fgrade(Student_info& s)
{    
    return grade(s) < 60;
}

vector<Student_info> extract_fails(vector<Student_info>& students)
{    
    vector<Student_info> fail;    
    vector<Student_info>::iterator iter = students.begin();    
    while (iter != students.end()) {
        if (fgrade(*iter)) {            
            fail.push_back(*iter);            
            iter = students.erase(iter);        
        } 
        else {
            ++iter;
        }    
    }
    
    return fail;
}

int main()
{
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;

    cout << "Enter name, midterm grade, finals grade, and homework grades." << endl;

    auto start = std::chrono::steady_clock::now();

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

    auto end = std::chrono::steady_clock::now();
    auto diff = end - start;

    cout << std::chrono::duration <double, milli> (diff).count() << " ms";

    return 0;
}