#ifndef __WorkFile__H__
#define __WorkFile__H__

#include <stdio.h>

#define seek_set SEEK_SET

int int_count_scan(FILE *f, int *count);
void scan_array(FILE *f, int *pa, int *pb);
void print_list(int count, const int *pa);
void write_to_file(FILE *file, const int *pa, const int *pb);

#endif //__WorkFile__H__
