#include "9_5SI.h"
#include "vec.h"

using std::istream;  

bool compare(const Student_info& x, const Student_info& y)
{    
    return x.name() < y.name();
}

double grade(double midterm, double final)
{
    return (midterm + final) / 2;
}

istream& Student_info::read(istream& in)
{    
    in >> n >> midterm >> final;    
    finalgrade = grade(midterm, final);    
    
    return in;
}