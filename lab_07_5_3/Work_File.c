#include "CONSTANT.h"
#include "Work_File.h"

int int_count_scan(FILE * file, int *count)//, int filter)
{
	int item = 0;

	if ( fscanf(file, "%d", &item) != 1 )
	{
		return ERROR_EMPTY_FILE;
	}
	*count = 1;
	//int minus = 0;
	//if ( item < 0 && filter )
	//{
	//	minus = *count;
	//}
	 while ( fscanf(file, "%d", &item) == 1 )
	 {
		 *count += 1;
		 //if ( item < 0 && filter )
		 //{
		//	 minus = *count;
		 //}
	 }
	 //if ( minus )
	 //{
	//	 *count = minus;
	 //}
	 //else
	 //{
	//	 (*count)--;
	 //}

	return OK;
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
