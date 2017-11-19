#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "constant.h"
#include "MyMath.h"
#include "WorkFile.h"

#define EPS 1e-5
#define name __func__

void check_swap(void);
void check_compare(void);
void check_key(void);
void check_sort(void);
void check_scan(void);
void check_write(void);

int main(void)
{
    check_swap();
    check_compare();
    check_key();
    check_sort();
    check_scan();
    check_write();
    return OK;
}

void check_swap(void)
{
    int ok_count = 0;
    int number_test = 0;

    //test 1
    {
        number_test++;
        int value_a = 123;
        int value_b = 987;

        swap(&value_a, &value_b, sizeof(value_a));

        if (value_a == 987 && value_b == 123)
        {
            ok_count++;
        }
        else
        {
            printf("test_swap: test %d faild\n", number_test);
        }
    }

    //test 2
    {
        number_test++;
        double value_a = 123;
        double value_b = 987;

        swap(&value_a, &value_b, sizeof(value_a));

        if (fabs(value_a - 987) < EPS && fabs(value_b - 123) < EPS)
        {
            ok_count++;
        }
        else
        {
            printf("test_swap: test %d faild\n", number_test);
        }
    }

    //test 3
    {
        number_test++;
        char value_a = 'a';
        char value_b = 'b';

        swap(&value_a, &value_b, sizeof(value_a));

        if (value_a == 'b' && value_b == 'a')
        {
            ok_count++;
        }
        else
        {
            printf("test_swap: test %d faild\n", number_test);
        }
    }

    //result
    printf("%s: %s\n", name, (ok_count == number_test) ? "OK" : "FAILED");
}

void check_compare(void)
{
    int ok_count = 0;
    int number_test = 0;

    //test 1
    {
        number_test++;
        int value_a = 1;
        int value_b = 2;

        if (compare_int_and_ch(&value_a, &value_b) < 0)
        {
            ok_count++;
        }
        else
        {
            printf("test_compare: test %d faild\n", number_test);
        }
    }

    //test 2
    {
        number_test++;
        int value_a = 1;
        int value_b = 1;

        if (compare_int_and_ch(&value_a, &value_b) == 0)
        {
            ok_count++;
        }
        else
        {
            printf("test_compare: test %d faild\n", number_test);
        }
    }

    //test 3
    {
        number_test++;
        int value_a = 2;
        int value_b = 1;

        if (compare_int_and_ch(&value_a, &value_b) > 0)
        {
            ok_count++;
        }
        else
        {
            printf("test_compare: test %d faild\n", number_test);
        }
    }

    //test 4
    {
        number_test++;
        char value_a = 'a';
        char value_b = 'z';

        if (compare_int_and_ch(&value_a, &value_b) < 0)
        {
            ok_count++;
        }
        else
        {
            printf("test_compare: test %d faild\n", number_test);
        }
    }

    //test 5
    {
        number_test++;
        char value_a = 'a';
        char value_b = 'a';

        if (compare_int_and_ch(&value_a, &value_b) == 0)
        {
            ok_count++;
        }
        else
        {
            printf("test_compare: test %d faild\n", number_test);
        }
    }

    //test 6
    {
        number_test++;
        char value_a = 'z';
        char value_b = 'a';

        if (compare_int_and_ch(&value_a, &value_b) > 0)
        {
            ok_count++;
        }
        else
        {
            printf("test_compare: test %d faild\n", number_test);
        }
    }

    //test 7
    {
        number_test++;
        double value_a = 1;
        double value_b = 2;

        if (compare_double(&value_a, &value_b) < 0)
        {
            ok_count++;
        }
        else
        {
            printf("test_compare: test %d faild\n", number_test);
        }
    }

    //test 8
    {
        number_test++;
        double value_a = 1;
        double value_b = 1;

        if (compare_double(&value_a, &value_b) == 0)
        {
            ok_count++;
        }
        else
        {
            printf("test_compare: test %d faild\n", number_test);
        }
    }

    //test 9
    {
        number_test++;
        double value_a = 1;
        double value_b = 2;

        if (compare_double(&value_a, &value_b) < 0)
        {
            ok_count++;
        }
        else
        {
            printf("test_compare: test %d faild\n", number_test);
        }
    }
    
    //test 10
    {
        number_test++;
        double value_a = 1.1;
        double value_b = 1.2;

        if (compare_double(&value_a, &value_b) < 0)
        {
            ok_count++;
        }
        else
        {
            printf("test_compare: test %d faild\n", number_test);
        }
    }

    //test 11
    {
        number_test++;
        double value_a = 1.1;
        double value_b = 1.1;

        if (compare_double(&value_a, &value_b) == 0)
        {
            ok_count++;
        }
        else
        {
            printf("test_compare: test %d faild\n", number_test);
        }
    }

    //test 12
    {
        number_test++;
        double value_a = 1.2;
        double value_b = 1.1;

        if (compare_double(&value_a, &value_b) > 0)
        {
            ok_count++;
        }
        else
        {
            printf("test_compare: test %d faild\n", number_test);
        }
    }

    //test 13
    {
        number_test++;
        double value_a = 1.1111;
        double value_b = 1.1112;

        if (compare_double(&value_a, &value_b) < 0)
        {
            ok_count++;
        }
        else
        {
            printf("test_compare: test %d faild\n", number_test);
        }
    }

    //test 14
    {
        number_test++;
        double value_a = 1.1111;
        double value_b = 1.1111;

        if (compare_double(&value_a, &value_b) == 0)
        {
            ok_count++;
        }
        else
        {
            printf("test_compare: test %d faild\n", number_test);
        }
    }

    //test 15
    {
        number_test++;
        double value_a = 1.1112;
        double value_b = 1.1111;

        if (compare_double(&value_a, &value_b) > 0)
        {
            ok_count++;
        }
        else
        {
            printf("test_compare: test %d faild\n", number_test);
        }
    }

    //result
    printf("%s: %s\n", name, (ok_count == number_test) ? "OK" : "FAILED");
}

void check_key(void)
{
    int ok_count = 0;
    int number_test = 0;

    //test 1
    {
        number_test++;
        int count_res = 10;
        int res[] =
            {
            1, 2, 3, 4, 5, 5, 6, 6, 7, 7
            };
        int value_in[] =
            {
            1, 2, 3, 4, 5, 5, 6, 6, 7, 7
            };
        int *value_out = NULL;
        int *value_out_end = NULL;

        if (!key(value_in, value_in + count_res, &value_out, &value_out_end) && !memcmp(res, value_out, count_res))
        {
            ok_count++;
        }
        else
        {
            printf("test_key: test %d faild\n", number_test);
        }
        free(value_out);
    }

    //test 2
    {
        number_test++;
        int count_res = 1;
        //int res[] = {EMPTY_ARRAY};
        int value_in[] =
            {
            -1
            };
        int *value_out = NULL;
        int *value_out_end = NULL;

        if (key(value_in, value_in + count_res, &value_out, &value_out_end))
        {
            ok_count++;
        }
        else
        {
            printf("test_key: test %d faild\n", number_test);
        }
        free(value_out);
    }

    //test 3
    {
        number_test++;
        int count_res = 0;
        //int res[] = {EMPTY_ARRAY};
        int *value_in = NULL;
        int *value_out = NULL;
        int *value_out_end = NULL;

        if (key(value_in, value_in + count_res, &value_out, &value_out_end))
        {
            ok_count++;
        }
        else
        {
            printf("test_key: test %d faild\n", number_test);
        }
        free(value_out);
    }
    
    //test 4
    {
        number_test++;
        int count_res = 5;
        int res[] =
            {
            0, 1, 2, -3, 4
            };
        int value_in[] =
            {
            0, 1, 2, -3, 4, -5, 6
            };
        int *value_out = NULL;
        int *value_out_end = NULL;

        if (!key(value_in, value_in + count_res, &value_out, &value_out_end) && !memcmp(res, value_out, count_res))
        {
            ok_count++;
        }
        else
        {
            printf("test_key: test %d faild\n", number_test);
        }
        free(value_out);
    }

    //result
    printf("%s: %s\n", name, (ok_count == number_test) ? "OK" : "FAILED");
}

void check_sort(void)
{
    int ok_count = 0;
    int number_test = 0;

    //test 1
    {
        number_test++;
        int count_res = 10;
        int res[] =
            {
            1, 2, 3, 4, 5, 5, 6, 6, 7, 7
            };
        int value[] =
            {
            1, 2, 3, 4, 5, 5, 6, 6, 7, 7
            };
        mysort(value, sizeof(value) / sizeof(value[0]), sizeof(value[0]), compare_int_and_ch);

        if (!memcmp(res, value, count_res))
        {
            ok_count++;
        }
        else
        {
            printf("test_sort: test %d faild\n", number_test);
        }
    }

    //test 2
    {
        number_test++;
        int count_res = 10;
        int res[] =
            {
            1, 2, 3, 4, 5, 5, 6, 6, 7, 7
            };
        int value[] =
            {
            6, 5, 7, 5, 4, 2, 7, 6, 1, 3
            };
        mysort(value, count_res, sizeof(value[0]), compare_int_and_ch);

        if (!memcmp(res, value, count_res))
        {
            ok_count++;
        }
        else
        {
            printf("test_sort: test %d faild\n", number_test);
        }
    }

    //test 3
    {
        number_test++;
        int count_res = 1;
        int res[] =
            {
            -1
            };
        int value[] =
            {
            -1
            };
        mysort(value, count_res, sizeof(value[0]), compare_int_and_ch);

        if (!memcmp(res, value, count_res))
        {
            ok_count++;
        }
        else
        {
            printf("test_sort: test %d faild\n", number_test);
        }
    }

    //test 4
    {
        number_test++;
        int count_res = 7;
        int res[] =
            {
            -5, -3, 0, 1, 2, 4, 6
            };
        int value[] =
            {
            6, 4, 2, 1, 0. -3, -5
            };
        mysort(value, count_res, sizeof(value[0]), compare_int_and_ch);

        if (!memcmp(res, value, count_res))
        {
            ok_count++;
        }
        else
        {
            printf("test_sort: test %d faild\n", number_test);
        }
    }

    //test 5
    {
        number_test++;
        int count_res = 5;
        double res[] =
            {
            1.0, 2.0, 3.0, 4.0, 5.0
            };
        double value[] =
            {
            1.0, 2.0, 3.0, 4.0, 5.0
            };
        mysort(value, count_res, sizeof(value[0]), compare_double);

        if (!memcmp(res, value, count_res))
        {
            ok_count++;
        }
        else
        {
            printf("test_sort: test %d faild\n", number_test);
        }
    }

    //test 6
    {
        number_test++;
        int count_res = 5;
        double res[] =
            {
            1.0, 2.0, 3.0, 4.0, 5.0
            };
        double value[] =
            {
            5.0, 4.0, 3.0, 2.0, 1.0
            };
        mysort(value, count_res, sizeof(value[0]), compare_double);

        if (!memcmp(res, value, count_res))
        {
            ok_count++;
        }
        else
        {
            printf("test_sort: test %d faild\n", number_test);
        }
    }
    
    // test7
    {
        number_test++;
        int count_res = 14;
        double res[] =
            {
            0.9, 1.0, 1.1, 1.2, 1.4, 1.5, 1.6, 4.1, 4.6, 7.2, 7.7, 8.4, 9.0, 9.9
            };
        double value[] =
            {
            1.4, 7.7, 1.6, 9.0, 1.2, 4.6, 1.1, 1.5, 0.9, 7.2, 8.4, 1.0, 4.1, 9.9
            };
        mysort(value, count_res, sizeof(value[0]), compare_double);

        if (!memcmp(res, value, count_res))
        {
            ok_count++;
        }
        else
        {
            printf("test_sort: test %d faild\n", number_test);
        }
    }

    //test 8
    {
        number_test++;
        int count_res = 5;
        char res[] =
            { 
            'a', 'b', 'c', 'd', 'e'
            };
        char value[] =
            {
            'a', 'b', 'c', 'd', 'e'
            };
        mysort(value, count_res, sizeof(value[0]), compare_int_and_ch);
        
        if (!memcmp(res, value, count_res))
        {
            ok_count++;
        }
        else
        {
            printf("test_sort: test %d faild\n", number_test);
        }
    }

    //test 9
    {
        number_test++;
        int count_res = 5;
        char res[] =
            { 
            'a', 'b', 'c', 'd', 'e'
            };
        char value[] =
            {
            'e', 'd', 'c', 'b', 'a'
            };
        mysort(value, sizeof(value) / sizeof(value[0]), sizeof(value[0]), compare_int_and_ch);

        if (!memcmp(res, value, count_res))
        {
            ok_count++;
        }
        else
        {
            printf("test_sort: test %d faild\n", number_test);
        }
    }

    //test 10
    {
        number_test++;
        int count_res = 5;
        char res[] =
            { 
            'a', 'b', 'c', 'd', 'e'
            };
        char value[] =
            {
            'c', 'a', 'e', 'b', 'd'
            };
        mysort(value, sizeof(value) / sizeof(value[0]), sizeof(value[0]), compare_int_and_ch);

        if (!memcmp(res, value, count_res))
        {
            ok_count++;
        }
        else
        {
            printf("test_sort: test %d faild\n", number_test);
        }
    }

    //result
    printf("%s: %s\n", name, (ok_count == number_test) ? "OK" : "FAILED");
}

void check_scan(void)
{
    int ok_count = 0;
    int number_test = 0;

    //test 1
    {
        number_test++;
        FILE * file_in = fopen("in_1.txt", "r");
        int count_res = 10;
        int res[] =
            {
            6, 5, 7, 5, 4, 2, 7, 6, 1, 3
            };
        int *pa = NULL;
        int *pb = NULL;
        scan_array(file_in, &pa, &pb);
        if (!memcmp(res, pa, count_res))
        {
            ok_count++;
        }
        else
        {
            printf("test_scan: test %d faild\n", number_test);
        }
        free(pa);
        fclose(file_in);
    }

    //test 2
    {
        number_test++;
        int count_res = 1;
        FILE * file_in = fopen("in_2.txt", "r");
        int res[] =
            {
            -1
            };
        int *pa = NULL;
        int *pb = NULL;
        scan_array(file_in, &pa, &pb);
        if (!memcmp(res, pa, count_res))
        {
            ok_count++;
        }
        else
        {
            printf("test_scan: test %d faild\n", number_test);
        }
        free(pa);
        fclose(file_in);
    }

    //test 3
    {
        number_test++;
        //int count_res = 0;
        //int res[] = {EMPTY_ARRAY};
        FILE * file_in = fopen("in_3.txt", "r");
        int *pa = NULL;
        int *pb = NULL;
        if (scan_array(file_in, &pa, &pb) == ERROR_EMPTY_FILE)
        {
            ok_count++;
        }
        else
        {
            printf("test_scan: test %d faild\n", number_test);
        }
        free(pa);
        fclose(file_in);
    }

    //test 4
    {
        number_test++;
        //int count_res = 0;
        //int res[] = {EMPTY_ARRAY};
        FILE * file_in = fopen("in_4.txt", "r");
        int *pa = NULL;
        int *pb = NULL;
        if (scan_array(file_in, &pa, &pb) == ERROR_EMPTY_FILE)
        {
            ok_count++;
        }
        else
        {
            printf("test_scan: test %d faild\n", number_test);
        }
        free(pa);
        fclose(file_in);
    }

    //result
    printf("%s: %s\n", name, (ok_count == number_test) ? "OK" : "FAILED");
}

void check_write(void)
{
    int ok_count = 0;
    int number_test = 0;

    //test 1
    {
        number_test++;
        int count_res = 18;
        int res[] =
            {
            -85, -70, -64, -57, -50, 8, 12, 16, 30, 44, 60, 60, 63, 70, 80, 82, 89, 96
            };
        FILE * file_out = fopen("out.txt", "w");
        write_to_file(file_out, res, res + count_res);
        fclose(file_out);

        FILE * file_in = fopen("out.txt", "r");
        int *pa = NULL;
        int *pb = NULL;
        int rc = scan_array(file_in, &pa, &pb);
        fclose(file_in);
        if (!rc && !memcmp(res, pa, count_res))
        {
            ok_count++;
        }
        else
        {
            printf("test_write_to_file: test %d faild\n", number_test);
        }
        free(pa);
    }

    //test 2
    {
        number_test++;
        //int count_res = 18;
        int res[] =
            {
            -85, -70, -64, -57, -50, 8, 12, 16, 30, 44, 60, 60, 63, 70, 80, 82, 89, 96
            };
        FILE * file_out = fopen("out.txt", "w");
        write_to_file(file_out, res, res + 0);
        fclose(file_out);

        FILE * file_in = fopen("out.txt", "r");
        int *pa = NULL;
        int *pb = NULL;
        if (scan_array(file_in, &pa, &pb) == ERROR_EMPTY_FILE)
        {
            ok_count++;
        }
        else
        {
            printf("test_write_to_file: test %d faild\n", number_test);
        }
        free(pa);
        fclose(file_in);
    }

    //result
    printf("%s: %s\n", name, (ok_count == number_test) ? "OK" : "FAILED");
}
