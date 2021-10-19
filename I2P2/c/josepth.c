#include <stdio.h>
#include <stdlib.h>

typedef struct _Node
{
    int id;
    struct _Node *next;
} Node;

Node *createList(int n)
{
    Node *head = (Node *)malloc(sizeof(Node));
    Node *cur = head;
    head->id = 1;
    head->next = head;
    for (int i = 2; i <= n; i++)
    {
        Node *newN = (Node *)malloc(sizeof(Node));
        newN->id = i;
        newN->next = head;
        cur->next = newN;
        cur = newN;
    }
    return head;
}

void freeList(Node *head)
{
    Node *cur = head;
    while (cur->next != head)
    {
        Node *tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    free(head);
}

int solveJoseph(Node **head, int step)
{
    int length = 1;
    Node *count = (*head)->next;
    while (count != *head) // count the length of circle every loop
        count = count->next, length++;
    while (*head != (*head)->next) // left 1 people
    {
        int k = (step % length - 2 + length) % length; // real step (speed up algorithm)
        while (k--)                                    // kill the people
        {
            *head = (*head)->next;
        }
        Node *tmp = (*head)->next;
        (*head)->next = (*head)->next->next;
        free(tmp);
        *head = (*head)->next; // start another loop
        length--;
    }
    return (*head)->id;
}

int main()
{
    int n, k;
    while (~scanf("%d%d", &n, &k))
    {
        Node *head = createList(n);
        printf("%d\n", solveJoseph(&head, k));
        freeList(head);
    }
}