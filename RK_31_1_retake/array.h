#ifndef __ARRAY__H__
#define __ARRAY__H__

#include <stdio.h>
#include <stdlib.h>

void free_array(double **data, int row);
int alloc_array(double ***data, int row, int col);
void print_list(double **data, int row, int col);
int scan_file(FILE *file, double ***data, int *rows, int *cols);

#endif //__ARRAY__H__