#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include "vec.h"
#include "9_5SI.h"
using std::cin; using std::setprecision; using std::cout; using std::sort; using std::domain_error; using std::remove_copy_if; using std::copy_if;
using std::streamsize; using std::endl; using std::string; using std::max; using std::istream; using std::back_inserter;

Student_info::Student_info() { }
Student_info::Student_info(istream& is) { read(is); }

bool isfail(const Student_info& examinee)
{
    return examinee.finalgrade < 60;
}

template <class T> typename Vec<T>::iterator remove_if2(T* p1, T* p2, bool pred)
{
    typename Vec<T>::iterator temp = p1;
    while (p1 != p2) {
        if (!isfail(*p1)) {
            *temp = *p1;
            ++temp;
        }
        ++p1;
    }

    return temp;
}

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
    Vec<Student_info> fail;
    copy_if(students.begin(), students.end(), back_inserter(fail), isfail);
    students.erase(remove_if2(students.begin(), students.end(), isfail), students.end());
    cout << "why\n";
    cout << "Passing:\n";
    for (Vec<Student_info>::const_iterator it = students.begin(); it != students.end(); ++it) {
        cout << it->name() << string(maxlen + 1 - it->name().size(), ' ');
        streamsize prec = cout.precision();            
        cout << setprecision(3) << "P" << setprecision(prec);        

        cout << endl;    
    }
    
    cout << "\nFail:\n";
    for (Vec<Student_info>::const_iterator it = fail.begin(); it != fail.end(); ++it) {
        cout << it->name() << string(maxlen + 1 - it->name().size(), ' ');
        streamsize prec = cout.precision();            
        cout << setprecision(3) << "F" << setprecision(prec);        

        cout << endl;    
    }
    
    return 0;
}