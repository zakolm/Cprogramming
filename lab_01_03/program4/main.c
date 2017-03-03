#include <stdio.h>

int main(void)
{
    // Объявление переменных.
    int number_apartment, count;
    int number_floor, number_ac;

    // Считывание переменных.
    printf("Input number apartment: ");
    scanf("%d", &number_apartment);

    // Высчитываем номер подъезда и этажа.
    number_ac = 0;
    for(;;)
    {
        for(count=1; count < 10; count++)
        {
            if (number_apartment > 0)
            {
                number_apartment -= 4;
            }
            else
            {
                break;
            }
        }
        number_ac++;
        if (number_apartment <= 0)
            break;
    }
    // Фиксируем номер этажа.
    number_floor = count-1;
    printf("Number floor: %d\n", number_floor);
    printf("Number access: %d", number_ac);
}
