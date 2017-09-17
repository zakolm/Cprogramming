#ifndef __PROGRAM_RESOURCE__H__

#define __PROGRAM_RESOURCE__H__

#define OK 0
#define EPS 1E-5
#define START_POINT_FIRST_POINT 0.0
#define STOP_POINT_FIRST_POINT 1.0
#define START_POINT_SECOND_POINT 0.0
#define STOP_POINT_SECOND_POINT 1.5
#define START_POINT_THIRD_POINT 1.5
#define STOP_POINT_THIRD_POINT 3.0

double function_first(const double x);
double function_second(const double x);
double function_third(const double x);

double eq12(const double x);
double eq13(const double x);
double eq23(const double x);

#endif //__PROGRAM_RESOURCE__H__
