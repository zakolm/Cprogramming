#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "array.h"
#include "constant.h"

#define name __func__

void check_scan_file(void);
//void check_work_array(void);

int main(void)
{
	check_scan_file();	
	return OK;
}

void check_scan_file(void)
{
	int ok_count = 0;
	int number_test = 0;
	
	//test 1
	{
		number_test++;
		FILE * file = fopen("in_1.txt", "r");
		double **data;
		int rows  = 0;
		int cols = 0;
		int rc = scan_file(file, &data, &rows, &cols);
		if (!rc && rows == 3 && cols == 3)
		{
			ok_count++;
		}
		else
		{
			printf("test_scan_file: error in %d test", number_test);
		}
		free_array(data, rows);
		fclose(file);
	}
	
	//test 2
	{
		number_test++;
		FILE * file = fopen("in_4.txt", "r");
		double **data;
		int rows  = 0;
		int cols = 0;
		int rc = scan_file(file, &data, &rows, &cols);
		if (rc)
		{
			ok_count++;
		}
		else
		{
			printf("test_scan_file: error in %d test", number_test);
		}
		fclose(file);
	}
	
	//result
	printf("test %s is %s", name, (ok_count == number_test) ? "OK" : "FAILD");
}