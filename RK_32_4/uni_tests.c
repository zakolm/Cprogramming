#include "list.h"
#include "constant.h"

//#define name __func__

void check_write_from_file(void);
void check_add_front(void);

int main(void)
{
    check_write_from_file();
    check_add_front();
    return OK;
}

void check_write_from_file(void)
{
    int ok_count = 0;
    int number_test = 0;

    //test 1
    {
        number_test++;
        char students[][MAX_NAME] = {"Pupkin", "Dymov", "Sidorov", "Petrov", "Ivanov"};
        char groups[][MAX_GROUP] = {"iu7-22", "iu7-23", "iu7-21",  "iu7-22", "iu7-21"};
        FILE * file = fopen("in_1.txt", "r");
        node_t *head = NULL;
        int rc = write_from_file(file, &head);
        int flag = 1;
        if (rc == OK)
        {
            node_t *head_tmp = head;
            for (int i = 0; i < 5; ++i)
            {
                if (strcmp(head_tmp->name, students[i]) || strcmp(head_tmp->group, groups[i]))
                {
                    printf("%s %s %s %s\n",head_tmp->name, students[i], head_tmp->group, groups[i]);
                    flag = 0;
                    break;
                }
                head_tmp = head_tmp->next;
            }
            if (flag)
                ok_count++;
        }
        if (!flag || rc != OK)
        {
            printf("test: %d write_from_file FAILD", number_test);
        }
        free_all(head);
        fclose(file);
    }

    //test 2
    {
        number_test++;
        int res = ERROR_FILE;
        FILE * file = fopen("in_2.txt", "r");
         node_t *head = NULL;
        int rc = write_from_file(file, &head);
        if (rc == res)
        {
            ok_count++;
        }
        else
        {
            printf("test: %d write_from_file FAILD", number_test);
        }
        fclose(file);
    }

    //result
    printf("check_write_from_file is %s", (ok_count == number_test) ? "OK" : "FAILD");
}

void check_add_front(void)
{
    int ok_count = 0;
    int number_test = 0;

    //test 1
    {
        number_test++;
        char res[][MAX_NAME] = {"Pupkin", "Dymov"};
        char groups[][MAX_GROUP] = {"iu7-22", "iu7-23"};
        node_t *tmp = create_elem(res[0], groups[0]);
        node_t *head = add_front(head, tmp);
        tmp = create_elem(res[1], groups[1]);
        head = add_front(head, tmp);
        int flag = 1;
        for (int i = 0; i < 2; ++i)
        {
            if (strcmp(head->name, res[i]) || strcmp(head->group, groups[i]))
            {
                //printf("%s %s %s %s\n",head_tmp->name, students[i], head_tmp->group, groups[i]);
                flag = 0;
                break;
            }
            head = head->next;
        }
        if (flag)
            ok_count++;
        else
            printf("test: %d add_front FAILD", number_test);
    }

     printf("check_write_from_file is %s", (ok_count == number_test) ? "OK" : "FAILD");
}
