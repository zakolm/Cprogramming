#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#define MAXLENGTH 5
#define OK 0
#define ERROR_INPUT_FILE -1
#define ERROR_FOUND_FILE -2
#define ERROR_ELEMENTS -3

void usage(void);
void input(FILE*, int**, int*, long long int*);
void array_print(int* pa, int* pb);

int main(int argc, char** argv)
{
    FILE *f;
    int rc = OK;
    if (argc != 2)
        usage();
    else
    {
        char** link_argv = argv;
        link_argv++;
        f = fopen(*link_argv, "r");
        int a[MAXLENGTH];
        //
        if (!f)
        {
            fprintf(stderr, "File %s not found! %s!\n", link_argv, strerror(errno));
            fclose(f);
            rc = ERROR_FOUND_FILE;
        }
        //
        long long int res = 0;
		int* pa = a;
        input(f, &pa, &rc, &res);
		//printf("[dbg]%d", pa);
		//array_print
        //fclose(f);
		//printf("[dbg]%d",a);
		array_print(a, pa);
        //if (!rc)
        //    printf("result is %lld\n", res);
        //
    }
    return rc;
}

void usage(void)
{
    printf("example.exe <name file>\n");
}

void input(FILE*f, int** pa, int* rc, long long int* sum)
{
    long long int squre = 1;
    int i = 0;
    for (; (fscanf(f, "%d", *pa) == 1); ++*pa, ++i)
    {
		//printf("[DBG]%d\n", *pa);
        if (i < MAXLENGTH)
        {
            squre *= **pa;
            *sum += squre;
            if (**(pa) < 0)
                break;
        }
        else
        {
            printf("More than 100 items\n");
            *rc = ERROR_ELEMENTS;
			break;
        }
    }
	//printf("%d\n", *pa);
    if (!i)
        *rc = ERROR_ELEMENTS;
}

void array_print(int* pa, int* pb)
{
	printf("\n");
	for (; pa < pb; ++pa)
		printf("%d ", *pa);
}
