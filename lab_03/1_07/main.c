#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#define ERROR -1
#define OK 0

void result(FILE*, int*, int*);

int main(void)
{
    int rc, count = 0;
    //
    result(stdin, &count, &rc);
    if (!rc)
        printf("result is %d", count);
    //
    return rc;
}

void result(FILE* f, int* count, int* rc)
{
    int temp, a, b, c;
    int input_flag = 0;
    //
    if (fscanf(f, "%d", &temp) != 1)
    {
        fprintf(stderr,"ERROR INPUT!",strerror(errno));
        *rc = ERROR;
        return;
    }
    else
        a = temp;
    //
    while((fscanf(f, "%d", &temp) == 1))
    {
        if (input_flag)
        {
            c = temp;
            if (b > a && b > c)
                *count = *count + 1;
            a = b; b = c;
        }
        else
        {
            b = temp; input_flag = 1;
        }
    }
}
