#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Node
{
    int data;
    struct _Node *next;
} Node;
Node *New_Node(int data)
{
    Node *tmp = (Node *)malloc(sizeof(Node));
    tmp->data = data;
    tmp->next = NULL;
    return tmp;
}

void insert(Node **head, int data, int n)
{
    while (n--)
    {
        Node *tmp = New_Node(data);
        tmp->next = (*head)->next;
        (*head)->next = tmp;
    }
}
void show(Node **head)
{
    Node *now = (*head);
    do
    {
        printf("%d->", now->data);
        now = now->next;
    } while (now != (*head));
}
void erase(Node **head, int n)
{
    while (n--)
    {
        Node *tmp = (*head)->next;
        (*head)->next = tmp->next;
        free(tmp);
    }
}
void move(Node **head, int n)
{
    while (n--)
    {
        (*head) = (*head)->next;
    }
}