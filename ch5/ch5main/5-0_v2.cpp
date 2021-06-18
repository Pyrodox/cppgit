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
//pre 5-6 main change (using resize instead of erase): 382.951 ms, post 5-6 main change (using resize instead of erase): 258.873 ms
bool fgrade(Student_info& s)
{    
    return grade(s) < 60;
}

vector<Student_info> extract_fails(vector<Student_info>& v)
{    
    vector<Student_info> fail, vcopy;    
    vector<Student_info>::size_type i = 0;
    int newvecsz = 0;
    
    // invariant:elements [0, i) of students represent passing grades     
    while (i != v.size()) {         
        if (fgrade(v[i])) {
            fail.push_back(v[i]);
        }
        else {
            newvecsz++;
            vcopy.push_back(v[i]);
        }

        i++;
    }

    v.insert(v.begin(), vcopy.begin(), vcopy.begin() + newvecsz);
    v.resize(newvecsz);
    
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

    auto end = std::chrono::steady_clock::now();
    auto diff = end - start;

    cout << std::chrono::duration <double, milli> (diff).count() << " ms";

    return 0;
}