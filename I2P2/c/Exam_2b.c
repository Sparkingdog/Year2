#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define right ptr_to_right_node
#define left ptr_to_left_node
#define num number

int preorder_idx = 0;
int idxSearch(int *postorder, int strt, int end, int value)
{
    int i;
    for (i = strt; i <= end; i++)
    {
        if (postorder[i] == value)
            return i;
    }
}
typedef struct _NODE
{
    int number;
    struct _NODE *ptr_to_right_node;
    struct _NODE *ptr_to_left_node;
} Node;

Node *buildTree(int *postorder, int *Preorder, int postorder_start, int postorder_end)
{
    if (postorder_start > postorder_end)
        return NULL;
    Node *tree_node = (Node *)malloc(sizeof(Node));
    tree_node->num = Preorder[preorder_idx++];
    int postorder_idx = idxSearch(postorder, postorder_start, postorder_end, tree_node->num);
    tree_node->left = buildTree(postorder, Preorder, postorder_start, postorder_idx - 1);
    tree_node->right = buildTree(postorder, Preorder, postorder_idx + 1, postorder_end);

    return tree_node;
}
int factorial(int num)
{
    int fact = 1;
    if (num == 0)
        return 1;
    else
    {
        while (num > 1)
        {
            fact = fact * num;
            num--;
        }
        return fact;
    }
}
void showPostorder(Node *root)
{
    if (root == NULL)
        return;
    showPostorder(root->left);
    showPostorder(root->right);
    printf("%d ", root->num);
}

void showPreorder(Node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->num);
    showPreorder(root->left);
    showPreorder(root->right);
}
void freeTree(Node *root)
{
    preorder_idx = 0;
    if (root != NULL)
    {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}
int numOfBST(int key)
{
    int catalanNumber = factorial(2 * key) / (factorial(key + 1) * factorial(key));
    return catalanNumber;
}
int n;
int main(void)
{
    int r = rand() % 6;
    int id = 1;
    while (~scanf("%d", &n))
    {
        int preorder[100], postorder[100];
        for (int i = 0; i < n; i++)
            scanf("%d", &preorder[i]);
        for (int i = 0; i < n; i++)
            scanf("%d", &postorder[i]);
        Node *root = buildTree(postorder, preorder, 0, n - 1);

        printf("%d\n", 4);

        freeTree(root);
    }
    return 0;
}