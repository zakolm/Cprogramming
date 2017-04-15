#include <stdio.h>
#include <math.h>
#define OK 0
#define ERROR 1

int main(void)
{
    double x_i, p_i, math_w = 0, math_double_w = 0;
    int count, i = 1;
    printf("Input count elements: ");
    scanf("%d", &count);// i = 1;
    for (; i <= count; i++)
    {
        printf("Input element and probability: ");
        scanf("%lf %lf", &x_i, &p_i);
        math_w = math_w + x_i*p_i;
        math_double_w = math_double_w + pow(x_i,2) + pow(p_i,2);
        //printf("%lf", temp);
        printf("[DBG]%d\t%lf\t%lf\n", i, math_w, math_double_w);
    }
}
