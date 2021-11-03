#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct _Node
{
    struct _Node *l;
    struct _Node *r;
    int id, val;
} Node;

Node *newNode()
{
    Node *newN = (Node *)malloc(sizeof(Node));
    newN->l = NULL;
    newN->r = NULL;
    newN->val = 0;
    return newN;
}
Node *newNode(int x)
{
    Node *newN = (Node *)malloc(sizeof(Node));
    newN->l = NULL;
    newN->r = NULL;
    newN->val = x;
    return newN;
}

void freeBST(Node *root)
{
    while (root)
    {
        free(root->l);
        root->l = NULL;
        free(root->r);
        root->r = NULL;
        free(root);
    }
}
int search(Node *root, int x)
{
    if (root == NULL)
    {
        return 0;
    }
    else if (root->val == x)
    {
        return root->val;
    }
    else if (x < root->val)
    {
        return search(root->l, x);
    }
    else if (x > root->val)
    {
        return search(root->r, x);
    }
}
Node *insert(Node *root, int x)
{
    if (!root)
    {
        return newNode(x);
    } // if the node is null
    if (x > root->val)
    {
        root->r = insert(root->r, x);
    }
    else
    {
        root->l = insert(root->l, x);
    }
    return root;
}
void Inorder(Node *root)
{
    if (!root)
    {
        return;
    }
    Inorder(root->l);
    printf("%d", root->val);
    Inorder(root->r);
}