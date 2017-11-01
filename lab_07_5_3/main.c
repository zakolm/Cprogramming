#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include "CONSTANT.h"
#include "MyMath.h"
#include "Work_File.h"

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
        fprintf(file, "%d ", *pa);
    }
}

int create_array_int(int **pa, int count)
{
    *pa = (int*)calloc(count, sizeof(int*));
    if (*pa == NULL)
    {
        return -1;
    }
    return 0;
}

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)//FILE * file, int *pa, int *pb, int **pc)
{
    int minus = (pe_src - pb_src) - 1;
    for (; pb_src < pe_src; pb_src++)
    {
        if (*pb_src < 0)
        {
            minus = (pe_src - pb_src);
        }
    }
    
    if (create_array_int(pb_dst, minus))
    {
        return -1;
    }
    *pe_dst = *pb_dst + minus;
    
    return minus;
}

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
    
    if (!rc && count)
    {
        int x = 0;
        while ( x == 0)
        {
            x++;
            int *pa = NULL;
            if (!create_array_int(&pa, count))
            {
                int *pb = pa + count;
                scan_array(file_in, pa, pb);
                
                print_list(count, pa);
                
                if (flag_filter)
                {
                    int *pc = NULL;
                    int *pd = NULL;
                    count = key(pa, pb, &pc, &pd);
                    free(pa);
                    if (count == -1)
                    {
                        rc = ERROR_MEMORY;
                        break;
                    }
                    pa = pc;
                    pb = pd;
                    scan_array(file_in, pa, pb);
                    printf("\n%d\n", count);
                }
                
                bubble_sort(pa, pb-pa, sizeof(*pa), compare_int_and_ch);
                
                printf("\n");
                print_list(count, pa);
                
                FILE * file_out = fopen(argv[2], "w");
                if (file_out != NULL)
                {
                    write_to_file(file_out, pa, pb);
                    fclose(file_out);
                }
                else
                {
                    rc = ERROR_EMPTY_FILE;
                }
                free(pa);
            }
        }
    }

    fclose(file_in);
    return OK;
}