#ifndef GUARD_9_5SI
#define GUARD_9_5SI

#include <iostream>
#include <string>
#include "vec.h"

class Student_info {
    public:
        Student_info();
        Student_info(std::istream&);
        std::istream& read(std::istream&);
        std::string name() const { return n; }
        double finalgrade;
                           
    private:    
        std::string n;    
        double midterm, final;                     
};

bool compare(const Student_info&, const Student_info&);
double grade(double, double);
std::istream& read(std::istream&);

#endif