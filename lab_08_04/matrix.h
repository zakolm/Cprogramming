#ifndef __MATRIX__H__
#define __MATRIX__H__

#include <stdio.h>

typedef struct matrix_s {
    int rows;
    int columns;
    double **data;
} matrix_s;

matrix_s *create_matrix_from_file(FILE *file);
matrix_s *create_matrix(int row, int col);
void free_matrix(matrix_s *matrix);
double get_elem(matrix_s *matrix, int row, int col);
void set_elem(matrix_s *matrix, int row, int col, double val);
int get_rows(matrix_s *matrix);
int get_cols(matrix_s *matrix);

#endif //__MATRIX__H__
