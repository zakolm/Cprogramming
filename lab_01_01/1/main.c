#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979323846

int main(void)
{
    // Объявление переменных.
    float angle, less_base, large_base;
    float square;

    // Считывание переменных.
    printf("Input large base: ");
    scanf("%f", &large_base);
    printf("Input less base: ");
    scanf("%f", &less_base);
    printf("Input angle: ");
    scanf("%f", &angle);

    // Высчитываем площадь и выводим ее.
    square=(fabs(large_base-less_base)/2)*sin(angle*PI/180)/cos(angle*PI/180);
    printf("Square = %7.4f", square);
}
