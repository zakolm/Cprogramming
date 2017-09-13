#ifndef __PROGRAM_MATH__H__

#define __PROGRAM_MATH__H__

typedef double (*func_t)(double);
typedef double (*method_t)(double, double, int, func_t);

double integral(double a, double b, double eps, method_t meth, func_t func);
double trapezium(double a, double b, int n, func_t func);
void find_point(double lht_point, double rht_point, const double eps, func_t eq, double* point);
void twice_points_min_max(double* min, double* max, const double* point_first, const double* point_second);

#endif //__PROGRAM_MATH__H__
