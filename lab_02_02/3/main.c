#include <stdio.h>
#include <math.h>
#define OK 0
#define ERROR 1
#define ERROR_INPUT 2
#define ERROR_INTERVAL 3

double summ(double x, double eps);

int main(void)
{
    int rc = OK;
    double x, eps;

    printf("Input x: ");
    if (scanf("%lf", &x))
        if (fabs(x) < 1)
        {
            printf("Input eps: ");
            if (scanf("%lf", &eps))
                if (eps > 0)
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
                }
                else
                    rc = ERROR_INTERVAL;
            else
                rc = ERROR_INPUT;
       }
        else
            rc = ERROR_INTERVAL;
    else
        rc = ERROR_INPUT;


    if (rc == OK)
        return OK;
    else if (rc == ERROR_INPUT)
    {
        printf("Error input!");
        return ERROR;
    }
    else
    {
        printf("Error interval!");
        return ERROR;
    }
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
