#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#define ERROR -1
#define OK 0

void middle_znach(FILE* f, int* znach, int* count);
void Sum_funct(FILE* f, int* sum, int middle_x);

int usage(void)
{
    printf("example.exe <name file>\n");
    return ERROR;
}

int dispartion(FILE* f, int *znach, char** argv)
{
    int sum = 0, count, middle_x;
    FILE* file = fopen(argv[1], "r");

    if (fscanf(f, "%d", znach) == 1)
    {
        middle_znach(file, &middle_x, &count);
        fclose(file);
        FILE* file = fopen(argv[1], "r");
        Sum_funct(file, &sum, middle_x);
        fclose(file);
        fclose(f);
        *znach = sum/count;
        return OK;
    }
    return ERROR;
}
int main(int argc, char** argv)
{
    FILE *f;
    int max;
    f = fopen(argv[1], "r");

    if (argc != 2)
        return usage();
    if (!f)
    {
        fprintf(stderr, "File %s not found! %s!\n", argv[1], strerror(errno));
        fclose(f);
        return ERROR;
    }

    if (dispartion(f, &max, argv) == OK)
        printf("dispartion is %d\n", max);
    else
        printf("There are not enough data.\n");
    fclose(f);

    return OK;
}

int pow_funct(int base, int n)
{
    int result = 1;
    for (int i = 0; i < n; ++i)
        result *= base;
    //printf("[DBG] %d\n", result);
    return result;
}

void Sum_funct(FILE* f, int* sum, int middle_x)
{
    int num;
    *sum = 0;
    while (fscanf(f, "%d", &num) == 1)
        *sum += pow_funct((num - middle_x), 2);
}

void middle_znach(FILE* f, int* znach, int* count)
{
    int sum = 0, x;
    *count = 0;
    while (fscanf(f, "%d", &x) == 1)
    {
        //printf("[dbg]%d\n", x);
        sum += x;
        *count += 1;
    }
    *znach = sum / *count;
}
