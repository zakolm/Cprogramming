#include <stdio.h>
#include <stdlib.h>

#include "array.h"
#include "constant.h"

void free_array(double **data, int row)
{
	for(int i = 0; i < row; ++i)
	{
		free(data[i]);
	}
	free(data);
}

int alloc_array(double ***data, int row, int col)
{
	double **tmp = calloc(row, sizeof(*tmp));
	if (!tmp)
	{
		return ERROR_MEMORY;
	}
	for (int i = 0; i < row; ++i)
	{
		tmp[i] = calloc(col, sizeof(**tmp));
		if (!tmp[i])
		{
			free_array(tmp, row);
			return ERROR_MEMORY;
		}
	}
	*data = tmp;
	
	return OK;
}

void print_list(double **data, int row, int col)
{
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			printf("%f ", data[i][j]);
		}
		printf("\n");
	}
}

int scan_file(FILE *file, double ***data, int *rows, int *cols)
{
	int row = 0;
	int col = 0;
	if (fscanf(file, "%d %d", &row, &col) != 2)
	{
		return ERROR_FILE;
	}
	if (row <= 0 || col <= 0)
	{
		return ERROR_FILE;
	}
	*rows = row;
	*cols = col;
	double **tmp;
	int rc = alloc_array(&tmp, row, col);
	if (rc)
	{
		return rc;
	}
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			if (fscanf(file, "%lf", &tmp[i][j]) != 1)
			{
				free_array(tmp, row);
				return ERROR_FILE;
			}
		}
	}
	
	*data = tmp;
	return OK;
}