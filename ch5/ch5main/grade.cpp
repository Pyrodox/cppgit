#include <stdexcept>
#include "grade.h"
#include "median.h"
#include "Student_info.h"

using std::domain_error; using std::vector;

double grade(Student_info &s)
{
    if (s.homework.size() == 0) {
        throw domain_error("student has done no homework");
    }

    int median1 = 0.2 * s.midterm + 0.4 * s.final + 0.4 * median(s.homework);

    return median1;
}