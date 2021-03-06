#ifndef __MyMath__H__
#define __MyMath__H__

int create_array_int(int **pa, int count);
int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst);
void swap(void *a, void *b, int size);
int compare_int_and_ch(const void *first_item, const void *second_item);
int compare_double(const void *first_item, const void *second_item);
void mysort(void *basic, size_t count, size_t size, int(*comp)(const void*, const void*));

#endif //__MyMath__H__
