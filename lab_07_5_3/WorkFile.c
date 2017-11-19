#include "constant.h"
#include "WorkFile.h"
#include "MyMath.h"

/*
* Функция подсчета кол-ва эл-тов в файле. Возвращает OK - все хорошо или ERROR_EMPTY_FILE - ошибка.
* file - файл откуда производится считывание.
* count - кол-во эле-тов в файле.
*/
static int int_count_scan(FILE *file, int *count)
{
    *count = 0;
    int item = 0;
    int rc = fscanf(file, "%d", &item);
    if (rc == 1)
    	(*count)++;
    while ((rc = fscanf(file, "%d", &item)) == 1)
    {
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
int scan_array(FILE *file, int **pa, int **pb)
{
    int count = 0;
    int rc = OK;
    rc = int_count_scan(file, &count);
    if (rc)
    {
        return rc;
    }

    rc = create_array_int(pa, count);
    if (rc)
    {
        return rc;
    }
    
    *pb = *pa + count;
    int *pc = *pa;
    fseek(file, 0, seek_set);
    while (pc < *pb && fscanf(file, "%d", pc) == 1)
    {
        pc++;
    }
    return rc;
}
/*
* Функция печати массива в поток(консоль).  
* pa - указатель на начало массива, который будет напечатан.  
* pb - указатель на конец массива, который будет напечатан.  
*/
void print_list(int count, const int *pa)
{
    for (int i = 0; i < count; ++i, ++pa)
    {
        printf("%d ", *pa);
    }
}
/*
* Функция печати массива в файл.  
* file - файл, в который будет произведена запись.  
* pa - указатель на начало массива, который будет напечатан.  
* pa - указатель на конец массива, который будет напечатан.
*/
void write_to_file(FILE *file, const int *pa, const int *pb)
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
