#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"

void print_matrix(matrix_s *matrix)
{
	for (int i = 0; i < matrix->rows; ++i)
	{
		for (int j = 0; j < matrix->columns; ++j)
		{
			printf("%d ", matrix->data[i][j]);
		}
		printf("\n");
	}
}

void free_matrix(matrix_s *matrix)
{
	for (int i = 0; i < matrix->rows; ++i)
	{
		free(matrix->data[i]);
	}
	free(matrix->data);
	free(matrix);
}

matrix_s *create_matrix(int row, int col)
{
	matrix_s *matrix;
	matrix = (matrix_s*) malloc(sizeof(matrix_s));
	if (!matrix)
	{
		return NULL;
	}
	matrix->columns = col;
	matrix->rows = row;
	matrix->data = (int**) calloc(row, sizeof(int*));
	if (!(matrix->data))
	{
		free(matrix);
		return NULL;
	}
	int size = 0;
	for (int i = 0; i < row; ++i)
	{
		matrix->data[i] = (int*) calloc(col, sizeof(int));
		if (!(matrix->data[i]))
		{
			break;
		}
		size++;
	}

	if (size != row)
	{
		free_matrix(matrix);
		return NULL;
	}

	return matrix;
}