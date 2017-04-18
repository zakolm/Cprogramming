#include <stdio.h>
#include <math.h>
#define OK 0
#define ERROR 1

void string_hello(char string , float *p, float *z, int *error)
{
    printf("Input triangle coordinates(x, y) point %c: ", string);
    if (scanf("%f %f", p, z) == 2)
        *error =  OK;
    else
        *error = ERROR;
}
int error_in(char string)
{
    printf("\nError input point %c!", string);
    return ERROR;
}

int check_triagle(float x_1, float y_1, float x_2, float y_2);

void print_info_point(float x_a, float y_a, float x_b, float y_b,
                      float x_c, float y_c, float x_o, float y_o);

int main(void)
{
    int rc = OK;
    float x_a, y_a, x_b, y_b, x_c, y_c;
    float x_o, y_o;

    string_hello('A', &x_a, &y_a, &rc);
    if (rc)
        return error_in('A');
    string_hello('B', &x_b, &y_b, &rc);
    if (rc)
        return error_in('B');
    string_hello('C', &x_c, &y_c, &rc);
    if (rc)
        return error_in('C');
    if (!(check_triagle(x_b - x_a, y_b - y_a, x_a - x_c, y_a - y_c)))
    {
        printf("Input coordinates(x, y) point O: ");
        if (scanf("%f %f", &x_o, &y_o) == 2)
            print_info_point(x_a, y_a, x_b, y_b, x_c, y_c, x_o, y_o);
        else
            return error_in('O');
    }
    else
    {
        printf("Error triagle!");
        return ERROR;
    }

    return OK;
}

int check_triagle(float x_1, float y_1, float x_2, float y_2)
{
    if ((x_1*y_2 - x_2*y_1) == 0)
        return ERROR;
    else
        return OK;
}

int check_location(float x_1, float y_1, float x_2, float y_2)
{
    if ((x_1*y_2 - x_2*y_1) > 0)
        return 1;
    else if ((x_1*y_2 - x_2*y_1) < 0)
        return -1;
    else
        return 0;
}

void print_info_point(float x_a, float y_a, float x_b, float y_b,
                      float x_c, float y_c, float x_o, float y_o)
{
    int s1, s2, s3;
    s1 = check_location(x_b - x_a, y_b - y_a, x_o - x_a, y_o - y_a);
    s2 = check_location(x_c - x_b, y_c - y_b, x_o - x_b, y_o - y_b);
    s3 = check_location(x_a - x_c, y_a - y_c, x_o - x_c, y_o - y_c);

    if ((s1 < 0 && s2 < 0 && s3 < 0) ||
            (s1 > 0 && s2 > 0 && s3 > 0))
        printf("Point in triagle");
    else if (s1 == 0 || s2 == 0 || s3 == 0)
        printf("Point on triagle");
    else
        printf("Point outside triagle");
}
