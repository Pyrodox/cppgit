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

bool fgrade(const Student_info_details& s)
{    
    return grade(s) < 60;
}

vector<Student_info_details> extract_fails(vector<Student_info_details>& students)
{    
    vector<Student_info_details> fail;    
    vector<Student_info>::size_type i = 0;    
    
    // invariant:elements [0, i) of students represent passing grades     
    while (i != students.size()) {         
        if (fgrade(students[i])) {
            fail.push_back(students[i]);            
            students.erase(students.begin() + i);        
        } 
        else {
            ++i;
        }    
    }    
    
    return fail;
}

int main()
{
    vector<Student_info_details> students;
    Student_info_details record;
    Student_info record2, record3;
    string::size_type maxlen = 0;

    cout << "Enter name, midterm grade, finals grade, and homework grades." << endl;
    while (read(cin, record)) {
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
        cout << "bruh" << endl;
    }

    sort(students.begin(), students.end(), compare);

    vector<Student_info_details> fail = extract_fails(students);

    cout << "Passing: " << endl;

    for (vector<Student_info_details>::size_type i = 0;
        i != students.size(); ++i) {

        cout << students[i].name << string(maxlen + 1 - students[i].name.size(), ' ');

        try {
            record2.final_grade = grade(students[i]);
            streamsize prec = cout.precision();
            cout << setprecision(3) << record2.final_grade << setprecision(prec);
        } catch (domain_error e) {
            cout << e.what();
        }
        cout << endl;
    }

    cout << "Failed: " << endl;

    for (int i = 0; i < fail.size(); i++) {
        cout << fail[i].name << string(maxlen + 1 - fail[i].name.size(), ' ');

        try {
            record3.final_grade = grade(fail[i]);
            streamsize prec = cout.precision();
            cout << setprecision(3) << record3.final_grade << setprecision(prec);
        } catch (domain_error e) {
            cout << e.what();
        }
        cout << endl;
    }

    return 0;
}