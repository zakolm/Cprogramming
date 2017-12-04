#include "my_string.h"

static size_t my_strlen(const char *src)
{
    size_t len = 0;
    while (*src)
    {
        src++;
        len++;
    }

    return len;
}

size_t my_strspn(const char *string1, const char *string2)
{
    size_t i = 0, j = 0;
    for (i = 0; string1[i]; ++i)
    {
        for (j = 0; string2[j]; ++j)
            if (string1[i] == string2[j])
                break;
        if (!string2[j])
            break;
    }

    return i;
}

static void my_strncpy(char *destination, const char *source, size_t num)
{
    for (size_t i = 0; i < num; ++i)
        destination[i] = source[i];

    destination[num] = '\0';
}

char *my_strdup(const char *src)
{
    size_t len = my_strlen(src) + 1;
    char *res = calloc(len, sizeof(*res));
    my_strncpy(res, src, len);

    return res;
}
