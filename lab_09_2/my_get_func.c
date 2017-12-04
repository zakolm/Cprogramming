#include "my_get_func.h"

static void my_strncpy(char * destination, const char * source, size_t num)
{
    for (size_t i = 0; i < num; ++i)
    {
        destination[i] = source[i];
    }
    destination[num] = '\0';
}

static int search(char *str, char find, size_t *count)
{
    for (size_t i = 0; i < MAXSTRING; ++i)
    {
        if (str[i] == find)
        {
            *count += i;
            return true;
        }
    }
    *count += MAXSTRING;
    return false;
}

// GET LINE INTO lineprt, RETURN LENGTH
size_t my_getline(char **lineptr, size_t *n, FILE *stream)
{
    size_t res = 0;
    char *string = calloc(MAXSTRING, sizeof(*string));
    char *lineptr_tmp = calloc(MAXSTRING, sizeof(*lineptr_tmp));
    while(fgets(string, MAXSTRING, stream) != NULL)
    {
        if (search(string, '\n', &res))
        {
            if ((res++) < MAXSTRING)
            {
                lineptr_tmp = calloc(res, sizeof(lineptr_tmp));
                my_strncpy(lineptr_tmp, string, res);
            }
            else
            {
                lineptr_tmp = realloc(lineptr_tmp, res * sizeof(*lineptr_tmp));
                snprintf(lineptr_tmp, res, "%s%s", lineptr_tmp, string);
            }
            break;
        }
        if (res != MAXSTRING)
            lineptr_tmp = realloc(lineptr_tmp, res * sizeof(*lineptr_tmp));
        snprintf(lineptr_tmp, res, "%s%s", lineptr_tmp, string);
    }
    free(string);
    if (!res)
    {
        free(lineptr_tmp);
        *n = (--res);
        return res;
    }

    *lineptr = calloc(res, sizeof(**lineptr));
    *lineptr = lineptr_tmp;
    *n = res;
    return res;
}
