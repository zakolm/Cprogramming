#include <stdio.h>
#define COUNT_APARTMENT_AC 36
#define COUNT_APARTMENT_FLOOR 4

int main(void)
{
    // Объявление переменных.
    int number_apartment;
    int number_floor, number_ac;

    // Считывание переменных.
    printf("Input number apartment: ");
    scanf("%d", &number_apartment);

    // Высчитываем номер подъезда и этажа.
    number_apartment--;
    number_ac = number_apartment / COUNT_APARTMENT_AC + 1;
    number_floor = (number_apartment - (number_ac - 1) * COUNT_APARTMENT_AC)
            / COUNT_APARTMENT_FLOOR + 1;

    // Вывод результатов.
    printf("Number floor: %d\n", number_floor);
    printf("Number access: %d", number_ac);
}
