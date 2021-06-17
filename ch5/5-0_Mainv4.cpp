#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <stdexcept>
#include <ios>
#include <list>
#include "grade.h"
#include "Student_info.h"
using std::cout; using std::endl; using std::max; using std::string; using std::list;
using std::sort; using std::streamsize; using std::setprecision; using std::domain_error; using std::cin;

bool fgrade(const Student_info_details& s)
{    
    return grade(s) < 60;
}

list<Student_info_details> extract_fails(list<Student_info_details>& students)
{
    list<Student_info_details> fail;    
    list<Student_info_details>::iterator iter = students.begin();    
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
    list<Student_info_details> students;
    Student_info_details record;
    Student_info record2, record3;
    string::size_type maxlen = 0;

    cout << "Enter name, midterm grade, finals grade, and homework grades." << endl;
    while (read(cin, record)) {
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
    }

    students.sort(compare);

    list<Student_info_details> fail = extract_fails(students);

    cout << "Passing: " << endl;

    for (auto line : students) {

        cout << line.name << string(maxlen + 1 - line.name.size(), ' ');

        try {
            record2.final_grade = grade(line);
            streamsize prec = cout.precision();
            cout << setprecision(3) << record2.final_grade << setprecision(prec);
        } catch (domain_error e) {
            cout << e.what();
        }
        cout << endl;
    }

    cout << "Failed: " << endl;

    for (auto line : fail) {
        cout << line.name << string(maxlen + 1 - line.name.size(), ' ');

        try {
            record3.final_grade = grade(line);
            streamsize prec = cout.precision();
            cout << setprecision(3) << record3.final_grade << setprecision(prec);
        } catch (domain_error e) {
            cout << e.what();
        }
        cout << endl;
    }

    return 0;
}