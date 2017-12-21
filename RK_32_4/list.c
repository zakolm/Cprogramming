#include "list.h"
#include "constant.h"

node_t *create_elem(char *name, char *group)
{
    node_t *element = malloc(sizeof(*element));
    if (element)
    {
        element->name = name;
        element->group = group;
        element->next = NULL;
    }

    return element;
}

void free_all(node_t *head)
{
    node_t *cur = head;
    for (; head; head = cur)
    {
        cur = head->next;
        free(head->name);
        free(head->group);
        free(head);
    }
}

node_t *add_front(node_t *head, node_t *new_head)
{
    new_head->next = head;
    return new_head;
}

int cmp(node_t *a, node_t *b)
{
    return strcmp(a->group, b->group);
}

node_t *my_sort(node_t *head, int(*cmp)(node_t*, node_t*))
{
    if (head)
    {
        node_t *res = head;
        head = head->next;
        res->next = NULL;
        while (head)
        {
            node_t *element = head;
            head = head->next;
            if (cmp(element, res) < 0)
            {
                element->next = res;
                res = element;
            }
            else
            {
                node_t *p = res;
                while (p->next)
                {
                    if (cmp(p->next, element) > 0)
                        break;
                    p = p->next;
                }
                element->next = p->next;
                p->next = element;
            }
        }
        head = res;
    }

    return head;
}

void print_elem(node_t *head)
{
    for (; head; head = head->next)
    {
        printf("%s %s\n", head->name, head->group);
    }
}


int write_from_file(FILE *file, node_t **head)
{
    int rc;
    node_t *head_tmp = NULL;
    while(!feof(file))
    {
        char *name = calloc(MAX_NAME, sizeof(*name));
        char *group = calloc(MAX_GROUP, sizeof(*group));
        if (!name || !group)
        {
            free_all(head_tmp);
            return ERROR_MEMORY;
        }
        if ((rc = fscanf(file, "%s %s", name, group)) != 2)
        {
            free(name);
            free(group);
            if (rc == EOF && head_tmp != NULL)
            {
                break;
            }
            else
            {
                free_all(head_tmp);
                return ERROR_FILE;
            }
        }
        node_t *tmp = create_elem(name, group);
        if (!tmp)
        {
            free(name);
            free(group);
            free_all(head_tmp);
            return ERROR_MEMORY;
        }
        head_tmp = add_front(head_tmp, tmp);
    }
    *head = head_tmp;

    return OK;
}
