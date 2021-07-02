#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "grade.h"
#include "Student_info.h"
#include <list>
using std::cin; using std::setprecision; using std::cout; using std::sort; using std::domain_error;
using std::streamsize; using std::endl; using std::string; using std::max; using std::vector; using std::list;

int main()
{    
    vector<Student_info> students;    
    Student_info record;    
    string::size_type maxlen = 0;

    while (read(cin, record)) {
        maxlen = max(maxlen, record.name.size());        
        students.push_back(record);    
    }   
    
    sort(students.begin(), students.end(), compare);   
    
    list<Student_info> a, b, c, d, f;

    for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
        //cout << students[i].name << string(maxlen + 1 - students[i].name.size(), ' ');
               
        try {            
            double final_grade = grade(students[i]);

            if (final_grade >= 90) {
                a.push_back(students[i]);
            }
            else if (final_grade >= 80) {
                b.push_back(students[i]);
            }
            else if (final_grade >= 70) {
                c.push_back(students[i]);
            }
            else if (final_grade >= 60) {
                d.push_back(students[i]);
            }
            else {
                f.push_back(students[i]);
            }     
        } 
        catch (domain_error e) {            
            cout << e.what();        
        }        
        
        cout << endl;    
    }

    list<list<Student_info> > all{a, b, c, d, f};
    list<string> letterg{"A: ", "B: ", "C: ", "D: ", "F: "};
    list<string>::const_iterator movethroughgrades = letterg.begin();

    for (list<list<Student_info> >::iterator it = all.begin(); it != all.end(); ++it) {
        cout << *movethroughgrades;
        ++movethroughgrades;
        
        for (list<Student_info>::iterator it2 = it->begin(); it2 != it->end(); ++it2) {
            cout << it2->name << string(maxlen + 1 - it2->name.size(), ' ');
            double final_grade = grade(*it2);
            if (it2 != --(it->end())) {
                cout << final_grade << ", ";
            }
            else {
                cout << final_grade;
            }
        }
        
        cout << endl;
    }
    
    return 0;
}