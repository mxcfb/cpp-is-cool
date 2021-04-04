#ifndef GUARD_grade_h
#define GUARD_grade_h

#include "Core.h"
#include "Vec.h"

double grade(double midterm, double final, double homework);
double grade(double midterm, double final, const Vec<double> & hw);
bool fgrade(const Core &s);

#endif
