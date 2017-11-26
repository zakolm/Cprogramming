#include <stdio.h>

#include "constant.h"

/*
* 
* code - 
*/
void print_error(int code)
{
    if (code == ERROR_PARAM)
    {
        printf("Input/output error\n");
        printf("Run program this way: ");
        printf("./example.exe action <name file1> [name file2] <name_res file>\n");
    }
    else if (code == ERROR_FILE)
    {
        printf("No such file or directory");
    }
    else if (code == ERROR_ALLOCATE_MEMORY)
    {
        printf("Cannot allocate memory\n");
    }
    else if (code == ERROR_DETERMINANT)
    {
        printf("Cannot find determinant\n");
    }
	else if (code != OK)
	{
		printf("Unknown error\n");
	}
}