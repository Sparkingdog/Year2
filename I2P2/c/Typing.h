#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Typing.h>
#define next ptr_to_next_node
#define prev ptr_to_prev_node

typedef struct _NODE
{
    char character;
    struct _NODE *ptr_to_next_node;
    struct _NODE *ptr_to_prev_node;
} Node;

Node *head, *tail, *cursor;
int num, n;
char buf[200], intype[200];

void show()
{
    if (head == NULL)
    {
        printf("\n");
        return;
    }
    Node *now = head->ptr_to_next_node;
    while (now != head)
    {
        printf("%c ", now->character);
        now = now->ptr_to_next_node;
    }
    printf("\n");
}

void insert(Node **cur, char c)
{

}

void deletion(Node **cur)
{

}

void backspace(Node **cur)
{
}

void go_left(Node **cur, int t)
{
    while(t--)
    {
        (*cur)=(*cur)->ptr_to_prev_node;
    }
}

void go_right(Node **cur, int t)
{
        while(t--)
    {
        (*cur)=(*cur)->ptr_to_next_node;
    }
}

void go_home(Node **cur)
{
    (*cur)=head;
}

void go_end(Node **cur)
{
    (*cur)=tail;
}
