#include <math.h>
#include <assert.h>
#include "program_math.h"

typedef double (*func_t)(double);
typedef double (*method_t)(double, double, int, func_t);

// Computing of the Integral. We use method(meth) trapezium.
double integral(double a, double b, double eps, method_t meth, func_t func) {
    assert(a < b);
    assert(0 < eps && eps < 1);
    assert(meth);
    assert(func);

    int n = 10;
    double prev, cur = meth(a, b, n, func);

    do
    {
        prev = cur;

        n *= 2;
        cur = meth(a, b, n, func);
    }
    while (fabs((cur - prev) / cur) > eps);

    //printf("[DBG]%d\n", n);

    return cur;
}

// n - number of points
double trapezium(double a, double b, int n, func_t func) {
    assert(a < b);
    assert(n > 1);
    assert(func);

    double h = (b - a) / (n - 1);
    double x = a + h;
    double s = (func(a) + func(b)) / 2.0;

    for (int i = 1; i < n - 1; i++)
    {
        s += func(x);
        x += h;
    }

    return s * h;
}

// Search the point of intersection.
void find_point(double lht_point, double rht_point, const double eps, func_t eq, double* point) {
	assert(lht_point < rht_point);
	assert(0 < eps && eps < 1);
	assert(eq);
	double item = 0;
	while ( (rht_point - lht_point) > eps ) {
		item = (rht_point + lht_point)/2;
		if ( eq(item)*eq(rht_point) < 0 ) {
			lht_point = item;
		} else {
			rht_point = item;
		}
	}
	*point = (rht_point + lht_point)/2;
}

void twice_points_min_max(double* min, double* max, const double* point_first, const double* point_second) {
	*min = (*point_first < *point_second) ? *point_first : *point_second;
	*max = (*point_first > *point_second) ? *point_first : *point_second;
}
