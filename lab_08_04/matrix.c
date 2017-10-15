#include "matrix.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

matrix_s* create_matrix(int row, int col)
{
    matrix_s *matrix;
    matrix = (matrix_s*) malloc(sizeof(matrix_s));
	if ( !matrix )
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
    for (int i = 0; i < row; ++i)
	{
        matrix->data[i] = (double*) calloc(col, sizeof(double));
        if (!(matrix->data[i]))
		{
            free(matrix->data);
            free(matrix);
            return NULL;
        }
    }

    return matrix;
}

matrix_s* create_matrix_from_file(FILE* file)
{
    int row, col;
    fscanf(file,"%d",&row);
    fscanf(file,"%d",&col);

	if (!(row & col))
	{
		return NULL;
	}

    matrix_s* matrix = create_matrix(row, col);
    if (!matrix)
	{
        return NULL;
    }
	for ( row = 0; matrix->rows; ++row )
	{
        for ( col = 0; col < matrix->columns; ++col )
        {
            double scan_item;
            if ( fscanf(file, "%lf", &scan_item) == 1 )
			{
                        	matrix->data[row][col] = scan_item;
			}
            else
			{
				return matrix;
			}
        }
	}

    return matrix;
}

void free_matrix(matrix_s *matrix)
{
    for ( int i = 0; i < matrix->rows; ++i )
	{
        free(matrix->data[i]);
    }
    free(matrix->data);
    free(matrix);
}
