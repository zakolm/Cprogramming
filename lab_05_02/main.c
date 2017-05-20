#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#define MAXLENGTH 100
#define OK 0
#define ERROR_INPUT_FILE -1
#define ERROR_FOUND_FILE -2
#define ERROR -3

int usage(void);

int input(FILE*, int*, int*);

void result(int*, int*, long long int*);

int main(int argc, char** argv)
{
    FILE *f;
    char** link_argv = argv;
    link_argv++;
    f = fopen(*link_argv, "r");
    int a[MAXLENGTH];
    //
    if (argc != 2)
        return usage();
    if (!f)
    {
        fprintf(stderr, "File %s not found! %s!\n", link_argv, strerror(errno));
        fclose(f);
        return ERROR_FOUND_FILE;
    }
    int rc = OK;
    //
    int len = input(f, a, &rc);
    if (rc)
        return rc;
    else
    {
        int *pa = a, *pb = a;
        int i = 0;
        for (; i < len; ++pb, ++i);
        //printf("%d %d\n", pb, *pb);
        long long int res;
        result(pa, pb, &res);
        printf("result is %lld", res);
    }
    //
    return rc;
}

int usage(void)
{
    printf("example.exe <name file>\n");
    return ERROR_INPUT_FILE;
}

int input(FILE*f, int* pa, int* rc)
{
    int i = 0;
    //
    for (; (fscanf(f, "%d", pa) == 1); ++pa, ++i)
    {
        if (i < MAXLENGTH)
        {
            if (*(pa) < 0)
            {
                //printf("%d %d\n", pa, *pa);
                break;
            }
        }
        else
        {
            printf("More than 100 items\n");break;
        }
    }
    //printf("%d %d\n", pa-1, *(pa-1));
    fclose(f);
    if (!i)
    {
        *rc = ERROR;
        return i;
    }
    else
    {
        if (i < 100)
            return i;
        else
            return i-1;
    }
}

void result(int* pa, int* pb, long long int* sum)
{
    *sum = 0;
    int i = 0;
    long long int squre = 1;
    //
    while(pa <= pb)
    {
        //printf("%d",*pa);
        squre *= *pa;
        //printf("\n[dbg] %lld\n", squre);
        *sum += squre;
        //printf("[dbg2] %lld\n", *sum);
        pa++;
    }
}
