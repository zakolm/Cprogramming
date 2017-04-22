#include <stdio.h>
#include <math.h>
#define OK 0
#define ERROR 1
#define ERROR_INPUT 2
#define ERROR_INTERVAL 3

double summ(double x, double eps);

int scan_all(double *n)
{
    if (scanf("%lf", n))
        return OK;
    else
        return ERROR;
}

int error_in(void)
{
    printf("Error input!");
    return ERROR;
}

int error_interval(void)
{
    printf("Error interval!");
    return ERROR;
}

int main(void)
{
    int rc = OK;
    double x, eps;

    printf("Input x: ");
    rc = scan_all(&x);
    if (rc)
        return error_in();
    if (fabs(x) < 1)
    {
        printf("Input eps: ");
        rc = scan_all(&eps);
        if (rc)
            return error_in();
        if (eps > 0)
        {
            double S = summ(x, eps);
            printf("ARCSIN(%.4f): %.6f for Taylor\n", x, S);
            printf("Absolute ARCSIN(%.4f): %.6f\n", x, asin(x));
            printf("Absulute error: %f\n", fabs(S - asin(x)));
            if (asin(x) != 0)
            {
                double relative_error = fabs((S - asin(x))/asin(x));
                printf("Relative error: %f\n", relative_error);
            }
            else
                printf("Error!\nFunction = 0");
        }
        else
            return error_interval();
    }
    else
        return error_interval();
}

double summ(double x, double eps)
{
    int count = 3;
    double  x_pow = x, s = 1, s_next = x;
    unsigned long long int fact_n, fact_c;
    fact_n = fact_c = 1;

    while(fabs(s) > eps)
    {
        x_pow *= x*x;
        fact_n *= (count - 2);
        fact_c *= (count - 1);
        count += 2;

        s = (fact_n * x_pow) / (fact_c * count);
        s_next += s;
    }

    return s_next;
}
