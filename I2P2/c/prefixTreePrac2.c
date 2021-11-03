#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Tree
{
    char c;
    struct Tree *left, *right;
} Tree;

int isOperator(char c)
{
    if (c == "+" || c == "-" || c == "*" || c == "/")
        return 1;
    else
        return 0;
}
Tree *makeNode(char c)
{
    Tree *newN = (Tree *)malloc(sizeof(Tree));
    newN->c = c;
    newN->left = NULL;
    newN->right = NULL;
    return newN;
}
Tree *BuildTree(Tree *root, char *a) // given infix expression
{
    Tree *subroot;
    if (*a == '\0')
        return NULL;

    while (1)
    {
        if (root == NULL)
        {
            Tree *newN = makeNode(*a);
        }
        else
        {
            if (isalpha(*a))
            {
                root->c = *a;
            }
            subroot = BuildTree(root->left, a + 1);
            subroot = BuildTree(root->right, NULL);
            return subroot;
        }
    }
}

void inOrder(Tree *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%c", root->c);
        inOrder(root->right);
    }
}
void preOrder(Tree *root)
{
    if (root != NULL)
    {
        printf("%c", root->c);
        preOrder(root->left);
        preOrder(root->right);
    }
}
int main()
{
    Tree *root = NULL;
    char s[100];
    fgets(s, sizeof(s), stdin);
    BuildTree(root, s);
    printf("Inorder expression :\n");
    inOrder(root);
    printf("Preorder expression :\n");
    preOrder(root);
}