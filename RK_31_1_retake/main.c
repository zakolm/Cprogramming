#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "array.h"
#include "constant.h"

int work_array(FILE *file, double **data, int row, int col);

int main(int argc, char **argv)
{
	if (argc != 3)
	{
		printf("Input Params!!!\nInput: app.exe file_1.txt file_2.txt\n");
		return ERROR_PARAMS;
	}
	FILE * file = fopen(argv[1], "r");
	if (!file)
	{
		printf("File Error!!!\n");
		return ERROR_FILE;
	}
	double **data;
	int row = 0;
	int col = 0;
	int rc = scan_file(file, &data, &row, &col);
	if (!rc)
	{
		print_list(data, row, col);
		FILE * file_in = fopen(argv[2], "w");
		if (!file_in)
		{
			printf("File Error!!!\n");
			rc = ERROR_FILE;
		}
		else
		{
			printf("\n");
			rc = work_array(file_in, data, row, col);
			if (rc)
			{
				printf("Memory Error!!!\n");
			}
			fclose(file);
		}
		free_array(data, row);
	}
	else
	{
		print_errors(rc);
	}
	
	fclose(file);
	return OK;
}

void scan_sums(double **data, int row, int col, double **sum_data)
{
	double **tmp = data;
	double *sum_tmp = *sum_data;
	for (int i = 0; i < row; ++i)
	{
		double sum = 0;
		for (int j = 0; j < col; ++j)
		{
			sum += tmp[i][j];
		}
		sum_tmp[i] = sum/col;
	}
	*sum_data = sum_tmp;
}

void make_array(double **data, int row, int col, double **sum_data)
{
	double **tmp = data;
	double *sum_tmp = *sum_data;
	for (int i = 0; i < row; ++i)
	{
		double min = 0;
		int coor_j = 0;
		int flag = 1;
		for (int j = 0; j < col; ++j)
		{
			if (abs(sum_tmp[i] - tmp[i][j]) < min || flag)
			{
				min = abs(sum_tmp[i] - tmp[i][j]);
				//printf("%f %d\n", min, i);
				coor_j = j;
				flag = 0;
			}
		}
		sum_tmp[i] = tmp[i][coor_j];
	}
	*sum_data = sum_tmp;
}

int work_array(FILE *file, double **data, int row, int col)
{
	double *sum_data = calloc(row, sizeof(*sum_data));
	if (!sum_data)
	{
		return ERROR_MEMORY;
	}
	scan_sums(data, row, col, &sum_data);
	
	make_array(data, row, col, &sum_data);
	for (int i = 0; i < row; ++i)
	{
		printf("%f ", sum_data[i]);
	}
	for (int i = 0; i < row; ++i)
	{
		fprintf(file, "%f ", sum_data[i]);
	}
	
	free(sum_data);
	return 0;
}