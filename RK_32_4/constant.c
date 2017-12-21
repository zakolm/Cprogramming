#include "constant.h"

void print_errors(int error)
{
    if (error == ERROR_FILE)
    {
        printf("ERROR FILE!\n");
    }
    else if (error == ERROR_MEMORY)
    {
        printf("ERROR MEMORY!\n");
    }
    else
    {
        printf("Unknown error!\n");
    }
}
