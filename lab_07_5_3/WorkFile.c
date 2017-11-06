#include "constant.h"
#include "WorkFile.h"

int int_count_scan(FILE *file, int *size)
{
	//int size = 0;
	int item;
	//int rc = 1;
	int rc = fscanf(file, "%d", &item);
	printf("rc = %d\n", *size);
	while (rc == 1)
	{
		rc = fscanf(file, "%d", &item);
		(*size)++;
	}
/*
	while (rc == 1)
	{
		printf("rc = %d\n", rc);
		rc = (fscanf(file, "%d", &item));
		*count += 1;
		//size++;
		*count += 1;
	}
	*/
	printf("rc = %d\n", *size);
	if (rc == -1)
	{
		return OK;
	}

	return ERROR_EMPTY_FILE;
}

void scan_array(FILE * file, int *pa, int *pb)
{
    int item;
    fseek(file, 0, SEEK_SET);
    while (pa < pb && fscanf(file, "%d", &item) == 1)
    {
        *pa = item;
        pa++;
    }
}

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
        fprintf(file, "%d", *pa);
        if ((pa - pb) != 1)
        {
            fprintf(file, " ");
        }
    }
}