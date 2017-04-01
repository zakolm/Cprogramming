#include <stdio.h>

int Fibonacci(int number)
{
    int temp = 0; // a
    int tmp = 1; // b
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
    int number, temp;
    printf("Number Fibonacci: ");
	setbuf(stdout,NULL);
    if (scanf("%d", &number))
    {
        // Вывод данных.
        temp = Fibonacci(number);
        printf("Fibonacci: %d", temp);
    }
    else
        printf("Error!");
}
