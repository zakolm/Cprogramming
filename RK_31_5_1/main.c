#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"

#define OK 0
#define ERROR_INPUT -1
#define ERROR_FILE -2
#define MAX_STR 100
/*
int check_place()
{
	
}
*/

int check_main_line(matrix_s *matrix)
{
	for (int i = 0; i < matrix->rows; ++i)
	{
		for (int j = 0; j < matrix->columns; ++j)
		{
			if (i == j && matrix->data[i][j])
			{
				return 1;
			}
		}
	}
	
	return 0;
}

int main(int argc, char **argv)
{
	int rc = OK;
	if (argc != 3)
	{
		printf("ERROR I/O");
		return ERROR_INPUT;
	}
	FILE * file = fopen(argv[1], "r");
	printf("%s\n", argv[1]);
	if (!file)
	{
		printf("No file or dir");
		return ERROR_FILE;
	}

	int row = 0, col = 0;
	if (fscanf(file, "%d %d", &row, &col) != 2)
	{
		return ERROR_FILE;
	}
	printf("%d %d", row, col);
	if (!(row && col) || (row < 0 || col < 0))
	{
		return ERROR_FILE;
	}
	
	matrix_s *matrix = create_matrix(row, col);
	if (!matrix)
	{
		return ERROR_FILE;
	}
	if (matrix->rows != matrix->columns)
	{
		return ERROR_INPUT;
	}
	int size_matrix = matrix->rows * matrix->columns;
	int size_check = 0;
	//printf("%d", size_matrix);
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			int scan_item;
			if (fscanf(file, "%d", &scan_item) == 1)
			{
				if (size_check < size_matrix)
				//Почему-то не работает...:( Segm falt
				//matrix->data[i][j] = scan_item;
				size_check++;
			}
			else
			{
				if (size_check != size_matrix)
				{
					return ERROR_FILE;
				}
			}
			
		}
	}
	
	
	free_matrix(matrix);
	
	
	return rc;
}