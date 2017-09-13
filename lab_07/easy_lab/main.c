#include <stdio.h>
#include <math.h>
#include "program_math.h"
#include "program_resource.h"

/*
 * Скорее всего потребуется создать 3 файла:
 * 1) program_math.c: содержит функции integral(), trapezium(), find_point(), twice_points_min_max().
 * 2) program_resource.c: содержит функции: function_first(), function_second(), function_third(), eq12(), eq13(), eq23().
 * Так же заголовочный файл "program_resource.h" будет содержать константы.
 * 3) main.c: содержит функции: main().
 * Проверка assert должна быть в: integral(), trapezium(), find_point().
 * Также создать тесты для функций: integral(), trapezium(), find_point().
 */

int main(void) {
	double point_first, point_second, point_third;
	find_point(START_POINT, STOP_POINT, EPS, eq12, &point_first);
	find_point(START_POINT, STOP_POINT, EPS, eq13, &point_second);
	find_point(START_POINT, STOP_POINT, EPS, eq23, &point_third);
	//printf("[DBG]print1 point1 = %f \t point2 = %f \t point3 = %f\n", point_first, point_second, point_third);

	double My_Result_Square, Square1, Square2, Square3, min, max;
	// Find the square of Function1 from point_first to point_second.
	twice_points_min_max(&min, &max, &point_first, &point_second);
	Square1 = integral(min, max, EPS, trapezium, function_first);
	// Find the square of Function2 from point_first to point_third.
	twice_points_min_max(&min, &max, &point_first, &point_third);
	Square2 = integral(min, max, EPS, trapezium, function_second);
	// Find the square of Function3 from point_second to point_third.
	twice_points_min_max(&min, &max, &point_second, &point_third);
	Square3 = integral(min, max, EPS, trapezium, function_third);
	// Find the square of the triangle.
	My_Result_Square = ((point_second<point_first && point_first<point_third) || (point_second>point_first && point_first>point_third)) ?
		fabs(Square1+Square2-Square3) : ((point_first<point_second && point_second<point_third) || (point_first>point_second && point_second>point_third)) ?
				fabs(Square1+Square3-Square2) : fabs(Square2+Square3-Square1);

	//printf("[DBG]print2 square1 = %f \t square2 = %f \t square3 = %f\n[DBG]print3 result_square = %f", Square1, Square2, Square3, My_Result_Square);
	printf("Result square = %.4f", My_Result_Square);
    return OK;
}
