#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#define ERROR -1
#define OK 0

int result(FILE*, int*, int);

int main(void)
{
    int rc, count = 0;
    //
    rc = result(stdin, &count, rc);
    if (!rc)
        printf("result is %d", count);
	else
		fprintf(stderr,"ERROR INPUT!",strerror(errno));
    //
    return rc;
}

int result(FILE* f, int* count, int rc)
{
    int a, b, c;
    //
    if (fscanf(f, "%d", &a) != 1 || (fscanf(f, "%d", &b)) != 1)
    {
        //fprintf(stderr,"ERROR INPUT!",strerror(errno));
        rc = ERROR;
        return rc;
    }
    while((fscanf(f, "%d", &c) == 1))
    {
            if (b > a && b > c)
                *count = *count + 1;
            a = b; b = c;
    }
	return rc;
}
