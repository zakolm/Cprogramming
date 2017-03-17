#include <stdio.h>
#include <math.h>

int main(void)
{
    // Объявление переменных.
    float v1, t1, v2, t2;
    float valueme;
    float temperature, dt;

    // Считывание переменных.
    printf("Input first volume and first temperature: ");
    scanf("%f %f", &v1, &t1);
    printf("Input second volume and second temperature: ");
    scanf("%f %f", &v2, &t2);

    // Высчитываем объем.
    valueme = v1 + v2;
    printf("Valueme: %7.4f\n", valueme);
    // Высчитываем температуру.
    dt = fabs((v2 * t2 - v1 * t1) / (v1 + v2));
    if (t1 > t2)
    {
        temperature = (t1 - dt);
    }
    else
    {
        temperature = (t1 + dt);
    }
    printf("Temperature: %7.4f", temperature);
}
