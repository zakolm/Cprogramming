#ifndef __CONSTANT__H__
#define __CONSTANT__H__

#define OK 0
#define ERROR_INPUT -1
#define ERROR_FILE -2
#define ERROR_ALLOCATE_MEMORY -3
#define ERROR_DETERMINANT -4

void print_error(int code)
{
    if (code == ERROR_INPUT)
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
}

#endif //__CONSTANT__H__
