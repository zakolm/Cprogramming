#include <stdio.h>
#include <string.h>

#include "my_string.h"

#define name __func__
#define OK 0

void check_my_snprintf(void);

int main(void)
{
    check_my_snprintf();
    return OK;
}

void check_my_snprintf(void)
{
    int ok_count = 0;
    int number_test = 0;

    int fc = 0, rc = 0;
    // test 1
    {
        number_test++;
        char s[11];
        char r[11];
        fc = my_snprintf(s, 11, "%c = %s = %o", 54, "qwerty", 108);
        rc = snprintf(r, 11, "%c = %s = %o", 54, "qwerty", 108);
        if(strcmp(s, r) == 0 && fc == rc)
        {
            ok_count++;
            printf("Test %d passed.\n", number_test);
        }
        else
        {
            printf("Test %d FAILD!\n", number_test);
        }
    }

    // test 2
    {
        number_test++;
        char s[20] = {0};
        char r[20] = {0};
        fc = my_snprintf(s, 20, "%s %o %c", "qwerty", 100, 61);
        rc = snprintf(r, 20, "%s %o %c", "qwerty", 100, 61);
        if(strcmp(s, r) == 0 && fc == rc)
        {
            ok_count++;
            printf("Test %d passed.\n", number_test);
        }
        else
        {
            printf("Test %d FAILD!\n", number_test);
        }
    }

    // test 3
    {
        number_test++;
        char s[20] = {0};
        char r[20] = {0};
        fc = my_snprintf(s, 20, "%o %s %c", 8, "qwerty", 57);
        rc = snprintf(r, 20, "%o %s %c", 8, "qwerty", 57);
        if(strcmp(s, r) == 0 && fc == rc)
        {
            ok_count++;
            printf("Test %d passed.\n", number_test);
        }
        else
        {
            printf("Test %d FAILD!\n", number_test);
        }
    }

    // test 4
    {
        number_test++;
        char s[20] = {0};
        char r[20] = {0};
        fc = my_snprintf(s, 20, "%o %c %s", 48, 100, "- - -");
        rc = snprintf(r, 20, "%o %c %s", 48, 100, "- - -");
        if(strcmp(s, r) == 0 && fc == rc)
        {
            ok_count++;
            printf("Test %d passed.\n", number_test);
        }
        else
        {
            printf("Test %d FAILD!\n", number_test);
        }

    }

    // test 5
    {
        number_test++;
        char s[20] = {0};
        char r[20] = {0};
        fc = my_snprintf(s, 20, "%c %o %s", 74, 100, "12345");
        rc = snprintf(r, 20, "%c %o %s", 74, 100, "12345");
        if(strcmp(s, r) == 0 && fc == rc)
        {
            ok_count++;
            printf("Test %d passed.\n", number_test);
        }
        else
        {
            printf("Test %d FAILD!\n", number_test);
        }
    }

    // test 6
    {
        number_test++;
        char s[20] = {0};
        char r[20] = {0};
        fc = my_snprintf(s, 20, "%c %s %o", 74, "qwerty", 61);
        rc = snprintf(r, 20, "%c %s %o", 74, "qwerty", 61);
        if(strcmp(s, r) == 0 && fc == rc)
        {
            ok_count++;
            printf("Test %d passed.\n", number_test);
        }
        else
        {
            printf("Test %d FAILD!\n", number_test);
        }
    }

    // test 7
    {
        number_test++;
        char s[20] = {0};
        char r[20] = {0};
        fc = my_snprintf(s, 20, "%s %c %o", "qwerty", 100, 61);
        rc = snprintf(r, 20, "%s %c %o", "qwerty", 100, 61);
        if(strcmp(s, r) == 0 && fc == rc)
        {
            ok_count++;
            printf("Test %d passed.\n", number_test);
        }
        else
        {
            printf("Test %d FAILD!\n", number_test);
        }
    }

    /*// test 8
    {
        number_test++;
        char s[20] = {0};
        char r[20] = {0};
        fc = my_snprintf(s, 20, "%s %o", "qwerty", 100, 61);
        rc = snprintf(r, 20, "%s %o", "qwerty", 100, 61);
        if(strcmp(s, r) == 0 && fc == rc)
        {
            ok_count++;
            printf("Test %d passed.\n", number_test);
        }
        else
        {
            printf("Test %d FAILD!\n", number_test);
        }
    }*/

    // test 8
    {
        number_test++;
        char s[20] = {0};
        char r[20] = {0};
        fc = my_snprintf(s, 20, "%c %s", 74, "qwerty");
        rc = snprintf(r, 20, "%c %s", 74, "qwerty");
        if(strcmp(s, r) == 0 && fc == rc)
        {
            ok_count++;
            printf("Test %d passed.\n", number_test);
        }
        else
        {
            printf("Test %d FAILD!\n", number_test);
        }
    }

    // test 9
    {
        number_test++;
        char s[20] = {0};
        char r[20] = {0};
        fc = my_snprintf(s, 20, "%s", "qwerty");
        rc = snprintf(r, 20, "%s", "qwerty");
        if(strcmp(s, r) == 0 && fc == rc)
        {
            ok_count++;
            printf("Test %d passed.\n", number_test);
        }
        else
        {
            printf("Test %d FAILD!\n", number_test);
        }
    }

    // test 10
    {
        number_test++;
        char s[20] = {0};
        char r[20] = {0};
        fc = my_snprintf(s, 20, "%o", 100);
        rc = snprintf(r, 20, "%o", 100);
        if(strcmp(s, r) == 0 && fc == rc)
        {
            ok_count++;
            printf("Test %d passed.\n", number_test);
        }
        else
        {
            printf("Test %d FAILD!\n", number_test);
        }
    }

    // test 11
    {
        number_test++;
        char s[20] = {0};
        char r[20] = {0};
        fc = my_snprintf(s, 20, "%c", 61);
        rc = snprintf(r, 20, "%c", 61);
        if(strcmp(s, r) == 0 && fc == rc)
        {
            ok_count++;
            printf("Test %d passed.\n", number_test);
        }
        else
        {
            printf("Test %d FAILD!\n", number_test);
        }
    }

    // test 12
    {
        number_test++;
        char s[20] = {0};
        char r[20] = {0};
        fc = my_snprintf(s, 4, "%s %o %c", "qwerty", 100, 61);
        rc = snprintf(r, 4, "%s %o %c", "qwerty", 100, 61);
        if(strcmp(s, r) == 0 && fc == rc)
        {
            ok_count++;
            printf("Test %d passed.\n", number_test);
        }
        else
        {
            printf("Test %d FAILD!\n", number_test);
        }
    }

    // test 13
    {
        number_test++;
        char s[20] = {0};
        char r[20] = {0};
        fc = my_snprintf(s, 9, "%s %o %c", "qwerty", 100, 61);
        rc = snprintf(r, 9, "%s %o %c", "qwerty", 100, 61);
        if(strcmp(s, r) == 0 && fc == rc)
        {
            ok_count++;
            printf("Test %d passed.\n", number_test);
        }
        else
        {
            printf("Test %d FAILD!\n", number_test);
        }
    }

    //test 14
    {
        number_test++;
        char s[20] = {0};
        char r[20] = {0};
        fc = my_snprintf(s, 1, "123 %s %o %c", "qwerty", 100, 61);
        rc = snprintf(r, 1, "123 %s %o %c", "qwerty", 100, 61);
        if(strcmp(s, r) == 0 && fc == rc)
        {
            ok_count++;
            printf("Test %d passed.\n", number_test);
        }
        else
        {
            printf("Test %d FAILD!\n", number_test);
        }
    }

    // test 15
    {
        number_test++;
        char s[20] = {0};
        char r[20] = {0};
        fc = my_snprintf(s, 9, "%s poiy %o %c", "qwerty", 100, 61);
        rc = snprintf(r, 9, "%s poiy %o %c", "qwerty", 100, 61);
        if(strcmp(s, r) == 0 && fc == rc)
        {
            ok_count++;
            printf("Test %d passed.\n", number_test);
        }
        else
        {
            printf("Test %d FAILD!\n", number_test);
        }
    }

    // test 16
    {
        number_test++;
        char s[20] = {0};
        char r[20] = {0};
        fc = my_snprintf(s, 6, "%s%c", "qwerty", 100);
        rc = snprintf(r, 6, "%s%c", "qwerty", 100);
        if(strcmp(s, r) == 0 && fc == rc)
        {
            ok_count++;
            printf("Test %d passed.\n", number_test);
        }
        else
        {
            printf("Test %d FAILD!\n", number_test);
        }
    }

    /*// test 18
    {
        number_test++;
        char s[20] = {0};
        char r[20] = {0};
        fc = my_snprintf(s, 10, "%s", "qwerty", 100, 61);
        rc = snprintf(r, 10, "%s", "qwerty", 100, 61);
        if(strcmp(s, r) == 0 && fc == rc)
        {
            ok_count++;
            printf("Test %d passed.\n", number_test);
        }
        else
        {
            printf("Test %d FAILD!\n", number_test);
        }
    }*/

    /*// test 19
    {
        number_test++;
        char s[20] = {0};
        char r[20] = {0};
        fc = my_snprintf(s, 10, "", "qwerty", 100, 61);
        rc = snprintf(r, 10, "", "qwerty", 100, 61);
        if(strcmp(s, r) == 0 && fc == rc)
        {
            ok_count++;
            printf("Test %d passed.\n", number_test);
        }
        else
        {
            printf("Test %d FAILD!\n", number_test);
        }
    }*/

    // result
    printf("%d %d\n", ok_count, number_test);
    printf("Test %s is %s", name, (ok_count == number_test) ? "OK" : "FAILD");
}
