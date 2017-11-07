#include "constant.h"
#include "WorkFile.h"

/*
* Функция подсчета кол-ва эл-тов в файле. Возвращает OK - все хорошо или ERROR_EMPTY_FILE - ошибка.
* file - файл откуда производится считывание.
* count - кол-во эле-тов в файле.
*/
int int_count_scan(FILE *file, int *count)
{
    int item = 0;
    int rc = fscanf(file, "%d", &item);
    while (rc == 1)
    {
        rc = fscanf(file, "%d", &item);
        (*count)++;
    }
    
    if (rc == -1 && (*count))
    {
        return OK;
    }

    *count = 0;
    return ERROR_EMPTY_FILE;
}
/*
* Функия считывания эл-тов из файла в массив.
* file - файл откуда производится считывание.
* pa - указатель на начало массива, в который производится считывание.
* pb - указатель на конец массива, в который производится считывание.
*/
void scan_array(FILE *file, int *pa, int *pb)
{
    int item = 0;
    fseek(file, 0, seek_set);
    while (pa < pb && fscanf(file, "%d", &item) == 1)
    {
        *pa = item;
        pa++;
    }
}
/*
* Функция печати массива в поток(консоль).  
* pa - указатель на начало массива, который будет напечатан.  
* pb - указатель на конец массива, который будет напечатан.  
*/
void print_list(int count, int *pa)
{
    for (int i = 0; i < count; ++i)
    {
        printf("%d ", *(pa + i));
    }
}
/*
* Функция печати массива в файл.  
* file - файл, в который будет произведена запись.  
* pa - указатель на начало массива, который будет напечатан.  
* pa - указатель на конец массива, который будет напечатан.
*/
void write_to_file(FILE *file, int *pa, int *pb)
{
    for (; pa < pb; pa++)
    {
        fprintf(file, "%d", *pa);
        if ((pa - pb) != 1)
        {
            fprintf(file, " ");
        }
    }
}