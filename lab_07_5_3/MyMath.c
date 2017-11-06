#include <stdio.h>
#include <stdlib.h>

#include "constant.h"
#include "MyMath.h"

int create_array_int(int **pa, int count)
{
    *pa = (int*)calloc(count, sizeof(int*));
    if (*pa == NULL)
    {
        return ERROR_MEMORY;
    }
    return 0;
}

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{
    int count = (pe_src - pb_src) - 1;
    const int *pa = pb_src;
    for (; pa < pe_src; pa++)
    {
        if (*pa < 0)
        {
            count = (pe_src - pa);
        }
    }
    
    if (!count || create_array_int(pb_dst, count))
    {
        return -1;
    }
    *pe_dst = *pb_dst + count;
    
    return 0;//count;
}

void swap(void *a, void *b, int size)
{
    char *f = a;
    char *g = b;
    for (int i = 0; i < size; ++i)
    {
        char tmp;

        tmp = *f;
        *f = *g;
        *g = tmp;

        f++;
        g++;
    }
}


int compare_int_and_ch(const void *first_item, const void *second_item)
{
    return (*(char*)second_item - *(char*)first_item);
}

int compare_double(const void *first_item, const void *second_item)
{
    //printf("%d\n", *(double*)first_item > *(double*)second_item);
    return (*(double*)first_item > *(double*)second_item) ? 1 : (*(double*)first_item < *(double*)second_item) ? -1 : 0;
  /*
    if (*(double*)first_item > *(double*)second_item) {
      return 1;
  } else if (*(double*)first_item < *(double*)second_item) {
      return -1;
  } else {
      return 0;
  }
  */
}

void my_sort(void *basic, int count, int size, int(*comp)(const void*, const void*))
{
    char *a = basic;
    char *pa = (char*)basic;
    char *pb = (char*)basic + count * size;
    for (; pa < pb; pa += size)
    {
        char *pc = (char*)basic;
        for (; pc < pb - size - ((pa - a) / size); pc += size)
        {
            char *temp = pc;
            if (comp(temp, pc + size) < 0)
            {
                swap(temp, (pc + size), size);
            }
        }
    }
}
