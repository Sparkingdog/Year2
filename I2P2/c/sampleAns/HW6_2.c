#define L left_child
#define R right_child

#include <stdlib.h>
typedef struct _NODE
{
    int level;
    struct _NODE *left_child, *right_child;
} Node;
Node *new_Node(int x)
{
    Node *res = (Node *)malloc(sizeof(Node));
    res->L = res->R = NULL;
    res->level = x;
    return res;
}

void build_tree(Node **now, int *arr, int l, int r)
{
    if (l > r)
        return;
    int mid = (l + r) / 2;
    (*now) = new_Node(arr[mid]);
    build_tree(&((*now)->L), arr, l, mid - 1);
    build_tree(&((*now)->R), arr, mid + 1, r);
}

int query_heatstroke(Node *now, int x)//search num in BST tree
{
    if (now == NULL)
        return 0;
    if (now->level > x)
        return query_heatstroke(now->L, x);
    else if (now->level < x)
        return query_heatstroke(now->R, x);
    else          // now->level == x
        return 1; // yay found~~
}
void eat_rat(Node **root, int x) // delete a node from a BST tree
{
    while ((*root) != NULL && (*root)->level != x)//found
    {
        if ((*root)->level > x)
            root = &((*root)->L);
        if ((*root)->level < x)
            root = &((*root)->R);
    }
    if ((*root) == NULL)//null
        return;
    if (!(*root)->L && !(*root)->R) // no leaf
    {
        free(*root);
        (*root) = NULL;
    }
    else if ((*root)->L && (*root)->R) // two leaf
    {
        Node **l = &((*root)->L);
        while ((*l)->R)//go to the right
            l = &((*l)->R);
        (*root)->level = (*l)->level;
        eat_rat(l, (*l)->level);
    }
    else // one leaf one null
    {
        Node *now = (*root)->L ? (*root)->L : (*root)->R;
        free(*root);
        (*root) = now;
    }
}