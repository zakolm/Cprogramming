#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#define MAXLENGTH 100
#define OK 0
#define ERROR -1

int usage(void);

int input(FILE*, int*);

void result(int*, int, long long int*);

int main(int argc, char** argv)
{
    FILE *f;
    f = fopen(*(argv+1), "r");
    int a[MAXLENGTH];
    int len;
    //
    if (argc != 2)
        return usage();
    if (!f)
    {
        fprintf(stderr, "File %s not found! %s!\n", argv[1], strerror(errno));
        fclose(f);
        return ERROR;
    }
    //
    len = input(f, a);
    //printf("%d", len);
    long long int res;
    result(a, len, &res);
    printf("result is %lld", res);
    //
    return OK;
}

int usage(void)
{
    printf("example.exe <name file>\n");
    return ERROR;
}

int input(FILE*f, int* pa)
{
    int len = -1, i = 0;
    //
    //printf("1# %d\n", len);
    for (; (fscanf(f, "%d", (pa+i)) == 1); ++i)
    {
        if (i < MAXLENGTH)
        {
            //printf("[a]%d\n", *(pa+i));
            if (*(pa+i) < 0)
            {
                len = i+1; break;
            }
        }
        else
        {
            printf("More than 100 items\n");break;
        }
    }
    fclose(f);
    //printf("2# %d\n", len);
    if (len == -1)
        len = (MAXLENGTH - 1);
    //printf("3# %d\n", len);
    //
    return len;
}

void result(int* pa, int len, long long int* sum)
{
    //printf("\n");
    *sum = 0;
    int i = 0;
    long long int squre = 1;
    //
    for (; i < len; ++i)
    {
        squre *= *(pa+i);
        //printf("%d\n", *(pa+i));
        //printf("\n[dbg] %lld\n", squre);
        *sum += squre;
        //printf("[dbg2] %lld\n", *sum);
    }
}
