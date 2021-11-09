#include <stdlib.h>
#include <stdio.h>

typedef struct _Node
{
    int data;
    struct _Node *l, *r;
} Node;
Node *newN(int x)
{
    Node *res = (Node *)malloc(sizeof(Node));
    res->r = res->r = NULL;
    res->data = x;
    return res;
}

void buildTree(Node **now, int *arr, int l, int r)
{
    if (l > r)
        return;
    int mid = (l + r) / 2;
    (*now) = newN(arr[mid]);
    buildTree(&((*now)->l), arr, l, mid - 1);
    buildTree(&((*now)->r), arr, mid + 1, r);
}

int searchNum(Node *now, int x)
{
    if (now == NULL)
        return;
    if (x > now->data)
        return searchNum(now->r, x);
    else if (x < now->data)
        return searchNum(now->l, x);
    else
        return x;
}

void killNode(Node **root, int x)
{
    while ((*root) != NULL && (*root)->data != x)
    {
        if (x < (*root)->data)
            root = &((*root)->l);
        if (x > (*root)->data)
            root = &((*root)->r);
    }
    if ((*root) == NULL)
        return;
    if (!(*root)->l && (*root)->r)
    {
        free(*root);
    }
    else if ((*root)->l && (*root)->r) // two leaf
    {
    }
    else
    {
        Node *now = (*root)->l ? (*root)->l : (*root)->r;
        free(*root);
        (*root) = now;
    }
}