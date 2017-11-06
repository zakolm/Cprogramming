#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "constant.h"
#include "MyMath.h"
#include "WorkFile.h"

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
        }
		count = pb - pa;
        printf("\n\n%d\n\n", count);
		count = 0;
		if ((pb - pa))
			mysort(pa, pb-pa, sizeof(*pa), compare_int_and_ch);
        
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
    return rc;
}