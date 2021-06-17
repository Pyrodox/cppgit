#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <iomanip>
#include <stdexcept>
#include <ios>
#include <vector>
#include "grade.h"
#include "Student_info.h"
using std::cout; using std::list; using std::endl; using std::max; using std::string; using std::vector;
using std::sort; using std::streamsize; using std::setprecision; using std::domain_error; using std::cin;

bool fgrade(Student_info& s)
{    
    return grade(s) < 60;
}

list<Student_info> extract_fails(list<Student_info>& students)
{
    list<Student_info> fail;    
    list<Student_info>::iterator iter = students.begin();    
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

vector<Student_info> extract_fails(vector<Student_info>& students)
{
    vector<Student_info> fail;    
    vector<Student_info>::iterator iter = students.begin();    
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

int printgrades(string::size_type &maxlen, list<Student_info> students)
{
    students.sort(compare);

    list<Student_info> fail = extract_fails(students);

    cout << "Passing: " << endl;

    double final_grade;
    
    for (auto i : students) {
        cout << i.name << string(maxlen - i.name.size() + 1, ' ');

        try {
            final_grade = grade(i);
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade << setprecision(prec);
        } 
        catch (domain_error e) {
            cout << e.what();
        }

        cout << endl;
    }
    
    return 0;
}

int printgrades(string::size_type &maxlen, vector<Student_info> students)
{
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
        } 
        catch (domain_error e) {
            cout << e.what();
        }

        cout << endl;
    }
    
    return 0;
}

int main()
{
    cout << "vector or list? (default is list): ";
    string vec_or_lst;
    cin >> vec_or_lst;

    if (vec_or_lst.compare("vector") == 0) {
        typedef list<Student_info> infolst;
        
        infolst students;
        Student_info record;
        string::size_type maxlen = 0;

        cout << "Enter name, midterm grade, finals grade, and homework grades." << endl;

        while (read(cin, record)) {
            maxlen = max(maxlen, record.name.size());
            students.push_back(record);
        }

        printgrades(maxlen, students);
    }
    else {
        typedef vector<Student_info> infolst;
        
        infolst students;
        Student_info record;
        string::size_type maxlen = 0;

        cout << "Enter name, midterm grade, finals grade, and homework grades." << endl;

        while (read(cin, record)) {
            maxlen = max(maxlen, record.name.size());
            students.push_back(record);
        }

        printgrades(maxlen, students);
    }

    return 0;
}