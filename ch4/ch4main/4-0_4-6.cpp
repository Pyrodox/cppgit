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

int main()
{
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;

    cout << "Enter name, midterm grade, finals grade, and homework grades.\n" << endl;
    while (read(cin, record)) {
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
    }

    sort(students.begin(), students.end(), compare);

    cout << endl;
    for (int i = 0; i < students.size(); ++i) {
        cout << students[i].name << ":" << string(maxlen - students[i].name.size() + 1, ' ');

        try {
            streamsize prec = cout.precision();
            cout << setprecision(3) << students[i].final_grade << setprecision(prec) << endl;
        }
        catch (domain_error e) {
            cout << e.what();
        }
    }

    return 0;
}