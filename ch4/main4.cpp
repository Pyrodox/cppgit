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
//4-1, Yes it works. If there's an issue, I'll go to Google and try to search the error up.
//4-6 modified (4-0 is done as well obviously)
int main()
{
    vector<Student_info_details> students;
    Student_info_details record;
    Student_info record2;
    string::size_type maxlen = 0;

    cout << 1;
    cout << "Enter name, midterm grade, finals grade, and homework grades." << endl;
    while (read(cin, record)) {
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
    }

    sort(students.begin(), students.end(), compare);

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
    return 0;
}