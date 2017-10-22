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
		/*
		for (int i = 0; i < size; ++i)
		{
			free(matrix->data[i]);
		}
		free(matrix->data);
		free(matrix);
		*/
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


static int check_elem_in_column(double *slot_ex_numbers, double elm_column, int row)
{
	for (int i = 0; i < row; i++)
		if (elm_column == slot_ex_numbers[i])
			return 0;
	return 1;
}

static double determinant_value(matrix_s *matrix, double *slot_ex_numbers, int row)
{
	double determinant_result = 0;
	short sign_ex_det = 1;
	for (int elm_column = 0; elm_column < matrix->columns; ++elm_column)
	{
		if (check_elem_in_column(slot_ex_numbers, elm_column, row))
		{
			if (row == matrix->columns - 1)
			{
				return matrix->data[row][elm_column];
			}
			else
			{
				slot_ex_numbers[row] = elm_column;
				determinant_result = determinant_result + sign_ex_det * matrix->data[row][elm_column] * determinant_value(matrix, slot_ex_numbers, row + 1);
				sign_ex_det *= -1;
			}
		}
	}
	return determinant_result;
}

int determinant(matrix_s *matrix, double *det)
{
	if (!(matrix->rows == matrix->columns))
	{
		return -1;
	}
	double slot_ex_numbers[matrix->rows];
	*det = determinant_value(matrix, slot_ex_numbers, 0);
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