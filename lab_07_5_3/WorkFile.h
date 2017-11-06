#ifndef __WorkFile__H__
#define __WorkFile__H__

#include <stdio.h>

int int_count_scan(FILE *f, int *count);
void scan_array(FILE *f, int *pa, int *pb);
void print_list(int count, int *pa);
void write_to_file(FILE *file, int *pa, int *pb);

#endif //__WorkFile__H__
