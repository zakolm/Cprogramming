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
    return OK;
}

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{
    int count = pe_src - pb_src;
    int count_new = 0;
    const int *pa = pb_src;
    for (; pa < pe_src; pa++)
    {
        if (*pa < 0)
        {
            count_new = (pe_src - pa);
        }
    }
    count -= count_new;
    if (create_array_int(pb_dst, count))//(count <= 0 || create_array_int(pb_dst, count))
    {
        return -1;
    }
    *pe_dst = *pb_dst + count;

    int *pc = *pb_dst;
    pa = pb_src;
    for (; pc < *pe_dst; ++pc, ++pa)
    {
        *pc = *pa;
    }
    
    return OK;
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
    return (*(double*)first_item < *(double*)second_item) ? 1 : (*(double*)first_item < *(double*)second_item) ? 0 : -1;
}

void mysort(void *basic, size_t count, size_t size, int (*comp)(const void*, const void*))
{
    char *pb = (char*)basic + count * size;
    int flag = 0;
    int len = count;
    do
    {
        flag = 0;
        for (char *pa = (char*)basic; pa < pb - size; pa += size)
        {
            if (comp(pa, pa + size) < 0)
            {
                swap(pa, pa + size, size);
                flag = 1;
            }
        }
        len--;
    } while (flag && len > 1);
}