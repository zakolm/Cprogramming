#ifndef __MATRIX__H__
#define __MATRIX__H__

#include <stdio.h>

typedef struct matrix_s
{
    int rows;
    int columns;
    double **data;
} matrix_s;

matrix_s *create_matrix_from_file(FILE *file);
matrix_s *create_matrix(int row, int col);
void free_matrix(matrix_s *matrix);
int determinant(const matrix_s *matrix, double *det);
matrix_s *addition_matrix(matrix_s *matrix_a, matrix_s *matrix_b);
matrix_s *multiply_matrix(matrix_s *matrix_a, matrix_s *matrix_b);
void print_matrix(const matrix_s *matrix);

#endif //__MATRIX__H__
