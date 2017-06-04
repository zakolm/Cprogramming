#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#define OK 0
#define ERROR_INPUT -1
#define ERROR_EMPTY_FILE -3
#define ERROR_ZERO_DIVISION -4

int usage(void);
int dispartion(FILE*, int*, char**);
int middle_znach(FILE*, int*, int*);
int Sum_funct(FILE*, int, int, int*);
int pow_funct(int, int);

int main(int argc, char** argv)
{
    FILE *f;
    int max, rc = OK;

    if (argc != 2)
	{
        usage();
		return rc;
	}
	f = fopen(argv[1], "r");
    if (!f)
    {
        fprintf(stderr, "File %s not found! %s!\n", argv[1], strerror(errno));
        rc = ERROR_INPUT;
    }
	if (!rc)
		rc = dispartion(f, &max, argv);
    if (!rc)
        printf("dispartion is %d\n", max);
    else if (rc != ERROR_INPUT)
	{
		printf("%d", rc);
		if (rc == ERROR_EMPTY_FILE)
			printf("There are not enough data.\n");
		else
			printf("Error zero division.\n");
	}
    fclose(f);

    return rc;
}

int usage(void)
{
    printf("example.exe <name file>\n");
}

int dispartion(FILE* f, int *znach, char** argv)
{
    int count, middle_x, rc;
	rc = middle_znach(f, &middle_x, &count);
    if (rc)
	{
		if (rc == ERROR_EMPTY_FILE)
			return rc;
		else
			return rc;
	}
	rewind(f);
	rc = Sum_funct(f, middle_x, count, znach);
    if (rc)
	{
		if (rc == ERROR_EMPTY_FILE)
			return rc;
		else
			return rc;
	}
    return rc;
}

int middle_znach(FILE* f, int* znach, int* count)
{
    int sum = 0, x;
	if (fscanf(f, "%d", &sum) != 1)
		return ERROR_EMPTY_FILE;
	*count = 1;
    while (fscanf(f, "%d", &x) == 1)
    {
        sum += x;
        *count += 1;
    }
	if (!(*count))
	{
		printf("%d", *count);
		return ERROR_ZERO_DIVISION;
	}
    *znach = sum / *count;
	
	return OK;
}

int Sum_funct(FILE* f, int middle_x, int count, int* znach)
{
    int num, count_check;
	if (fscanf(f, "%d", &num) != 1)
		return ERROR_EMPTY_FILE;
	count_check = 1; 
	int sum = pow_funct((num - middle_x), 2);
	
    while (fscanf(f, "%d", &num) == 1)
	{
		count_check++;
        sum += pow_funct((num - middle_x), 2);
	}
	if (count_check == count)
	{
		if (count)
			*znach = sum/count;
		else
			return ERROR_ZERO_DIVISION;
	}
	return OK;
}

int pow_funct(int base, int n)
{
    int result = 1;
    for (int i = 0; i < n; ++i)
        result *= base;
    return result;
}