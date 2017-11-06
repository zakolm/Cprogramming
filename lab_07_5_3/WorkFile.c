#include "constant.h"
#include "WorkFile.h"

int int_count_scan(FILE * file, int *count)
{
    int item = 0;

    if ( fscanf(file, "%d", &item) != 1 )
    {
        return ERROR_EMPTY_FILE;
    }
    *count = 1;
     while (1)
     {
         int zn = fscanf(file, "%d", &item);
         if (zn == 0)
         {
             return -2;
         }
         else if (zn == 1)
         {
            *count += 1;
         }
         else
         {
             break;
         }
     }

    return OK;
}

void scan_array(FILE * file, int *pa, int *pb)
{
    int item;
    fseek(file, 0, SEEK_SET);
    while (pa < pb && fscanf(file, "%d", &item) == 1)
    {
        *pa = item;
        pa++;
    }
}

void print_list(int count, int *pa)
{
    for (int i = 0; i < count; ++i)
    {
        printf("%d ", *(pa+i));
    }
}

void write_to_file(FILE * file, int *pa, int *pb)
{
    for (; pa < pb; pa++)
    {
        fprintf(file, "%d", *pa);
        if ((pa - pb) != 1)
        {
            fprintf(file, " ");
        }
    }
}