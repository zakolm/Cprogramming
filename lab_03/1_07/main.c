#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#define ERROR -1
#define OK 0

int result(int* count);

int main(void)
{
    int rc, count = 0;
    //
    rc = result(&count);
    if (!rc)
        printf("result is %d", count);
    //
    return rc;
}

int result(int* count)
{
    int temp, a, b, c;
    int input_flag = 0;
    //
    if (fscanf(stdin, "%d", &temp) != 1)
    {
        fprintf(stdout,"ERROR INPUT!");
        return ERROR;
    }
    else
        a = temp;
    //
    while((fscanf(stdin, "%d", &temp) == 1))
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
    //
    return OK;
}
