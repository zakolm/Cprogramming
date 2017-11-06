#include <stdio.h>
#include <errno.h>
#include <string.h>

#include "matrix.h"
#include "constant.h"

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
		rc = ERROR_ALLOCATE_MEMORY;
	}

	int count = 0;
	while (rc == OK && !count)
	{
		count++;
		if (!strcmp(argv[1], "a") || !strcmp(argv[1], "m"))
		{
			FILE * file1 = fopen(argv[3], "r");
			if (!file1)
			{
				rc = ERROR_FILE;
				break;
			}
			matrix_s *matrix_b = NULL, *new_matrix = NULL;
			matrix_b = create_matrix_from_file(file1);
			if (!matrix_b)
			{
				rc = ERROR_ALLOCATE_MEMORY;
				fclose(file1);
				break;
			}
			if (!strcmp(argv[1], "a"))
			{
				new_matrix = addition_matrix(matrix, matrix_b);
			}
			else
			{
				new_matrix = multiply_matrix(matrix, matrix_b);
			}

			free_matrix(matrix_b);
			fclose(file1);
			if (!new_matrix)
			{
				rc = ERROR_ALLOCATE_MEMORY;
				break;
			}
			FILE * file_write = fopen(argv[4], "w");
			if (!file_write)
			{
				rc = ERROR_FILE;
				free_matrix(new_matrix);
				break;
			}
			print_to_file(file_write, new_matrix);
			free_matrix(new_matrix);
			fclose(file_write);
		}
		else if (!strcmp(argv[1], "o"))
		{
			double det;
			int flag = determinant(matrix, &det);
			if (!flag)
			{
				FILE * file_write = fopen(argv[3], "w");
				if (!file_write)
				{
					rc = ERROR_FILE;
					break;
				}
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
			printf("When action is \"0\" or \"a\" or \"m\"\n");
			rc = ERROR_INPUT;
		}
	}

	free_matrix(matrix);	
	fclose(file);
	print_error(rc);
	return rc;
}