#include <stdexcept>
#include <vector>
#include "grade.h"
#include "median.h"
#include "Student_info.h"

using std::domain_error; using std::vector;

double grade(vector<double> &homework, double &midterm, double &final)
{
    if (homework.size() == 0) {
        throw domain_error("student has done no homework");
    }

    int median1 = 0.2 * midterm + 0.4 * final + 0.4 * median(homework);

    return median1;
}