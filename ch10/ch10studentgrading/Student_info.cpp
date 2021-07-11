#include "Student_info.h"
#include "grade.h"

using std::istream;  
using std::vector;

bool compare(const Student_info& x, const Student_info& y)
{    
    return x.name() < y.name();
}

istream& Student_info::read(istream& in)
{    
    in >> n >> midterm >> final;    
    read_hw(in, homework);
    finalgrade = ::grade(midterm, final, homework);    
    
    return in;
}

istream& read_hw(istream& in, vector<double>& hw)
{    if (in) {
        hw.clear();

        double x;        
        while (in >> x)            
            hw.push_back(x);             
        
        in.clear();    
}    
    
    return in;
}