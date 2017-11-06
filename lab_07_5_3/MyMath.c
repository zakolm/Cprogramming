#include <stdio.h>
#include <stdlib.h>

#include "constant.h"
#include "MyMath.h"

int create_array_int(int **pa, int count)
{
    *pa = (int*)calloc(count, sizeof(int*));
    if (*pa == NULL)
    {
        return ERROR_MEMORY;
    }
    return 0;
}

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
    printf("\n%d\n", count);
    if (count <= 0 || create_array_int(pb_dst, count))
    {
        return -1;
    }
    *pe_dst = *pb_dst + count;

    int *pc = *pb_dst;
    pa = pb_src;
    for (; pc < *pe_dst; ++pc, ++pa)
    {
		*pc = *pa;
    }
    
    return OK;//count;
}

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


int compare_int_and_ch(const void *first_item, const void *second_item)
{
    return (*(char*)second_item - *(char*)first_item);
}

int compare_double(const void *first_item, const void *second_item)
{
    //printf("%d\n", *(double*)first_item > *(double*)second_item);
    return (*(double*)first_item > *(double*)second_item) ? 1 : (*(double*)first_item < *(double*)second_item) ? -1 : 0;
  /*
    if (*(double*)first_item > *(double*)second_item) {
      return 1;
  } else if (*(double*)first_item < *(double*)second_item) {
      return -1;
  } else {
      return 0;
  }
  */
}
/*
void mysort(void *basic, size_t count, size_t size, int (*comp)(const void*, const void*))
{
	//if (count != 1)
	//{
	char *a = basic;
	char *pa = (char*)basic;
	char *pb = (char*)basic + count * size;
	int flag = 1;
	do
	{
		flag = 0;
		for (; pa < pb; pa += size)
		{
			char *pc = (char*)basic;
			for (; pc < pb - size - ((pa - a) / size); pc += size)
			{
				char *temp = pc;
				if (comp(temp, pc + size) < 0)
				{
					swap(temp, (pc + size), size);
					flag = 1;
				}
			}
		}
	} while (flag == 0);
	//}
}
*/
void mysort(void *basic, size_t count, size_t size, int (*comp)(const void*, const void*))
{
	if (count <= 1 || !basic)
	{
		return;
	}
	char *pb = (char*)basic + count * size;
	int flag = 0;
	int len = count;
	do
	{
		flag = 0;
		//for (; pa < pb - size; pa += size)
		//{
		//char *pc = pa + size;
		for (char *pa = (char*)basic; pa < pb - size; pa += size)
		{
			if (comp(pa, pa + size) < 0)
			{
				swap(pa, pa + size, size);
				flag = 1;
			}
		}
		//}
	len--;
	} while(flag && len > 1);
}

/*
 void modif_bubble(int *m, int n) // Модифицированный пузырек

{

int i=n,t; // Длина неотсортированной части массива

int f;

do {

f=0; //Предположим, что массив является отсортированным

for (int k=0;k<i-1;k++)

if (m[k]>m[k+1])

{

t=m[k]; m[k]=m[k+1]; m[k+1]=t; // Обмен

f=1; // Массив был неотсортированным

}

i--;

} while (f && i>1);

}
*/