#ifndef GUARD_Student_info
#define GUARD_Student_info

#include <iostream>
#include <string>
#include "vec.h"

class Student_info {
    public:
        Student_info();
        Student_info(std::istream&);
        //bool valid() { return !homework.empty(); }
        std::istream& read(std::istream&);
        std::string name() const { return n; }
        double grade() const;
        double finalgrade;
                           
    private:    
        std::string n;    
        double midterm, final;    
        Vec<double> homework;                 
};

bool compare(const Student_info&, const Student_info&);
std::istream& read(std::istream&);
std::istream& read_hw(std::istream&, Vec<double>&);

#endif