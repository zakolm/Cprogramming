#include "resultex.h"

void result(int* pa, int* pb, long int* sum)
{
	long int squre = 1;
	for (; pa < pb; ++pa)
	{
		squre *= *pa;
		*sum += squre;
	}
}