#include <stdexcept>
#include "vec.h"
#include "grade.h"
#include "median.h"
#include "Student_info.h"

using std::domain_error;

double Student_info::grade() const
{    
    return finalgrade;
}

double grade(double midterm, double final, Vec<double> homework)
{
    if (homework.size() == 0) {
        throw domain_error("student has done no homework");
    }

    int median1 = 0.2 * midterm + 0.4 * final + 0.4 * median(homework);

    return median1;
}