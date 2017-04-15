#include <stdio.h>
#define OK 0
#define ERROR 1
#define MAX_VALUE 94

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

int print_error(string str_error);

int main(void)
{
    // Ввод данных.
    int number;
    unsigned long long int temp;
    setbuf(stdout,NULL);
    printf("\t\t0 < number < 93\n");
    printf("Number Fibonacci: ");
    //setbuf(stdout,NULL);
    //scanf("%d", &number);
    if (scanf("%d", &number))
        if(number < MAX_VALUE)
        {
            // Вывод данных.
            temp = Fibonacci(number);
            printf("Fibonacci: %llu", temp);

            return OK;
        }
    else
        return print_error('input');
}

int print_error(string str_error)
{
    printf("Error! %s", str_error);

    return ERROR;
}
