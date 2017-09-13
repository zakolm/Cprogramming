#include <math.h>
#include "program_resource.h"

double function_first(const double x) { // exp(x)
    return exp(x);
}
double function_second(const double x) { // exp(-x+2)
    return exp(-x+2);
}
double function_third(const double x) { // 3*x+2
	return 3*x+2;
}

double eq12(const double x) {
	return function_first(x) - function_second(x);
}
double eq13(const double x) {
	return function_first(x) - function_third(x);
}
double eq23(const double x) {
	return function_second(x) - function_third(x);
}
