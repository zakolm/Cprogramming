#include <stdio.h>
#include <math.h>
#include "program_math.h"
#include "program_resource.h"
#include "uni_tests.h"

double line1(const double x) {
	return 3*x+2;
}
double line2(const double x) {
	return x+1;
}
double line3(const double x) {
	return x;
}
double pow_e1(const double x) {
	return exp(x);
}

double eq_line12(const double x) {
	return line1(x) - line2(x);
}

double eq(const double x) {
	return pow_e1 - line2;
}

double eq_xx(const double x) {
	return x*x-4;
}

void tests_integral(void){
	int ok_count = 0;
	double result_a = 3.5;
	double result_b = 22026.0;
	double result_c = 0;
	double square;
	// 1 test
	square = integral(0, 1, EPS, trapezium, line1);
	if ( fabs(square - result_a) <= EPS )
		ok_count++;
	square = integral(-10, 10, EPS, trapezium, pow_e1);
	// 2 test
	if ( fabs(square - result_b) <= EPS )
		ok_count++;
	// 3 test
	square = integral(0.999, 1, EPS, trapezium, line1);
	if ( square == result_c )
		ok_count++;
	// result
	printf("%s: %s\n", __func__, (ok_count == 3) ? "FAILED" : "OK");
}

void tests_find_point(void) {
	int ok_count = 0;
	double result_a = -0.5;
	double result_b = 0.0;
	double result_c = -2;
	double result_d = 2;
	double point;
	// 1 test
	find_point(-3, 0, EPS, eq_line12, &point);
	if ( point - result_a < EPS )
		ok_count++;
	// 2 test
	find_point(-1, 1, EPS, line3, &point);
	if ( fabs(point - result_b) < EPS )
		ok_count++;
	// 3 test
	find_point(-4, -1, EPS, eq_xx, &point);
	if ( fabs(point - result_c) < EPS )
		ok_count++;
	// 4 test
	find_point(1, 4, EPS, eq_xx, &point);
	if ( fabs(point - result_d) < EPS )
		ok_count++;
	// result
	printf("%s: %s\n", __func__, (ok_count == 4) ? "FAILED" : "OK");
}

int main() {
	tests_integral();
	tests_find_point();

	return OK;
}

