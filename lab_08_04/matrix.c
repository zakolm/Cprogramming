#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "matrix.h"

matrix_s *create_matrix_from_file(FILE *file)
{
	int row = 0, col = 0;
	if (fscanf(file, "%d %d", &row, &col) != 2)
	{
		return NULL;
	}

	if (!(row && col) || (row < 0 || col < 0))
	{
		return NULL;
	}
	
	matrix_s *matrix = create_matrix(row, col);
	if (!matrix)
	{
		return NULL;
	}
	
	int size_matrix = matrix->rows * matrix->columns;
	int size_check = 0;
	for (row = 0; matrix->rows; ++row)
	{
		for (col = 0; col < matrix->columns; ++col)
		{
			double scan_item;
			if (fscanf(file, "%lf", &scan_item) == 1)
			{
				if (size_check < size_matrix)
					matrix->data[row][col] = scan_item;
				size_check++;
			}
			else
			{
				if (size_check != size_matrix)
				{
					free_matrix(matrix);
					return NULL;
				}
				else
				{
					return matrix;
				}
			}
		}
	}
	return matrix;
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
	matrix->data = (double**) calloc(row, sizeof(double*));
	if (!(matrix->data))
	{
		free(matrix);
		return NULL;
	}
	int size = 0;
	for (int i = 0; i < row; ++i)
	{
		matrix->data[i] = (double*) calloc(col, sizeof(double));
		if (!(matrix->data[i]))
		{
			break;
		}
		size++;
	}

	if (size != row)
	{
		free_matrix(matrix);
		
		/*for (int i = 0; i < size; ++i)
		{
			free(matrix->data[i]);
		}
		free(matrix->data);
		free(matrix);*/
		
		return NULL;
	}

	return matrix;
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

static matrix_s *matrix_det(int count, int exclude_row, int exclude_column, const matrix_s *matrix)
{
	matrix_s *new_matrix = create_matrix(count-1, count-1);
	int ki = 0, kj = 0;
	for (int i = 0; i < count-1; ++i)
	{
		if (i == exclude_row) ki = 1;
		for (int j = 0; j < count-1; ++j)
		{
			if (j == exclude_column) kj = 1;
			new_matrix->data[i][j] = matrix->data[i+ki][j+kj];
		}
	}
	return new_matrix;
}
static double determinant_value(int count, const matrix_s *matrix)
{
	int sign = 1, new_count = count - 1;
	double det = 0;
	if (count == 1)
	{
		return matrix->data[0][0];
	}
	if (count == 2)
	{
		return ((matrix->data[0][0] * matrix->data[1][1]) - (matrix->data[1][0] * matrix->data[0][1]));
	}
	if (count > 2)
	{
		for (int i = 0; i < count; ++i)
		{
			matrix_s *new_matrix = matrix_det(count, i, 0, matrix);
			det = det + sign * matrix->data[i][0] * determinant_value(new_count, new_matrix);
			sign = -sign;
			free_matrix(new_matrix);
		}
	}
	return det;
}

int determinant(const matrix_s *matrix, double *det)
{
	if (!(matrix->rows == matrix->columns))
	{
		return -1;
	}
	*det = determinant_value(matrix->rows, matrix);
	return 0;
}
matrix_s *addition_matrix(matrix_s *matrix_a, matrix_s *matrix_b)
{
	if (!((matrix_a->rows == matrix_b->rows) && (matrix_a->columns == matrix_b->columns)))
	{
		return NULL;
	}
	matrix_s *new_matrix = create_matrix(matrix_a->rows, matrix_a->columns);
	if (!new_matrix)
	{
		return NULL;
	}
	for (int i = 0; i < matrix_a->rows ; ++i)
	{
		for (int j = 0; j < matrix_a->columns; ++j)
		{
			new_matrix->data[i][j] = matrix_a->data[i][j] + matrix_b->data[i][j];
		}
	}
	return new_matrix;
}

matrix_s *multiply_matrix(matrix_s *matrix_a, matrix_s *matrix_b)
{
	if (!(matrix_a->columns == matrix_b->rows))
	{
		return NULL;
	}
	matrix_s *new_matrix = create_matrix(matrix_a->rows, matrix_b->columns);
	if (!new_matrix)
	{
		return NULL;
	}
	for (int i = 0; i < matrix_a->rows; ++i)
	{
		for (int j = 0; j < matrix_b->columns; ++j)
		{
			new_matrix->data[i][j] = 0;
			for (int k = 0; k < matrix_b->rows; ++k)
			{
				new_matrix->data[i][j] += matrix_a->data[i][k] * matrix_b->data[k][j];
			}
		}
	}

	return new_matrix;
}

void print_matrix(const matrix_s *matrix)
{
	for (int i = 0; i < matrix->rows; ++i)
	{
		for (int j = 0; j < matrix->columns; ++j)
		{
			printf("%f ", matrix->data[i][j]);
		}
		printf("\n");
	}
}
