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
                float AB_x = x_b - x_a, AB_y = y_b - y_a;
                float CA_x = x_a - x_c, CA_y = y_a - y_c;
                float BC_x = x_c - x_b, BC_y = y_c - y_b;
                if (check_triagle(AB_x, AB_y, CA_x, CA_y))
                {
                    printf("Input coordinates(x, y) point O: ");
                    if (scanf("%f %f", &x_o, &y_o))
                    {
                        int s1,s2,s3;
                        s1 = check_location(AB_x, AB_y, x_o - x_a, y_o - y_a);
                        s2 = check_location(BC_x, BC_y, x_o - x_b, y_o - y_b);
                        s3 = check_location(CA_x, CA_y, x_o - x_c, y_o - y_c);
                        //printf("[DBG] %d %d %d\n", s1, s2, s3);

                        if ((s1 < 0 && s2 < 0 && s3 < 0) ||
                                (s1 > 0 && s2 > 0 && s3 > 0))
                            printf("Point in triagle");
                        else if (s1 == 0 || s2 == 0 || s3 == 0)
                            printf("Point on triagle");
                        else
                            printf("Point outside triagle");
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
    //printf("[DBG] {%f, %f} {%f, %f}\n", x_1, y_1, x_2, y_2);
    //printf("[DBG] %f\n", (x_1*y_2 - x_2*y_1));
    if ((x_1*y_2 - x_2*y_1) > 0)
        return 1;
    else if ((x_1*y_2 - x_2*y_1) < 0)
        return -1;
    else
        return 0;
}
