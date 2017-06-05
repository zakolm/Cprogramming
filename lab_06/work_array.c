#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "workarray.h"
#include "const.h"

void input(FILE*f, int** pa, int* rc)
{
    int i = 0;
    for (; (fscanf(f, "%d", *pa) == 1) && (i <= MAXLENGTH); ++*pa, ++i)
    {
        if (i < MAXLENGTH)
        {
            if (**(pa) < 0)
                break;
        }
        else
        {
            *rc = MORE_ERROR_ELEMENTS;
        }
    }
    if (!i)
        *rc = ZERO_ERROR_ELEMENTS;
}

void array_print(int* pa, int* pb)
{
	printf("ARRAY:\n");
	for (; pa < pb; ++pa)
		printf("%d ", *pa);
}