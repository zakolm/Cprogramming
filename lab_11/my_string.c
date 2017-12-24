#include "my_string.h"

/*
 * преобразование из десятичного числа в восьмеричное
 * * number- число
 * возвращает восьмеричное число в виде строки или NULL
*/
static char* d_to_o(unsigned int number)
{
    if(!number)
    {
        char* oct = malloc(2*sizeof(char));
        if(oct)
        {
            *oct = 0 + '0';
            *(oct + 1) = '\0';
        }
        return oct;
    }

    unsigned int buf = number;
    int size = 0;
    while(buf) //исправить
    {
        buf /= 8;
        size++;
    }

    char* oct = malloc(size*sizeof(char)+1);
    if(oct)
    {
        char* pos = oct + size - 1;
        for(; pos >= oct; --pos)
        {
            *pos = (number % 8) + '0';
            number /= 8;
            if(number <= 0)
                break;
        }
        *(pos+size) = '\0';
    }

    return oct;
}

/*
 * находит длину строки
 * * str- строка входная
 * возвращает размер строки без '\0'
*/
static size_t strlength(const char *str)
{
    size_t i = 0;
    while (str[i] != '\0')
        i++;

    return i;
}

/*
 * * s
 * * n- размер строки
 * * format
 * возвращает количество записанных чисел;
 * аргументов больше, чем нужно, оставшиеся игнорируются; если форматная строка длиннее n возращается -1,
 * в строку записывается только n символов; длина строки s должна быть достаточно длинной.
*/
int my_snprintf(char *s, size_t n, const char *format, ...)
{
    va_list args;
    va_start(args, format);
    char* ptr = s;
    char cval;
    char* oval;
    char* ptr_char;
    int i = 0;

    memset(s, 0, n);

    for(const char* p = format; *p; ++p)
    {
        printf("%d\n", i);
        if(i >= n-1)
            return -1;

        if(*p != '%')
        {
            *ptr = *p;
            ptr++;
            i++;
            continue;
        }

        switch (*++p)
        {
        case 's':
            for(char* sval = va_arg(args, char*); *sval; sval++)
            {
                if(i >= n-1)
                    return -1;

                *ptr = *sval;
                ptr++;
                i++;
            }
            break;
        case 'c':
            cval = va_arg(args, int);
            *ptr = cval;
            ptr++;
            i++;
            break;
        case 'o':
            oval = d_to_o(va_arg(args, unsigned int));
            ptr_char = oval;
            if(oval)
            {
                for(; *oval; oval++)
                {
                    if(i > n-1)
                    {
                        printf("djblkjblkcvjblkxcvnbkcvn\n");
                        free(ptr_char);
                        return -1;
                    }
                    *ptr = *oval;
                    ptr++;
                    i++;
                }
                free(ptr_char);
            }
            break;
        }
    }
    va_end(args);

    return strlength(s);
}
