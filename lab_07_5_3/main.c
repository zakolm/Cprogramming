#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include "CONSTANT.h"
#include "MyMath.h"
#include "Work_File.h"

void print_list(int count, int *pa)
{
	for (int i = 0; i < count; ++i)
	{
		printf("%d ", *(pa+i));
	}
}

void write_to_file(FILE * file, int *pa, int *pb)
{
	for (; pa < pb; pa++)
	{
		fprintf(file, "%d ", *pa);
	}
}

int create_array_int(int **pa, int count)
{
	*pa = (int*)calloc(count, sizeof(int*));
	if (*pa == NULL)
	{
		return -1;
	}
	return 0;
}

int filter(FILE * file, int *pa, int *pb, int **pc)
{
	fseek(file, 0, SEEK_SET);
	int minus = (pb - pa) - 1;
	int item = 0;
	for (; pa < pb; pa++)
	{
		fscanf(file, "%d", &item);
		if (item < 0)
		{
			minus = (pb-pa);
		}
	}
	
	if (create_array_int(pc, minus))
	{
		return 0;
	}
	
	return minus;
}

int main(int argc, char **argv)
{
	if (argc != 3 && !(argc == 4 && !strcmp(argv[3],"-")))
	{
		printf("example.exe <name file> <name file> [f]\n");
		return ERROR_INPUT;
	}
	FILE * file_in = fopen(argv[1], "r");
	if (!file_in)
	{
		printf("file\n");
		return ERROR_EMPTY_FILE;
	}
	
	int rc = OK;
	int count = 0;
	int flag_filter = (argc < 4) ? 0 : 1;
	rc = int_count_scan(file_in, &count);//, flag_filter);
	
	if (!rc && count)
	{
		int *pa = NULL;
		if (!create_array_int(&pa, count))
		{
			int *pb = pa + count;
			scan_array(file_in, pa, pb);
			
			print_list(count, pa);
			
			if (flag_filter)
			{
				int *pc = NULL;
				count = filter(file_in, pa, pb, &pc);
				free(pa);
				if (!count)
				{
					fclose(file_in);
					return -1;
				}
				pa = pc;
				pb = pa + count;
				scan_array(file_in, pa, pb);
				printf("\n%d\n", count);
			}
			
			bubble_sort(pa, pb-pa, sizeof(*pa), compare_int_and_ch);
			
			printf("\n");
			print_list(count, pa);
			
			FILE * file_out = fopen(argv[2], "w");
			if (file_out != NULL)
			{
				write_to_file(file_out, pa, pb);
				fclose(file_out);
			}
			else
			{
				rc = ERROR_EMPTY_FILE;
			}
			free(pa);
		}
	}

	fclose(file_in);
	return OK;
}

/*
	double a = 2.5;
	double b = 1.5;
	int k = 1, g = 2;
	new_swap(8, a, b);
	printf("%f %f\n", a, b);
	*/
	/*
	double a[10] = {2.0, 2.5, -6.0, 1.1, 0.00003, 5, 8.1, 7.0, 9.0, 0.0};
	for ( int i = 0; i < 10; ++i ) {
		printf("%f ", a[i]);
	}
	printf("\n");
	//printf("%d\n", sizeof(a));
	BubbleSort(a, sizeof(a)/sizeof(a[0]), sizeof(a[0]), compare_double);
	for ( int i = 0; i < 10; ++i ) {
		printf("%f ", a[i]);
	}
	printf("\n");
	qsort(a, sizeof(a)/sizeof(a[0]), sizeof(a[0]), compare_double);
	for ( int i = 0; i < 10; ++i ) {
		printf("%f ", a[i]);
	}
*/

//char a[3] = "bda";
//char a[10] = {'a', 'q', 'e', 'z', 'd', 'b', 'w', 'p', 'r', 'y'};
//int a[10] = {2, 4, 6, 1, 3, 5, 8, 7, 9, 0};
//BubbleSort(a, 3, sizeof(char), compare);
//for (int i = 0; i < 2; ++i) {
//	printf("%d\n", *pa);
//}
//printf("%d", *pb);
