#include <stdio.h>
#include <string.h>

#include "my_string.h"

#define name __func__

void check_my_strspn(void);
void check_my_strdup(void);

int main(void)
{
    check_my_strspn();
    check_my_strdup();
    return 0;
}

void check_my_strspn(void)
{
    int ok_count = 0;
    int number_test = 0;

    //test 1
    {
        number_test++;
        size_t res = 4;
        char strtext[] = "2017 год";
        char digit[] = "1234567890";

        size_t num = strspn(strtext, digit);
        if (res == num)
        {
            ok_count++;
        }
        else
        {
            printf("%s: FAILD %d test\n", name, number_test);
        }
    }

    //test 2
    {
        number_test++;
        size_t res = 2;
        char strtext[] = "42: The answer to life, the universe and everything.";
        char digit[] = "1234567890";

        size_t num = strspn(strtext, digit);
        if (res == num)
        {
            ok_count++;
        }
        else
        {
            printf("%s: FAILD %d test\n", name, number_test);
        }
    }

    //test 3
    {
        number_test++;
        size_t res = 2;
        char strtext[] = "21 - the answer to the question of 128";
        char digit[] = "1234567890";

        size_t num = strspn(strtext, digit);
        if (res == num)
        {
            ok_count++;
        }
        else
        {
            printf("%s: FAILD %d test\n", name, number_test);
        }
    }

    //test 4
    {
        number_test++;
        size_t res = 0;
        char strtext[] = "foo";
        char digit[] = "o";

        size_t num = strspn(strtext, digit);
        if (res == num)
        {
            ok_count++;
        }
        else
        {
            printf("%s: FAILD %d test\n", name, number_test);
        }
    }

    //test 5
    {
        number_test++;
        size_t res = 2;
        char strtext[] = "oof";
        char digit[] = "o";

        size_t num = strspn(strtext, digit);
        if (res == num)
        {
            ok_count++;
        }
        else
        {
            printf("%s: FAILD %d test\n", name, number_test);
        }
    }

    //test 6
    {
        number_test++;
        size_t res = 0;
        char strtext[] = "";
        char digit[] = "abcdefghijklmnopqrstuvwxyz";

        size_t num = strspn(strtext, digit);
        if (res == num)
        {
            ok_count++;
        }
        else
        {
            printf("%s: FAILD %d test\n", name, number_test);
        }
    }

    //test 7
    {
        number_test++;
        size_t res = 0;
        char strtext[] = "abcdefghijklmnopqrstuvwxyz";
        char digit[] = "";

        size_t num = strspn(strtext, digit);
        if (res == num)
        {
            ok_count++;
        }
        else
        {
            printf("%s: FAILD %d test\n", name, number_test);
        }
    }

    //test 8
    {
        number_test++;
        size_t res = 0;
        char strtext[] = "";
        char digit[] = "";

        size_t num = strspn(strtext, digit);
        if (res == num)
        {
            ok_count++;
        }
        else
        {
            printf("%s: FAILD %d test\n", name, number_test);
        }
    }

    //test 9
    {
        number_test++;
        size_t res = 5;
        char strtext[] = "abacan";
        char digit[] = "abc";

        size_t num = strspn(strtext, digit);
        if (res == num)
        {
            ok_count++;
        }
        else
        {
            printf("%s: FAILD %d test\n", name, number_test);
        }
    }

    //test 10
    {
        number_test++;
        size_t res = 5;
        char strtext[] = "abcde312@";
        char digit[] = "abcdefghijklmnopqrstuvwxyz";

        size_t num = strspn(strtext, digit);
        if (res == num)
        {
            ok_count++;
        }
        else
        {
            printf("%s: FAILD %d test\n", name, number_test);
        }
    }

    //result
    printf("%s: %s\n", name, (ok_count == number_test) ? "OK" : "FAILED");
}

void check_my_strdup(void)
{
    int ok_count = 0;
    int number_test = 0;

    //test 1
    {
        number_test++;
        char res[] = "0123456789";
        char *istr;

        istr = my_strdup(res);
        if (!istr || strcmp(res, istr))
        {
            printf("%s: FAILD %d test\n", name, number_test);
        }
        else
        {
            ok_count++;
        }
        free(istr);
    }

    //test 2
    {
        number_test++;
        char res[] = "";
        char *istr;

        istr = my_strdup(res);
        if (!istr || strcmp(res, istr))
        {
            printf("%s: FAILD %d test\n", name, number_test);
        }
        else
        {
            ok_count++;
        }
        free(istr);
    }

    //test 3
    {
        number_test++;
        //char res[] = "";
        char *istr;

        istr = my_strdup("\0");
        if (!istr || strcmp("\0", istr))
        {
            printf("%s: FAILD %d test\n", name, number_test);
        }
        else
            ok_count++;
        free(istr);
    }

    //result
    printf("%s: %s\n", name, (ok_count == number_test) ? "OK" : "FAILED");
}
