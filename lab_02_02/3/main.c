#include <stdio.h>
#include <math.h>

float summ(float x, float eps);
int fact(int x_z);

int main()
{
    float x, eps;

    //
    printf("Input x: ");
    scanf("%f", &x);
    printf("Input eps: ");
    scanf("%f", &eps);

    //
    summ(x, eps);
    float a = asin(x);
    printf("\n%f", a);
    //printf("%d", fact(x));
}

float summ(float x, float eps)
{
    int count = 1;
    float s = 0, s_next = 0;

    while((count == 1) || (fabs(s_next - s) > eps))
    {
        s += (count * pow(x, count))/(fact(count - 1) * count);
        count += 2;
        s_next += (count * pow(x, count))/(fact(count - 1) * count);
        printf("[DBG]%f %f %d", s, s_next, count);
        printf("[DBG]%d\n", fabs(s_next - s) < eps);
    }
    return 0.0;
}

float new_summ()
{
    int i = 0;
    for(; i <= count; i++)
    {

    }
}

int fact(int x_z)
{
    if (x_z == 0 || )
    {
        return 1;
    }
    else
    {
        int i = 2, number = 1;
        for(; i <= x_z; i += 2)
        {
            number *= (-i);
        }
        return number;
    }
}
