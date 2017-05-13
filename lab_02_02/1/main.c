#include <stdio.h>
#define OK 0
#define ERRORINTERVAL -1
#define ERRORINPUT -2
#define MAX_VALUE 93

unsigned long long int Fibonacci(int number)
{
    unsigned long long int main_value = 0; // a
    unsigned long long int side_value = 1; // b
    // Вычисление:
    for(int i = 0; i < number; i++)
    {
        main_value += side_value; // a + b = c
        side_value = main_value - side_value; // c - b = a
    }

    return main_value;
}

int print_error(int index);

int main(void)
{
    // Ввод данных.
    int number, rc = OK;
    unsigned long long int Fib_number;

    printf("\t\t0 < number < %d\n", MAX_VALUE);
    printf("Number Fibonacci: ");
    if (scanf("%d", &number))
        if(number <= MAX_VALUE && number >= 0)
        {
            // Вывод данных.
            Fib_number = Fibonacci(number);
            printf("Fibonacci: %llu", Fib_number);
        }
        else
        {
            printf("\nError interval!");
            return ERRORINTERVAL;
        }
    else
    {
        printf("\nError input!");
        return ERRORINPUT;
    }

    return OK;
}
