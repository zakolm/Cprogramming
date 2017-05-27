#include <stdio.h>
#define MAX 100
#define OK 0
#define ERROR_FOUND_FILE -1
#define ERROR_LEN_ARRAY -2
#define YES 1
#define NO 2

void usage(void);
int input_array(FILE*, int*, int*);
int process(int*, int);

int main(int argc, char** argv)
{
	int rc = OK;
	if (argc != 2)
		usage();
	else
	{
		FILE* f;
		f = fopen(argv[1], "r");
		if (!f)
		{
			printf("File '%s' not found!\n", argv[1]);
			rc = ERROR_FOUND_FILE;
		}
		if (!rc)
		{
			int len;
			int array[MAX];
			if(!input_array(f, array, &len))
			{
				printf("\n");
				if (process(array, len) == YES)
					printf("yes");
				else
					printf("no");
			}
			else
			{
				printf("Error in file!");
			}
		}
	}
	return rc;
}

void usage(void)
{
	printf("example.exe <name file>\n");
}

int input_array(FILE* f, int* pa, int* len)
{
	fscanf(f, "%d\n", len);
	if (*len > MAX || *len <= 0)
		return ERROR_LEN_ARRAY;
	int i, new_len = 0;
	
	i = 0;
	for (; (i < *len) && 
		fscanf(f, "%d", (pa+i)) == 1; ++i)
		new_len++;
	if(!new_len)
		return ERROR_LEN_ARRAY;
	
	*len = new_len;
	printf("%d\n", *len);
	i = 0;
	for (; (i < *len); ++i)
		printf("%d ", *(pa+i));
	return OK;
}

int process(int* pa, int len)
{
	int new_array[len];
	int i = 0;
	for (; i < len; ++i)
		new_array[i] = 0;
	int* pb = new_array;
	i = 0; *pb += 1;
	while(*(pb+i) < 2 && i < len)
	{
		i = *(pa+i);
		*(pb+i) += 1;
	}
	i = 0;
	for (; i < len; ++i)
		if (*(pb+i) == 0)
			return NO;
	return YES;
}