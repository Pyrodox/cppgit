#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <numeric>
#include "grade.h"
#include "Student_info.h"
#include "median.h"
using std::cin; using std::cout; using std::sort; using std::remove_copy; using std::domain_error; 
using std::back_inserter; using std::ostream; using std::endl; using std::string; using std::max;
using std::vector; using std::transform; using std::stable_partition; using std::find;

double grade_aux(const Student_info& s)
{
    try {         
        return grade(s);    
    } 
    catch (domain_error) {        
        return grade(s.midterm, s.final, 0);    
    }
}

double average(const vector<double>& v)
{    
    return accumulate(v.begin(), v.end(), 0.0) / v.size();
}

double average_grade(const Student_info& s)
{    
    return grade(s.midterm, s.final, average(s.homework));
}

double optimistic_median(const Student_info& s)
{
    vector<double> nonzero;    
    remove_copy(s.homework.begin(), s.homework.end(), back_inserter(nonzero), 0);    
    
    if (nonzero.empty()) {
        return grade(s.midterm, s.final, 0);
    }    
    else {        
        return grade(s.midterm, s.final, median(nonzero));
    }    
}
//6-5 easy
//6-6 done as well
template<class D, class V, class S>D analysis(const V& students, D func(const S&))
{
    vector<D> grades;
    transform(students.begin(), students.end(), back_inserter(grades), func);

    return median(grades);
}

void write_analysis(ostream& out, const string& name, const vector<Student_info>& did, const vector<Student_info>& didnt, 
double func(const Student_info&))
{   
    out << name << ": median(did) = " << analysis(did, func) << ", median(didnt) = " << analysis(didnt, func) << endl;
}

bool pgrade(Student_info& s)
{    
    return grade(s) >= 80;
}
//6-8
vector<Student_info> at_least_b(vector<Student_info>& students) 
{    
    vector<Student_info>::iterator iter = stable_partition(students.begin(), students.end(), pgrade);    
    vector<Student_info> lessthanb(iter, students.end());    
    students.erase(iter, students.end());

    return lessthanb;
}
//6-7
void did_or_not(vector<Student_info>& did, vector<Student_info>& didnt, Student_info& student)
{
    if (find(student.homework.begin(), student.homework.end(), 0) != student.homework.end()) {
        didnt.push_back(student);
    }
    else {
        did.push_back(student);
    }
}

int main()
{
    vector<Student_info> students;

    vector<Student_info> did, didnt;
    Student_info student;

    while (read(cin, student)) {
        did_or_not(did, didnt, student);
        students.push_back(student);
    }
    
    sort(students.begin(), students.end(), compare);   

    if (did.empty()) {    
        cout << "No student did all the homework!" << endl;    

        return 1;
    }

    if (didnt.empty()) {    
        cout << "Every student did all the homework!" << endl;    
    
        return 1;
    }

    at_least_b(students);
    cout << "students who scored at least a b" << endl;
    for (auto line : students) {
        cout << line.name << endl;
    }
    
    write_analysis(cout, "median", did, didnt, grade_aux);    
    write_analysis(cout, "average", did, didnt, average_grade);    
    write_analysis(cout, "median of homework turned in", did, didnt, optimistic_median);
    
    return 0;
}