#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "matrix.h"
#define OK 0

int check_elem_in_column(double *slot_ex_numbers, int elm_column, int row)
{
    for (int i = 0; i < row; i++)
        if (elm_column == slot_ex_numbers[i])
        	return 0;
    return 1;
}

double determinant(matrix_s *matrix, double *slot_ex_numbers, int row)
{
    double determinant_result = 0;
    short sign_ex_det = 1;
    for (int elm_column = 0; elm_column < matrix->columns; ++elm_column)
    {
        if (check_elem_in_column(slot_ex_numbers, elm_column, row))
        {
            if (row == matrix->columns - 1)
            {
            	//printf("%f\n", matrix->data[row][elm_column]);
            	return matrix->data[row][elm_column];
            }
	    	else
			{
            	slot_ex_numbers[row] = elm_column;
            	determinant_result = determinant_result + sign_ex_det * matrix->data[row][elm_column] * determinant(matrix, slot_ex_numbers, row + 1);
            	sign_ex_det *= -1;
            }
        }
    }
    return determinant_result;
}

matrix_s *addition_matrix(matrix_s *matrix_a, matrix_s *matrix_b)
{
	matrix_s *new_matrix = create_matrix(matrix_a->rows, matrix_a->columns);
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
	matrix_s *new_matrix = create_matrix(matrix_a->rows, matrix_a->columns);
	for (int i = 0; i < matrix_a->rows ; ++i)
	{
		for (int j = 0; j < matrix_a->columns; ++j)
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

int main(int argc, char **argv)
{
	if ((argc != 5 || !strcmp(argv[1], "o")) && (argc != 4 || strcmp(argv[1], "o")))
	{
		printf("%s\n", strerror(EIO));
		printf("Run program this way: ");
		printf("./example.exe action <name file1> [name file2] <name_res file>\n");
		return EIO;
	}
	FILE *file = fopen(argv[2], "r");
	if (!file)
	{
			printf("%s", strerror(errno));
			return errno;
	}

	matrix_s *matrix = create_matrix_from_file(file);
	if (!matrix)
	{
		printf("%s\n", strerror(ENOMEM));
		return -1;
	}

	//print_matrix(matrix);
	//printf("\n\n");
	if (!strcmp(argv[1], "a") || !strcmp(argv[1], "m"))
	{
		FILE *file1 = fopen(argv[3], "r");
		if (!file1)
		{
			printf("%s", strerror(errno));
			return errno;
		}
		matrix_s *matrix_b = NULL, *new_matrix = NULL;
		matrix_b = create_matrix_from_file(file1);
		if (!matrix_b)
		{
			printf("%s\n", strerror(ENOMEM));
			return -1;
		}
		if (!strcmp(argv[1], "a"))
		{
			if (matrix->rows == matrix_b->rows && matrix->columns == matrix_b->columns)
			{
				new_matrix = addition_matrix(matrix, matrix_b);
				//print_matrix(new_matrix);
			}
		}
		else
		{
			new_matrix = multiply_matrix(matrix, matrix_b);
			//print_matrix(new_matrix);
		}
		if (!new_matrix)
		{
			printf("%s\n", strerror(ENOMEM));
			return -1;
		}
		FILE *file_write = fopen(argv[4], "w");
		for (int i = 0; i < new_matrix->rows; ++i)
		{
			for (int j = 0; j < new_matrix->columns; ++j)
			{
				fprintf(file_write, "%f", new_matrix->data[i][j]);
				fprintf(file_write, "%c", ' ');
			}
			fprintf(file_write, "%c", '\n');
		}
		//fwrite(new_matrix->data, sizeof(double), new_matrix->columns, file_write);
		fclose(file_write);
	}
	else if (!strcmp(argv[1], "o"))
	{
		FILE *file_write = fopen(argv[3], "w");
		double det = 0;// int flag = 1;
		if (matrix->rows == matrix->columns)
		{
			//FILE *file_write = fopen(argv[3], "w");
			//flag = 0;
			double slot_ex_numbers[matrix->rows];
			det = determinant(matrix, slot_ex_numbers, 0);
			//printf("det: %f", det);
			fprintf(file_write, "%f", det);
			//fclose(file_write);
		}
		//if (flag)
		//{
		//	fprintf(file_write, "%s", "NULL");
		//}// else
		//{
		//	fprintf(file_write, "%s", "NULL");
		//}
		fclose(file_write);
	}
	else
	{
		printf("Run program this way: ");
		printf("./example.exe action <name file1> [name file2] <name_res file>\n");
		printf("When action is \"0\" or \"a\" or \"m\"\n");
		return -1;
	}

	free_matrix(matrix);
	fclose(file);

	return OK;
}
