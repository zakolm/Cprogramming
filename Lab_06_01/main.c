#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "workarray.h"
#include "resultex.h"
#include "const.h"

void usage(void);

int main(int argc, char** argv)
{
    FILE *f;
    int rc = OK;
    if (argc != 2)
        usage();
    else
    {
        char** link_argv = argv;
        link_argv++;
        f = fopen(*link_argv, "r");
        int a[MAXLENGTH];
        //
        if (!f)
        {
            fprintf(stderr, "File %s not found! %s!\n", *link_argv, strerror(errno));
            fclose(f);
            rc = ERROR_FOUND_FILE;
        }
        //
		int* pa = a;
        input(f, &pa, &rc);
        fclose(f);
		printf("\n");
		switch(rc)
		{
			case OK:
			{
				long int res = 0;
				result(a, pa, &res);
				printf("result is %ld\n", res);
				break;
			}
			case MORE_ERROR_ELEMENTS:
				printf("More than 100 items!\n");
				break;
			default:
				printf("Empty array!\n");
		}
		array_print(a, pa);
    }
    return rc;
}

void usage(void)
{
    printf("example.exe <name file>\n");
}
