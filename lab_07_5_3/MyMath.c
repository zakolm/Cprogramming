#include <stdio.h>
#include <stdlib.h>

#include "constant.h"
#include "MyMath.h"

/*
* Функция создания(выделения памяти) для массива целых чисел(int). Используется больщое кол-во раз. Возвращает OK - все хорошо или ERROR_MEMORY - ошибка.  
* pa - указатель на начало создаваемого массива.  
* count - кол-во элементов необходимого массива.  
*/
int create_array_int(int **pa, int count)
{
    *pa = (int*)calloc(count, sizeof(int*));
    if (*pa == NULL)
    {
        return ERROR_MEMORY;
    }
    return OK;
}
/*
* Функция фильтр:
* * В массиве остаются элементы от нулевого до p-го, где p - индекс последнего
* * отрицательного элемента этого массива либо число n, если такого элемента в массиве нет.
* * Т.е. отфильтрованный массив содержит элементы,
* * расположенные перед первым отрицательным элементом, или весь исходный массив,
* * если отрицательные элементы отсутствуют.
* Возвращает OK - все хорошо, или ERROR_COUNT_ELEMENTS - ошибка кол-ва элементов нового массива, или ERROR_MEMORY - ошибка выделения памяти.
* pb_src - указатель на начало исходного массива.
* pe_src - указатель на конец исходного массива.
* pb_dst - указатель на начало нового массива.
* pe_dst - указатель на конец нового массива.
*/
int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{
    int count = pe_src - pb_src;
    int count_new = 0;
    const int *pa = pb_src;
    for (; pa < pe_src; pa++)
    {
        if (*pa < 0)
        {
            count_new = (pe_src - pa);
        }
    }
    count -= count_new;
    if (count <= 0)
    {
        return ERROR_COUNT_ELEMENTS;
    }
    if (create_array_int(pb_dst, count))
    {
        return ERROR_MEMORY;
    }
    *pe_dst = *pb_dst + count;

    int *pc = *pb_dst;
    pa = pb_src;
    for (; pc < *pe_dst; ++pc, ++pa)
    {
        *pc = *pa;
    }
    
    return OK;
}
/*
* Функция обмена значений переменных.
* a - указатель на первый элемент.
* b - указатель на второй элемент.
* size - размер типа элементов.
*/
void swap(void *a, void *b, int size)
{
    char *f = a;
    char *g = b;
    for (int i = 0; i < size; ++i)
    {
        char tmp;

        tmp = *f;
        *f = *g;
        *g = tmp;

        f++;
        g++;
    }
}

/*
* Функция сравнения для целых чисел(int) и символов(char). Возвращает разность полученных чисел:
* * 1) <0, если (first_item < second_item).
* * 2) 0, если (first_item == second_item).
* * 3) >0, если (first_item > second_item).
* first_item - первый элемент сравнения.
* second_item - второй элемент сравнения.
*/
int compare_int_and_ch(const void *first_item, const void *second_item)
{
    return (*(char*)first_item - *(char*)second_item);//(*(char*)second_item - *(char*)first_item);
}
/*
* Функция сравнения для чисел с плавающей точкой. Возвращает разность полученных чисел:
* * 1) -1, если (first_item < second_item).
* * 2) 0, если (first_item == second_item).
* * 3) 1, если (first_item > second_item).
* first_item - первый элемент сравнения.
* second_item - второй элемент сравнения.
*/
int compare_double(const void *first_item, const void *second_item)
{
    return (*(double*)first_item < *(double*)second_item) ? -1 : (*(double*)first_item > *(double*)second_item) ? 1 : 0;
}
/*
* Функия сортировки:
* * Модифицированная сортировка пузырьком I. Запоминайте, где произошел последний
* * обмен элементов, и при следующем проходе алгоритм не заходит за это место. Если
* * последними поменялись i-ый и i+1-ый элементы, то при следующем проходе алгоритм не
* * сравнивает элементы за i-м.
* basic - указатель на начало массива, который мы хотим отсортировать.
* count - кол-во эле-тов в массиве.
* size - размер типа эл-тов массива.
* comp - функция сравнения эл-тов массива.
*/
void mysort(void *basic, size_t count, size_t size, int (*comp)(const void*, const void*))
{
    if (count == 1)
        return;
    char *pb = (char*)basic + count * size;
    char *bar = pb;
    char *tmp = pb;
    //int flag = 0;
    //int len = count;
    for (char *pa = (char*)basic; pa < pb; pa += size)
    {
        //flag = 0;
        for (char *pc = (char*)basic; pc < pb - size; pc += size)
        {
	    if (pc < bar)
	    {
                if (comp(pa, pa + size) > 0)
                {
                    swap(pa, pa + size, size);
                    //flag = 1;
		    tmp = pc;
                }
	    }
	    else
	    {
		    bar = tmp;
	    }
        }
        //len--;
    }// while (flag && len > 1);
}
