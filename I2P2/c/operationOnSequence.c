#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "operationOnSequence.h"

//declare var
int x, n;
int t1, t2;
char buf[20];
Node *head;

int main()
{
    scanf("%d", &x);
    head = New_Node(x);
    head->next = head;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%s", buf);
        if (!strcmp(buf, "insert"))
        {
            scanf("%d%d", &t1, &t2);
            insert(&head, t1, t2);
        }
        else if (!strcmp(buf, "erase"))
        {
            scanf("%d", &t1);
            erase(&head, t1);
        }
        else if (!strcmp(buf, "show"))
        {
            show(&head);
            printf("\n");
        }
        else if (!strcmp(buf, "move"))//not working
        {
            scanf("%d", &t1);
            move(&head, t1);
        }
    }
}