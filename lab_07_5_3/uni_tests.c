#include <stdio.h>
#include <stdlib.h>

#include "constant.h"
#include "MyMath.h"
#include "WorkFile.h"

#define name __func__

void check_key(void);
void check_sort(void);

int main(void)
{
	check_key();
	check_sort();
	return OK;
}

int list_check(size_t count, size_t size, void *pa_src, void *res_src)
{
	char *res = (char*)res_src;
	char *pb = (char*)pa_src + count * size;
	for (char *pa = (char*)pa_src; pa < pb; ++pa, ++res)
	{
		if (*pa != *res)
		{
			return 0;
		}
	}
	
	return 1;
}

void check_key(void)
{
	int ok_count = 0;
	// test1
	{
		int res[] =
		{
			1, 2, 3, 4, 5, 5, 6, 6, 7, 7
		};
		int count_res = 10;
		FILE * file = fopen("in_1.txt", "r");
		if (!file)
		{
			printf("Error\n");
		}
		else
		{
			int count = 0;
			int rc = int_count_scan(file, &count);
			if (!rc && count && count == count_res)
			{
				int *pa = NULL;
				if (!create_array_int(&pa, count))
				{
					int *pb = pa + count;
					scan_array(file, pa, pb);
					int *pc = NULL;
					int *pd = NULL;
					int sup_flag = key(pa, pb, &pc, &pd);
					free(pa);
					if (sup_flag == -1 || !(pd - pc))
					{
						printf("Error\n");
					}
					else
					{
						pa = pc;
						pb = pd;
						mysort(pa, pb - pa, sizeof(*pa), compare_int_and_ch);
						if (list_check(count, sizeof(int), pa, res))
						{
							ok_count++;
						}
						free(pa);
					}
				}
				else
				{
					printf("Error\n");
				}
			}
			else
			{
				printf("Error\n");
			}
		}
	}
	// test2
	{
		//int res[] = {};
		int count_res = 0;
		FILE * file = fopen("in_2.txt", "r");
		if (!file)
		{
			printf("Error\n");
		}
		else
		{
			int count = 0;
			int rc = int_count_scan(file, &count);
			if (!rc && count)
			{
				int *pa = NULL;
				if (!create_array_int(&pa, count))
				{
					int *pb = pa + count;
					scan_array(file, pa, pb);
					int *pc = NULL;
					int *pd = NULL;
					int sup_flag = key(pa, pb, &pc, &pd);
					count = pd - pc;
					if (sup_flag == -1 && !count && count == count_res)
					{
						ok_count++;
					}
					free(pa);
				}
				else
				{
					printf("Error\n");
				}
			}
			else
			{
				printf("Error\n");
			}
		}
	}
	// test3
	{
		//int res[] = {};
		int count_res = 0;
		FILE * file = fopen("in_3.txt", "r");
		if (!file)
		{
			printf("Error\n");
		}
		else
		{
			int count = 0;
			int rc = int_count_scan(file, &count);
			if (rc == -2 && !count && count == count_res)
			{
				ok_count++;
			}
			else
			{
				printf("Error\n");
			}
		}
	}
	// test4
	{
		int res[] =
		{
			-3, 0, 1, 2, 4
		};
		int count_res = 5;
		FILE * file = fopen("in_5.txt", "r");
		if (!file)
		{
			printf("Error\n");
		}
		else
		{
			int count = 0;
			int rc = int_count_scan(file, &count);
			if (!rc && count)
			{
				int *pa = NULL;
				if (!create_array_int(&pa, count))
				{
					int *pb = pa + count;
					scan_array(file, pa, pb);
					int *pc = NULL;
					int *pd = NULL;
					int sup_flag = key(pa, pb, &pc, &pd);
					free(pa);
					if (sup_flag == -1 || !(pd - pc))
					{
						printf("Error\n");
					}
					else
					{
						pa = pc;
						pb = pd;
						mysort(pa, pb - pa, sizeof(*pa), compare_int_and_ch);
						if (list_check(count_res, sizeof(int), pa, res))
						{
							ok_count++;
						}
						free(pa);
					}
				}
				else
				{
					printf("Error\n");
				}
			}
			else
			{
				printf("Error\n");
			}
		}
	}
	
	printf("%s: %s\n", name, (ok_count == 4) ? "OK" : "FEILED");
}

void check_sort(void)
{
	int ok_count = 0;
	// test1
	{
		int res[] =
		{
			1, 2, 3, 4, 5, 5, 6, 6, 7, 7
		};
		int count_res = 10;
		FILE * file = fopen("in_1.txt", "r");
		if (!file)
		{
			printf("Error\n");
		}
		else
		{
			int count = 0;
			int rc = int_count_scan(file, &count);
			if (!rc && count && count == count_res)
			{
				int *pa = NULL;
				if (!create_array_int(&pa, count))
				{
					int *pb = pa + count;
					scan_array(file, pa, pb);
					mysort(pa, pb - pa, sizeof(*pa), compare_int_and_ch);
					if (list_check(count, sizeof(int), pa, res))
					{
						ok_count++;
					}
					free(pa);
				}
				else
				{
					printf("Error\n");
				}
			}
			else
			{
				printf("Error\n");
			}
		}
	}
	// test2
	{
		int res[] =
		{
			-1
		};
		int count_res = 1;
		FILE * file = fopen("in_2.txt", "r");
		if (!file)
		{
			printf("Error\n");
		}
		else
		{
			int count = 0;
			int rc = int_count_scan(file, &count);
			if (!rc && count && count == count_res)
			{
				int *pa = NULL;
				if (!create_array_int(&pa, count))
				{
					int *pb = pa + count;
					scan_array(file, pa, pb);
					mysort(pa, pb - pa, sizeof(*pa), compare_int_and_ch);
					if (list_check(count, sizeof(int), pa, res))
					{
						ok_count++;
					}
					free(pa);
				}
				else
				{
					printf("Error\n");
				}
			}
			else
			{
				printf("Error\n");
			}
		}
	}
	//test3
	{
		//int res[] = {}
		int count_res = 0;
		FILE * file = fopen("in_3.txt", "r");
		if (!file)
		{
			printf("Error\n");
		}
		else
		{
			int count = 0;
			int rc = int_count_scan(file, &count);
			if (count == count_res && rc)
			{
				ok_count++;
			}
			else
			{
				printf("Error\n");
			}
		}
	}
	// test4
	{
		//int res[] = {};
		int count_res = 0;
		FILE * file = fopen("in_4.txt", "r");
		if (!file)
		{
			printf("Error\n");
		}
		else
		{
			int count = 0;
			int rc = int_count_scan(file, &count);
			if (count == count_res && rc)
			{
				ok_count++;
			}
			else
			{
				printf("Error\n");
			}
		}
	}
	// test5
	{
		int res[] =
		{
			-5, -3, 0, 1, 2, 4, 6
		};
		int count_res = 7;
		FILE * file = fopen("in_5.txt", "r");
		if (!file)
		{
			printf("Error\n");
		}
		else
		{
			int count = 0;
			int rc = int_count_scan(file, &count);
			if (!rc && count && count == count_res)
			{
				int *pa = NULL;
				if (!create_array_int(&pa, count))
				{
					int *pb = pa + count;
					scan_array(file, pa, pb);
					mysort(pa, pb - pa, sizeof(*pa), compare_int_and_ch);
					if (list_check(count, sizeof(int), pa, res))
					{
						ok_count++;
					}
					free(pa);
				}
				else
				{
					printf("Error\n");
				}
			}
			else
			{
				printf("Error\n");
			}
		}
	}
	// test6
	{
		int res[] =
		{
			1
		};
		int count_res = 1;
		FILE * file = fopen("in_7.txt", "r");
		if (!file)
		{
			printf("Error\n");
		}
		else
		{
			int count = 0;
			int rc = int_count_scan(file, &count);
			if (!rc && count && count == count_res)
			{
				int *pa = NULL;
				if (!create_array_int(&pa, count))
				{
					int *pb = pa + count;
					scan_array(file, pa, pb);
					mysort(pa, pb - pa, sizeof(*pa), compare_int_and_ch);
					if (list_check(count, sizeof(int), pa, res))
					{
						ok_count++;
					}
					free(pa);
				}
				else
				{
					printf("Error\n");
				}
			}
			else
			{
				printf("Error\n");
			}
		}
	}
	// test7
	{
		int res[] =
		{
			1, 2, 3, 4, 5, 6
		};
		int count_res = 6;
		FILE * file = fopen("in_8.txt", "r");
		if (!file)
		{
			printf("Error\n");
		}
		else
		{
			int count = 0;
			int rc = int_count_scan(file, &count);
			if (!rc && count && count == count_res)
			{
				int *pa = NULL;
				if (!create_array_int(&pa, count))
				{
					int *pb = pa + count;
					scan_array(file, pa, pb);
					mysort(pa, pb - pa, sizeof(*pa), compare_int_and_ch);
					if (list_check(count, sizeof(int), pa, res))
					{
						ok_count++;
					}
					free(pa);
				}
				else
				{
					printf("Error\n");
				}
			}
			else
			{
				printf("Error\n");
			}
		}
	}
	// test8
	{
		int res[] =
		{
			-1, 0, 1, 2, 3, 4, 5
		};
		int count_res = 7;
		FILE * file = fopen("in_9.txt", "r");
		if (!file)
		{
			printf("Error\n");
		}
		else
		{
			int count = 0;
			int rc = int_count_scan(file, &count);
			if (!rc && count && count == count_res)
			{
				int *pa = NULL;
				if (!create_array_int(&pa, count))
				{
					int *pb = pa + count;
					scan_array(file, pa, pb);
					mysort(pa, pb - pa, sizeof(*pa), compare_int_and_ch);
					if (list_check(count, sizeof(int), pa, res))
					{
						ok_count++;
					}
					free(pa);
				}
				else
				{
					printf("Error\n");
				}
			}
			else
			{
				printf("Error\n");
			}
		}
	}
	// test9
	{
		char res[] = "abcdef";
		int count = 6;
		char *pa = calloc(count, sizeof(char));
		char *pb = pa + count;
		*pa = 'c'; *(pa + 1) = 'f'; *(pa + 2) = 'e'; *(pa + 3) = 'd'; *(pa + 4) = 'a'; *(pa + 5) = 'b';
		mysort(pa, pb - pa, sizeof(*pa), compare_int_and_ch);
		if (list_check(count, sizeof(char), pa, res))
		{
			ok_count++;
		}
	}
	// test10
	{
		double res[] =
		{
			0.12, 0.24, 0.29, 0.38, 0.58, 0.68, 0.77, 0.83, 0.85, 0.90
		};
		int count = 10;
		double *pa = calloc(count, sizeof(double));
		if (!pa)
		{
			printf("Error\n");
		}
		else
		{
			double *pb = pa + count;
			*pa = 0.38; *(pa + 1) = 0.24; *(pa + 2) = 0.68; *(pa + 3) = 0.90; *(pa + 4) = 0.85;
			*(pa + 5) = 0.83;*(pa + 6) = 0.58; *(pa + 7) = 0.77; *(pa + 8) = 0.12; *(pa + 9) = 0.29;
			mysort(pa, pb - pa, sizeof(*pa), compare_double);
			if (list_check(count, sizeof(double), pa, res))
			{
				ok_count++;
			}
			free(pa);
		}
	}
	
	printf("%s: %s\n", name, (ok_count == 10) ? "OK" : "FAILED");
}