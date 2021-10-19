#include <stdio.h>
#include <stdlib.h>
#define in Inorder
#define pre Preorder
#define in_start inorder_start
#define in_end inorder_end
typedef struct _NODE
{
    int number;
    struct _NODE *ptr_to_right_node;
    struct _NODE *ptr_to_left_node;
} Node;
Node *newNode(int val)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->number = val;
    node->ptr_to_left_node = NULL;
    node->ptr_to_right_node = NULL;
}

int idxSearch(int arr[], int start, int end, int val)
{
    for (int i = start; i <= end; i++)
    {
        if (arr[i] == val)
            return i;
    }
    return -1;
}
Node *buildTree(int *Inorder, int *Preorder, int inorder_start, int inorder_end)
{
    // preorder:x 2 3 4 5 6 7 8 9
    // inorder:5 3 2 x 4 7 6 8 9
    //        i_s    p          i_e
    static int pre_idx = 0;
    Node *root = newNode(pre[pre_idx++]);
    if (in_start > in_end)
        return NULL; // false input

    int in_idx = idxSearch(in, in_start, in_end, root->number);

    if (in_start <= in_end) // found x main function
    {
        root->ptr_to_left_node = buildTree(in, pre, in_start, in_idx - 1);
        root->ptr_to_right_node = buildTree(in, pre, in_idx + 1, in_end);
    }
    return root;
}
void showPostorder(Node *root)
{
    if (root == NULL)
        return;
    showPostorder(root->ptr_to_left_node);
    showPostorder(root->ptr_to_right_node);
    printf("%d ", root->number);
}

void freeTree(Node *root)
{
    if (root != NULL)
    {
        freeTree(root->ptr_to_left_node);
        freeTree(root->ptr_to_right_node);
        free(root);
    }
}

int n;
int main(void)
{
    int id = 1;
    while (~scanf("%d", &n))
    {
        int inorder[100], preorder[100];
        for (int i = 0; i < n; i++)
            scanf("%d", &inorder[i]);
        for (int i = 0; i < n; i++)
            scanf("%d", &preorder[i]);
        Node *root = buildTree(inorder, preorder, 0, n - 1);
        printf("testcase%d: ", id++);
        showPostorder(root);
        printf("\n");
        freeTree(root);
    }
    return 0;
}