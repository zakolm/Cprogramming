#include <stdio.h>

int main(void)
{
    // Объявление переменных.
    int number_apartment; //count;
    int number_floor, number_ac;

    // Считывание переменных.
    printf("Input number apartment: ");
    scanf("%d", &number_apartment);

    // Высчитываем номер подъезда и этажа.
    number_apartment--;
    number_ac = number_apartment/36 + 1;
    number_floor = (number_apartment - (number_ac - 1)*36)/4 + 1;

    // Вывод результатов.
    printf("Number floor: %d\n", number_floor);
    printf("Number access: %d", number_ac);
}
