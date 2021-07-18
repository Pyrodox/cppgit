#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include "vec.h"
#include "grade.h"
#include "Student_info.h"
using std::cin; using std::setprecision; using std::cout; using std::sort; using std::domain_error;
using std::streamsize; using std::endl; using std::string; using std::max; using std::istream;

Student_info::Student_info() { }
Student_info::Student_info(istream& is) { read(is); }

int main()
{    
    Vec<Student_info> students;    
    Student_info record;    
    string::size_type maxlen = 0;

    while (record.read(cin)) {
        maxlen = max(maxlen, record.name().size());        
        students.push_back(record);    
    }   
    
    sort(students.begin(), students.end(), compare);   
    
    for (Vec<Student_info>::size_type i = 0; i != students.size(); ++i) {
        cout << students[i].name() << string(maxlen + 1 - students[i].name().size(), ' ');

        if (students[i].valid()) {
            double final_grade = students[i].grade();
            streamsize prec = cout.precision();            
            cout << setprecision(3) << final_grade << setprecision(prec);        
        }          
        
        cout << endl;    
    }    
    
    return 0;
}