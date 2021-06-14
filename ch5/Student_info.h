#ifndef GUARD_STUDENT_INFO_H
#define GUARD_STUDENT_INFO_H

#include <iostream>
#include <string>
#include <vector>

struct Student_info_details {;
    double midterm, final;
    std::string name;
    std::vector<double> homework;
};

struct Student_info {;
    double final_grade;
};

bool compare(const Student_info_details&, const Student_info_details&);
std::istream& read(std::istream&, Student_info_details&);
std::istream& read_hw(std::istream&, std::vector<double>&);

#endif