#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "9_5SI.h"
using std::cin; using std::setprecision; using std::cout; using std::sort; using std::domain_error; using std::remove_copy_if; using std::copy_if;
using std::streamsize; using std::endl; using std::string; using std::max; using std::vector; using std::istream; using std::back_inserter;

Student_info::Student_info() { }
Student_info::Student_info(istream& is) { read(is); }

bool isfail(const Student_info& examinee)
{
    return examinee.finalgrade < 60;
}

int main()
{    
    vector<Student_info> students;    
    Student_info record;    
    string::size_type maxlen = 0;

    while (record.read(cin)) {
        maxlen = max(maxlen, record.name().size());        
        students.push_back(record);    
    }   
    
    sort(students.begin(), students.end(), compare);
    vector<Student_info> fail;
    copy_if(students.begin(), students.end(), back_inserter(fail), isfail);
    students.erase(remove_if(students.begin(), students.end(), isfail), students.end());
    
    cout << "Passing:\n";
    for (vector<Student_info>::const_iterator it = students.begin(); it != students.end(); ++it) {
        cout << it->name() << string(maxlen + 1 - it->name().size(), ' ');
        streamsize prec = cout.precision();            
        cout << setprecision(3) << "P" << setprecision(prec);        

        cout << endl;    
    }
    
    cout << "\nFail:\n";
    for (vector<Student_info>::const_iterator it = fail.begin(); it != fail.end(); ++it) {
        cout << it->name() << string(maxlen + 1 - it->name().size(), ' ');
        streamsize prec = cout.precision();            
        cout << setprecision(3) << "F" << setprecision(prec);        

        cout << endl;    
    }
    
    return 0;
}