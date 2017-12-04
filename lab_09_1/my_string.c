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
    size_t res = 0;
    size_t len1 = my_strlen(string1);
    size_t len2 = my_strlen(string2);

    for (size_t i = 0; i < len2; ++i)
        if (string1[0] != string2[i] && i == (len2 - 1))
            return res;
        else if (string1[0] == string2[i])
            break;

    res++;
    int arr[len1];
    for (size_t i = 0; i < len2; ++i)
    {
        for (size_t j = 0; j < len1; ++j)
        {
            if (string2[i] == string1[j] && !arr[j])
            {
                arr[j] = 1;
                res++;
            }
        }
    }

    return res;
}

static void my_strncpy(char * destination, const char * source, size_t num)
{
    for (size_t i = 0; i < num; ++i)
    {
        destination[i] = source[i];
    }
    destination[num] = '\0';
}

char *my_strdup(const char *src)
{
    size_t len = my_strlen(src) + 1;
    char *res = calloc(len, sizeof(*res));
    my_strncpy(res, src, len);

    return res;
}
