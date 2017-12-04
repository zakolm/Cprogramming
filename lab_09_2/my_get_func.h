#ifndef __my_get_func__H__
#define __my_get_func__H__

#include <stdio.h>
#include <stdlib.h>

#define MAXSTRING 128
#define true 1
#define false 0

size_t my_getline(char **lineptr, size_t *n, FILE *stream);

#endif // __my_get_func__H__
