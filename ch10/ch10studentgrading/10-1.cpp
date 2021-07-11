#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <iomanip>
#include "Student_info.h"
using std::cout; using std::endl; using std::vector; using std::string;
using std::cin; using std::max; using std::sort; using std::domain_error;
using std::streamsize; using std::setprecision; using std::istream;

Student_info::Student_info() { }
Student_info::Student_info(istream& is) { read(is); }

int main()
{    
    vector<Student_info> students;    
    Student_info record;    
    string::size_type maxlen = 0;    
    // read and store the data    
    while (record.read(cin)) {                      
        //  changed        
        maxlen = max(maxlen, record.name().size());
        //  changed        
        students.push_back(record);    
    }    
    // alphabetize the student records    
    sort(students.begin(), students.end(), compare);    
    // write the names and grades    
    for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
        cout << students[i].name() << string(maxlen + 1 - students[i].name().size(), ' ');        
        try {            
            double final_grade = students[i].grade();     
            // changed            
            streamsize prec = cout.precision();
            string grade;
            if (final_grade >= 90) {
                grade = "A";
            }
            else if (final_grade >= 80) {
                grade = "B";
            }
            else if (final_grade >= 70) {
                grade = "C";
            }
            else if (final_grade >= 60) {
                grade = "D";
            }
            else {
                grade = "F";
            }
            cout << setprecision(3) << grade << setprecision(prec) << endl;        
        } 
        catch (domain_error e) {            
            cout << e.what() << endl;        
        }    
    }    
    
    return 0;
}