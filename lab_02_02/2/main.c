#include <stdio.h>
#include <math.h>

int string_hello(char string , float *p, float *z)
{
    printf("Input triangle coordinates(x, y) point %c: ", string);
    if (scanf("%f %f", &*p, &*z) == 2)
        return 1;
    else
        return 0;
}

int check_triagle(float x_1, float y_1, float x_2, float y_2);
int check_location(float x_1, float y_1, float x_2, float y_2);

int main(void)
{
    float x_a, y_a, x_b, y_b, x_c, y_c;
    float x_o, y_o;

    if (string_hello('A', &x_a, &y_a))
    {
        if (string_hello('B', &x_b, &y_b))
        {
            if (string_hello('C', &x_c, &y_c))
            {
                //printf("[DBG]%f %f\n", x_a, y_a);
                float AB_x = x_b - x_a, AB_y = y_b - y_a;
                float AO_x = x_o - x_a, AO_y = y_o - y_a;
                float AC_x = x_c - x_a, AC_y = y_c - y_a;
                float BC_x = x_c - x_b, BC_y = y_c - y_b;
                if (check_triagle(AB_x, AB_y, AC_x, AC_y))
                {
                    printf("Input coordinates(x, y) point O: ");
                    if (scanf("%f %f", &x_o, &y_o))
                    {
                        int s1,s2,s3;
                        s1 = check_location(AB_x, AB_y, AO_x, AO_y);
                        s2 = check_location(AC_x, AC_y, AO_x, AO_y);
                        s3 = check_location(BC_x, BC_y, x_o - x_b, y_o - y_b);
                        //printf("[DBG] %d %d %d\n", s1, s2, s3);

                        if ((s1+s2+s3)/3 == 1)
                            printf("Point in triagle");
                        else if ((s1+s2+s3)/3 > 1)
                            printf("Point outside triagle");
                        else
                            printf("Point on triagle");
                    }
                    else
                        printf("There is no such triagle!");
                }
            }
            else
                printf("Error!");
        }
        else
            printf("Error!");
    }
    else
        printf("Error!");
}

int check_triagle(float x_1, float y_1, float x_2, float y_2)
{
    if ((x_1*y_2 - x_2*y_1) == 0)
        return 0;
    else
        return 1;
}

int check_location(float x_1, float y_1, float x_2, float y_2)
{
    if ((x_1*y_2 - x_2*y_1) > 0)
        return 3;
    else if ((x_1*y_2 - x_2*y_1) < 0)
        return 1;
    else
        return 0;
}
