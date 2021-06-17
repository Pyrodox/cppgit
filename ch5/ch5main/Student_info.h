#ifndef GUARD_STUDENT_INFO_H
#define GUARD_STUDENT_INFO_H

#include <iostream>
#include <string>
#include <vector>

struct Student_info {;
    double midterm, final;
    std::string name;
    std::vector<double> homework;
};

bool compare(const Student_info&, const Student_info&);
std::istream& read(std::istream&, Student_info&);
std::istream& read_hw(std::istream&, std::vector<double>&);

#endif