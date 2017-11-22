#include <stdio.h>
#include "constant.h"

void print_errors(int rc)
{
	if (rc == ERROR_FILE)
	{
		printf("Error File\n");
	}
	else if (rc == ERROR_MEMORY)
	{
		printf("Error Memory\n");
	}
	else
	{
		printf("Unknown error\n");
	}
}