#include <stdio.h>
#define OK 0
#define ERROR 1

unsigned long long int Fibonacci(int number)
{
    unsigned long long int temp = 0; // a
    unsigned long long int tmp = 1; // b
    // Вычисление:
    for(int i = 0; i < number; i++)
    {
        temp += tmp; // a + b = c
        tmp = temp - tmp; // c - b = a
    }

    return temp;
}

int main(void)
{
    // Ввод данных.
    int number;
    unsigned long long int temp;
    setbuf(stdout,NULL);
    printf("\t\t0 < number < 93\n");
    printf("Number Fibonacci: ");
    //setbuf(stdout,NULL);
    scanf("%d", &number);
    if (number && number < 94)
    {
        // Вывод данных.
        temp = Fibonacci(number);
        printf("Fibonacci: %llu", temp);

        return OK;
    }
    else
    {
        printf("Error!");

        return ERROR;
    }
}
