#define right ptr_to_right_node
#define left ptr_to_left_node
#define num number
int preorder_idx = 0;
int idxSearch(int *inorder, int strt, int end, int value)
{
    int i;
    for (i = strt; i <= end; i++)
    {
        if (inorder[i] == value)
            return i;
    }
}
typedef struct _NODE
{
    int number;
    struct _NODE *ptr_to_right_node;
    struct _NODE *ptr_to_left_node;
} Node;

Node *buildTree(int *Inorder, int *Preorder, int inorder_start, int inorder_end)
{
    if (inorder_start > inorder_end)
        return NULL;
    Node *tree_node = (Node *)malloc(sizeof(Node));
    tree_node->num = Preorder[preorder_idx++];
    int inorder_idx = idxSearch(Inorder, inorder_start, inorder_end, tree_node->num);
    tree_node->left = buildTree(Inorder, Preorder, inorder_start, inorder_idx - 1);
    tree_node->right = buildTree(Inorder, Preorder, inorder_idx + 1, inorder_end);

    return tree_node;
}
void showPostorder(Node *root)
{
    if (root == NULL)
        return;
    showPostorder(root->left);
    showPostorder(root->right);
    printf("%d ", root->num);
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