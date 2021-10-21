#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Node
{
    struct _Node *prev, *next;
    int d;
} Node;
Node *new_node(int d)
{
    Node *res = (Node *)malloc(sizeof(Node));
    res->d = d;
    res->prev = res->next = NULL;
    return res;
}

void insert(Node **head, int v1, int v2)
{
    while (v2--)
    {
        Node *tmp = new_node(v1);
        tmp->next = (*head)->next;
        (*head)->next->prev = tmp;
        tmp->prev = (*head);
        (*head)->next = tmp;
    }
}
void erase(Node **head, int v)
{
    while (v--)
    {
        Node *tmp = (*head)->next;
        (*head)->next = tmp->next;
        tmp->next->prev = (*head);
        free(tmp);
    }
}
void move(Node **head, int v, int len)
{
    v %= len;
    int m = abs(v), dir = v / m;
    while (m--)
    {
        if (dir == 1)
            (*head) = (*head)->next;
        else
            (*head) = (*head)->prev;
    }
}
void show(Node **head)
{
    Node *now = (*head);
    do
    {
        printf("%d%c", now->d, " \n"[now->next == (*head)]);
        now = now->next;
    } while (now != (*head));
}

int main()
{
    int x, n, len;
    char op[20];
    scanf("%d", &x);
    Node *head = new_node(x);
    head->prev = head->next = head;
    len = 1;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%s", op);
        int t1, t2;
        if (!strcmp(op, "insert"))
            scanf("%d%d", &t1, &t2), insert(&head, t1, t2), len += t2;
        else if (!strcmp(op, "erase"))
            scanf("%d", &t1), erase(&head, t1), len -= t1;
        else if (!strcmp(op, "move"))
            scanf("%d", &t1), move(&head, t1, len);
        else
            show(&head);
    }
    return 0;
}