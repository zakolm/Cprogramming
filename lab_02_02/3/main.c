#include <stdio.h>
#include <math.h>
#define OK 0
#define ERROR 1

double summ(double x, double eps);
int fact(int x_z);

int print_error(void)
{
    printf("Error!");
    return ERROR;
}

int main()
{
    double x, eps;

    printf("Input x: ");
    if (scanf("%lf", &x) && (fabs(x) < 3))
    {
        printf("Input eps: ");
        if (scanf("%lf", &eps))
        {
            double S = summ(x, eps);
            printf("ARCSIN(%.4f): %.6f for Taylor\n", x, S);
            printf("Absolut ARCSIN(%.4f): %.6f\n", x, asin(x));
            printf("Absulut error: %f\n", fabs(S - asin(x)));
            if (asin(x) != 0)
            {
                double relative_error = fabs((S - asin(x))/asin(x));
                printf("Relative error: %f\n", relative_error);
            }
            else
                printf("Error!\nFunction = 0");

            return OK;
          }
        else
            return print_error();
    }
    else
        return print_error();
}

double summ(double x, double eps)
{
    int count = 3, count_z = 1;
    double s = 0, s_next = x;
    unsigned long long int fact_n, fact_c;
    fact_n = fact_c = 1;
    double x_pow = x;
    while(fabs(s_next - s) > eps)
    {
        fact_n *= (count - 2);
        fact_c *= (count - 1);
        for (; count_z < count; count_z++)
            x_pow *= x;
        //printf("[DBG] %llu %llu\n", fact_n, fact_c);
        //printf("[DBG]%f %f\n", s_next, s);
        s = s_next;
        s_next += (fact_n * x_pow) / (fact_c * count);
        count += 2;
    }
    return s;
}
