#include "list.h"
#include "constant.h"

int main(int argv, char **argc)
{
    if (argv != 2)
    {
        printf("ERROR INPUT:\nInput app.exe name_file.txt");
        return ERROR_PARAMS;
    }

    FILE * file = fopen(argc[argv - 1], "r");
    if (!file)
    {
        printf("FILE ERROR\nNo such file or directory");
        return ERROR_FILE;
    }

    node_t *head;
    int rc = write_from_file(file, &head);
    if (rc == OK)
    {
        printf("First input:\n");
        print_elem(head);
        head = my_sort(head, cmp);
        printf("\n\n");
        printf("Sort by group:\n");
        print_elem(head);
        free_all(head);
    }
    else
    {
        print_errors(rc);
    }

    fclose(file);

    return rc;
}
