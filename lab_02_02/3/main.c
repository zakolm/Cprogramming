#include <stdio.h>
#include <math.h>

float summ(float x, float eps);
int fact(int x_z);

int main()
{
    float x, eps;

    printf("Input x: ");
    if (scanf("%f", &x) && fabs(x)<1)
    {
        printf("Input eps: ");
        if (scanf("%f", &eps))
        {
            float S = summ(x, eps);
            printf("ARCSIN(%.4f): %.6f for Taylor\n", x, S);
            printf("Absolut ARCSIN(%.4f): %.6f\n", x, asin(x));
            printf("Absulut error: %f\n", fabs(S - asin(x)));
            if (asin(x) != 0)
            {
                float relative_error = fabs((S - asin(x))/asin(x));
                printf("Relative error%f\n", relative_error);
            }
            else
                printf("Error!\nFunction = 0");
          }
        else
            printf("Error!");
    }
    else
        printf("Error!");
}

float summ(float x, float eps)
{
    int count = 3;
    float s = 0, s_next = x;

    while(fabs(s_next - s) >= eps)
    {
        s = s_next;
        s_next += (fact(count - 2) * pow(x, count))/(fact(count - 1) * count);
        count += 2;
    }
    return s;
}

int fact(int x_z)
{
    if (x_z == 1)
        return 1;
    else
    {
        int i = (x_z % 2) + 2, number = 1;
        for(; i <= x_z; i += 2)
            number *= i;
        return number;
    }
}
