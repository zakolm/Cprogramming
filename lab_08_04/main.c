#include <stdio.h>
#include <errno.h>
#include <string.h>

#include "matrix.h"
#include "CONSTANT.h"

void print_to_file(FILE *file_write, const matrix_s *matrix);

int main(int argc, char **argv)
{
	if ((argc != 5 || !strcmp(argv[1], "o")) && (argc != 4 || strcmp(argv[1], "o")))
	{
		print_error(ERROR_INPUT);
		return ERROR_INPUT;
	}
	FILE * file = fopen(argv[2], "r");
	if (!file)
	{
		print_error(ERROR_FILE);
		return ERROR_FILE;
	}

	int rc = OK;
	matrix_s *matrix = create_matrix_from_file(file);
	if (!matrix)
	{
		print_error(ERROR_ALLOCATE_MEMORY);
		//fclose(file);
		rc = ERROR_ALLOCATE_MEMORY;
		//return ERROR_ALLOCATE_MEMORY;
	}
	else
	{
		//print_matrix(matrix);
		if (!strcmp(argv[1], "a") || !strcmp(argv[1], "m"))
		{
			FILE * file1 = fopen(argv[3], "r");
			if (!file1)
			{
				print_error(ERROR_FILE);
				//fclose(file);
				//free_matrix(matrix);
				rc = ERROR_FILE;
				//return ERROR_FILE;
			}
			else
			{
				matrix_s *matrix_b = NULL, *new_matrix = NULL;
				matrix_b = create_matrix_from_file(file1);
				if (!matrix_b)
				{
					print_error(ERROR_ALLOCATE_MEMORY);
					//fclose(file);
					//fclose(file1);
					//free_matrix(matrix);
					//return ERROR_ALLOCATE_MEMORY;
				}
				else
				{
					//fclose(file1);
					if (!strcmp(argv[1], "a"))
					{
						new_matrix = addition_matrix(matrix, matrix_b);
						//print_matrix(new_matrix);
					}
					else
					{
						new_matrix = multiply_matrix(matrix, matrix_b);
						//print_matrix(new_matrix);
					}
					free_matrix(matrix_b);

					if (new_matrix != NULL)
					{
						FILE * file_write = fopen(argv[4], "w");
						print_to_file(file_write, new_matrix);
						free_matrix(new_matrix);
						fclose(file_write);
					}
					else
					{
						print_error(ERROR_ALLOCATE_MEMORY);
					}
				}
				fclose(file1);
			}
		}
		else if (!strcmp(argv[1], "o"))
		{
			double det;
			int flag = determinant(matrix, &det);
			if (!flag)
			{
				FILE * file_write = fopen(argv[3], "w");
				fprintf(file_write, "%f", det);
				fclose(file_write);
			}
			else
			{
				rc = ERROR_DETERMINANT;
			}
		}
		else
		{
			print_error(ERROR_INPUT);
			printf("When action is \"0\" or \"a\" or \"m\"\n");
			rc = ERROR_INPUT;
		}

		free_matrix(matrix);
	}
	
	fclose(file);
	return rc;
}

void print_to_file(FILE *file_write, const matrix_s *matrix)
{
	fprintf(file_write, "%d %d\n", matrix->rows, matrix->columns);
	//fprintf(file_write, "%c", ' ');
	//fprintf(file_write, "%d", matrix->columns);
	//fprintf(file_write, "%c", '\n');
	for (int i = 0; i < matrix->rows; ++i)
	{
		for (int j = 0; j < matrix->columns; ++j)
		{
			fprintf(file_write, "%f", matrix->data[i][j]);
			fprintf(file_write, "%c", ' ');
		}
		if (i != matrix->rows - 1)
			fprintf(file_write, "%c", '\n');
	}
}