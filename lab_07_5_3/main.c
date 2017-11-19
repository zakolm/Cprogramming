#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "constant.h"
#include "MyMath.h"
#include "WorkFile.h"

int main(int argc, char **argv)
{
    if (argc != 3 && (argc != 4 || strcmp(argv[3], "f") != 0))
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
    int flag_filter = (argc < 4) ? 0 : 1;
    int *pa = NULL;
    int *pb = NULL;
    rc = scan_array(file_in, &pa, &pb);

    if (!rc)
    {    
        print_list(pb - pa, pa);
        if (flag_filter)
        {
            int *pc = NULL;
            int *pd = NULL;
            rc = key(pa, pb, &pc, &pd);
            if (!rc)
            {
                free(pa);
                pa = pc;
                pb = pd;
            }        
        }
        if (!rc)
        {
            mysort(pa, pb - pa, sizeof(*pa), compare_int_and_ch);
            
            printf("\n");
            print_list(pb - pa, pa);
            FILE * file_out = fopen(argv[2], "w");
            if (!file_out)
            {
                rc = ERROR_EMPTY_FILE;
            }
            else
            {
                write_to_file(file_out, pa, pb);
                fclose(file_out);
            }
        }
    }

    free(pa);
    fclose(file_in);
    printf("%d\n", rc);
    return rc;
}
