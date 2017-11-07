#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "constant.h"
#include "MyMath.h"
#include "WorkFile.h"

int main(int argc, char **argv)
{
    if (argc != 3 && argc != 4)
    {
        printf("example.exe <name file> <name file> [f]\n");
        printf("%d\n", ERROR_INPUT);
        return ERROR_INPUT;
    }
    FILE * file_in = fopen(argv[1], "r");
    if (!file_in)
    {
        printf("file\n");
        printf("%d\n", ERROR_EMPTY_FILE);
        return ERROR_EMPTY_FILE;
    }
    
    int rc = OK;
    int count = 0;
    int flag_filter = (argc < 4) ? 0 : 1;
    rc = int_count_scan(file_in, &count);

    while (!rc && count)
    {
        int *pa = NULL;
        if (create_array_int(&pa, count))
        {
            rc = ERROR_MEMORY;
            break;
        }
        int *pb = pa + count;
        scan_array(file_in, pa, pb);
        
        print_list(pb - pa, pa);
        
        if (flag_filter)
        {
            int *pc = NULL;
            int *pd = NULL;
            int sup_flag = key(pa, pb, &pc, &pd);
            free(pa);
            if (sup_flag == -1)// || !(pd - pc))
            {
                rc = ERROR_MEMORY;
                break;
            }
            if ((pd - pc))
            {
                break;
            }
            pa = pc;
            pb = pd;
        }
        
        mysort(pa, pb - pa, sizeof(*pa), compare_int_and_ch);
        count = 0; //  для выхода из цикла
        
        printf("\n");
        print_list(pb - pa, pa);
        
        FILE * file_out = fopen(argv[2], "w");
        if (!file_out)
        {
            rc = ERROR_EMPTY_FILE;
            free(pa);
            break;
        }
        write_to_file(file_out, pa, pb);
        fclose(file_out);
        free(pa);
    }

    fclose(file_in);
    printf("\n%d\n", rc);
    return rc;
}