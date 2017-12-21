#ifndef LIST_H
#define LIST_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node node_t;
struct node
{
    char *name;
    char *group;
    node_t *next;
};

node_t *create_elem(char *name, char *group);
void free_all(node_t *head);
node_t *add_front(node_t *head, node_t *new_head);//test
node_t *my_sort(node_t *head, int(*cmp)(node_t*, node_t*));//test
void print_elem(node_t *head);//- test
int cmp(node_t *a, node_t *b);//- test
int write_from_file(FILE *file, node_t **head);//test

#endif //LIST_H
