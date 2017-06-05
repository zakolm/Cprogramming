#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#define MAXLENGTH 10
#define OK 0
#define ERROR_INPUT -1

int input(int*);
int menu(void);
void sum_comp(int*, int*, int*, int);
int new_array(int*, int*, int);
int del_negative_elem(int*, int);
int work_items(int*, int, int*);
void switch_element(int*, int);
void work_numbers3(int*, int);
void min_sort_max(int*, int);
void quick_sort(int*, int, int);

int main(void)
{
	int a[2*MAXLENGTH];
	int len, number_menu;
	int rc = OK;
	len = input(a);
	if (!len)
	{
		printf("Error input!");
		rc = ERROR_INPUT;
	}
	// PROGRAM
	if (!rc)
	{
	number_menu = menu();
	switch (number_menu)
	{
		case 0:
			break;
		case 1:
		{
			int sum = 0, comp = 1;
			sum_comp(&sum, &comp, a, len);
			printf("\nsum is %d\ncomp is %d\n", sum, comp);
			break;
		}
		case 2:
		{
			int b[len];
			int len_new_array;
			len_new_array = new_array(a, b, len);
			int i = 0;
			printf("\nNew Array:\n");
			for (; i < len_new_array; ++i)
				printf("%d ", b[i]);
			printf("\n");
			break;
		}
		case 3:
		{
			int i = 0;
			len = del_negative_elem(a, len);
			printf("\nArray:\n");
			if (!len)
				printf("Empty array!");
			for (; i < len; ++i)
				printf("%d ", a[i]);
			printf("\n");
			break;
		}
		case 4:
		{
			int temp;
			printf("\nInput items: ");
			fscanf(stdin, "%d", &temp);
			len = work_items(a, len, &temp);
			int i = 0;
			for (; i < len; ++i)
				printf("%d ", a[i]);
			printf("\n");
			break;
		}
		case 5:
		{
			switch_element(a,len);
			int i = 0;
			printf("\nResult:\n");
			for (; i < len; ++i)
				printf("%d ", a[i]);
			printf("\n");
			break;
		}
		case 6:
		{
			work_numbers3(a, len);
			int i = 0;
			printf("\nResult:\n");
			for (; i < len; ++i)
				printf("%d ", a[i]);
			printf("\n");
			break;
		}
		case 7:
		{
			min_sort_max(a, len);
			printf("\nResult:\n");
			int i = 0;
			for (; i < len; ++i)
				printf("%d ", a[i]);
			printf("\n");
			break;
		}
	}
	}
	return rc;
}
// INPUT OF ARRAY
int input(int* pa)
{
	int len = 0, i;
	len = i = 0;
	char temp;
	
	for (;(i < MAXLENGTH) && (fscanf(stdin, "%d", (pa+i)) == 1); ++i)
		len++;
	if (len < MAXLENGTH)
		fscanf(stdin, "%c", &temp);
	return len;
}
//MENU
int menu(void)
{
	int number = -1, temp;
	while (number < 0 || number > 7)
	{
		printf("\n0- Exit\n");
		printf("1- Finding the sum of even elements and multiplication of uneven elements in array\n");
		printf("2- Finding elements more average\n");
		printf("3- Remove from the array all the negative elements\n");
		printf("4- Adding after elements value\n");
		printf("5- To make changes in array: max between even elements and min between uneven elements\n");
		printf("6- To record in place of maximum that multiple of 3 amount of elements that ends on 3\n");
		printf("7- Sort the elements that located between the min and max elements of the array\n");
		printf("Input item menu>>>");
		if (fscanf(stdin, "%d", &number) != 1)
			fscanf(stdin, "%c", &temp);
	}
	return number;
}
// NUMBER_MENU == 1
void sum_comp(int* sum, int* comp, int* pa, int len)
{
	int i = 0;
	for (; i < len; ++i)
	{
		if (i%2)
			*sum += *(pa+i);
		else
			*comp *= *(pa+i);
	}
}
// NUMBER_MENU == 2
int new_array(int* pa, int* pb, int len)
{
	int i = 0, j = 0, middle = 0;
	for (; i < len; ++i)
		middle += *(pa+i);
	middle /= len; i = 0;
	for (; i < len; ++i)
		if (*(pa+i) > middle)
		{
			*(pb+j) = *(pa+i); j++;
		}
	return j;
}
// NUMBER_MENU == 3
int del_negative_elem(int* pa, int len)
{
	int i, j, temp;
	i = j = 0;
	for (; i < len; ++i)
	{
		if (*(pa+i) < 0)
		{
			j = i; temp = *(pa+i);
			for (; j < len-1; ++j)
				*(pa+j) = *(pa+j+1);
			len--;i--;
			*(pa+len) = temp;
		}
	}
	return len;
}
// NUMBER_MENU == 4
int work_items(int* pa, int len, int* temp)
{
	int tmp, tmp2, count = 0, sum = 0;
	int j, i = 0;
	for (; i < len; ++i)
	{
		sum += *(pa+i);
		if (*(pa+i) == *temp)
		{
			count++;
			j = i+2; tmp2 = *(pa+j-1);
			*(pa+i+1) = sum;
			for (; j < len+count; ++j)
			{
				tmp = *(pa+j);
				*(pa+j) = tmp2;
				tmp2 = tmp;
			}
			sum = 0;
		}
	}
	return (len+count);
}
// NUMBER_MENU == 5
void switch_element(int* pa, int len)
{
	int max = *(pa+1), min = *pa;
	int max_position, min_position;
	int i = 0;
	for (; i < len; ++i)
	{
		if ((i%2) && (max < *(pa+i)))
		{
			max_position = i;
			max = *(pa+i);
		}
		if (!(i%2) && (min > *(pa+i)))
		{
			min_position = i;
			min = *(pa+i);
		}
	}
	int temp = *(pa+max_position);
	*(pa+max_position) = *(pa+min_position);
	*(pa+min_position) = temp;
}
// NUMBER_MENU == 6
void work_numbers3(int* pa, int len)
{
	int elements_position, sum = 0;
	int max = 41;
	int i = 0;
	for (; i < len; ++i)
	{
		if (!(*(pa+i)%3))
		{
			elements_position = i;
			max = *(pa+i);
			break;
		}
	}
	if (max%3)
	{
		printf("ERROR");
		return;
	}
	i = 0;
	for (; i < len; ++i)
	{
		if (*(pa+i)%10 == 3)
			sum += *(pa+i);
		if (((*(pa+i)%3) == 0) && (max < *(pa+i)))
			elements_position = i;
	}
	*(pa+elements_position) = sum;
}
// NUMBER_MENU == 7
void min_sort_max(int* pa, int len)
{
	int left = 0, right = 0, temp, i = 0, max = *pa, min = *pa;
	for (; i < len; ++i)
	{
		if (*(pa+i) > max)
		{
			max = *(pa+i); right = i;
		}
		if (*(pa+i) < min)
		{
			min = *(pa+i); left = i;
		}
	}
	if (left > right)
	{
		temp = left; left = right; right = temp;
	}
	quick_sort(pa, left, right);
}

void quick_sort(int* pa, int left, int right)
{
	int middle = *(pa+((left+right)/2));
	int i = left, j = right;
	int temp;
	do
	{
		while (*(pa+i) < middle) i++;
		while (*(pa+j) > middle) j--;
		if (i <= j)
		{
			temp = *(pa+i);
			*(pa+i) = *(pa+j);
			*(pa+j) = temp;
			i++; j--;
		}
	}while(i <= j);
	if (left < j)  quick_sort(pa, left, j);
	if (i < right) quick_sort(pa, i, right);
}

