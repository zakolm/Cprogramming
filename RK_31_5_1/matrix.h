#ifndef __MATRIX__H__
#define __MATRIX__H__

typedef struct matrix_s
{
	int rows;
	int columns;
	int **data;
	//int *scorre;
}matrix_s;

void print_matrix(matrix_s *matrix);
void free_matrix(matrix_s *matrix);
matrix_s *create_matrix(int row, int col);

#endif //__MATRIX__H__