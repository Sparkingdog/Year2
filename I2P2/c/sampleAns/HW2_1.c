#include <stdlib.h>
#include <string.h>

void insert(Node **head, char *color, int dest)
{
    Node *now = (*head), *tmp;
    for (int id = 0; now->next != NULL && id != dest; now = now->next, id++)
        ;
    tmp = now->next;
    now->next = (Node *)malloc(sizeof(Node));
    strcpy(now->next->color, color);
    now->next->next = tmp;
}

void erase1(Node **head, int dest)
{
    Node *now = (*head), *prev = NULL;
    for (int id = 0; now->next != NULL && id != dest; prev = now, now = now->next, id++)
        ;
    if (prev == NULL)
        return;
    prev->next = now->next;
    free(now);
}

void erase2(Node **head, char *color)
{
    Node *now = (*head), *prev = NULL;
    while (now != NULL)
    {
        if (!strcmp(now->color, color))
        {
            prev->next = now->next;
            free(now);
            now = prev;
        }
        prev = now;
        now = now->next;
    }
}

void reverse(Node **head, int dest1, int dest2)
{
    Node *now = (*head), *l = NULL, *tmp = NULL;
    int id;
    for (id = 0; now->next != NULL && id != dest1; l = now, now = now->next, id++)
        ;
    while (now->next != NULL && id < dest2)
    {
        tmp = now->next;
        now->next = tmp->next;
        tmp->next = l->next;
        l->next = tmp;
        id++;
    }
}