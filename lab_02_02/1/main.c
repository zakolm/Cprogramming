#include <stdio.h>

int Fibonacci(int number)
{
    int temp = 1;
    int x;
    for(int i=1; i<number; i++)
    {
        x = temp;
        temp += x;
    }

    return temp;
}

int main(void)
{
    //
    int number, temp;
    printf("Number Fibonacci: ");
    scanf("%d", &number);
    //
    temp = Fibonacci(number);
    printf("Fibonacci: %d", temp);
}
