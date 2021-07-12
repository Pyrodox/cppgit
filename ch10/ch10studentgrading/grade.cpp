#include <stdexcept>
#include <vector>
#include "grade.h"
#include "median.h"
#include "Student_info.h"

using std::domain_error; using std::vector;

double Student_info::grade() const
{    
    return finalgrade;
}

double grade(double midterm, double final, vector<double> homework)
{
    if (homework.size() == 0) {
        throw domain_error("student has done no homework");
    }

    double median1 = 0.2 * midterm + 0.4 * final + 0.4 * median(2.1, homework.size(), homework, homework.begin());

    return median1;
}