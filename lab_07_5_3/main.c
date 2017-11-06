#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include "constant.h"
#include "MyMath.h"
#include "Work_File.h"

void print_list(int count, int *pa);

void write_to_file(FILE * file, int *pa, int *pb);

int create_array_int(int **pa, int count);

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst);

int main(int argc, char **argv)
{
    if (argc != 3 && !(argc == 4 && !strcmp(argv[3],"-")))
    {
        printf("example.exe <name file> <name file> [f]\n");
        return ERROR_INPUT;
    }
    FILE * file_in = fopen(argv[1], "r");
    if (!file_in)
    {
        printf("file\n");
        return ERROR_EMPTY_FILE;
    }
    
    int rc = OK;
    int count = 0;
    int flag_filter = (argc < 4) ? 0 : 1;
    rc = int_count_scan(file_in, &count);

    while (!rc && count)
    {
        x++;
        int *pa = NULL;
        if (create_array_int(&pa, count))
        {
            rc = ERROR_MEMORY;
            break;
        }
        int *pb = pa + count;
        count = 0; //  для выхода из цикла
        scan_array(file_in, pa, pb);
        
        print_list(pb-pa, pa);
        
        if (flag_filter)
        {
            int *pc = NULL;
            int *pd = NULL;
            int sup_flag = key(pa, pb, &pc, &pd);
            free(pa);
            if (sup_flag == -1)
            {
                rc = ERROR_MEMORY;
                break;
            }
            pa = pc;
            pb = pd;
            scan_array(file_in, pa, pb);
        }
        
        my_sort(pa, pb-pa, sizeof(*pa), compare_int_and_ch);
        
        printf("\n");
        print_list(pb-pa, pa);
        
        FILE * file_out = fopen(argv[2], "w");
        if (!file_out)
        {
            rc = ERROR_EMPTY_FILE;
            break;
        }
        write_to_file(file_out, pa, pb);
        fclose(file_out);
        free(pa);
    }

    fclose(file_in);
    return OK;
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