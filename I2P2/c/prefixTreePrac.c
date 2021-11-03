// C program to construct an expression tree
// from prefix expression
#include <stdio.h>
#include <stdlib.h>

// Represents a Node of the required tree
typedef struct Node
{
    char data;
    struct Node *left, *right;
} Node;

// Function to recursively build the expression tree
char *buildTree(Node **p, char *a)
{

    // If its the end of the expression
    if (*a == '\0')
        return '\0';

    while (1)
    {
        char *q = "null";
        if (*p == NULL)
        {

            // Create a Node with *a as the data and
            // both the children set to null
            Node *nn = (Node *)malloc(sizeof(Node));
            nn->data = *a;
            nn->left = NULL;
            nn->right = NULL;
            *p = nn;
        }
        else
        {

            // If the character is an operand
            if (*a >= 'a' && *a <= 'z')
            {
                return a;
            }

            // Build the left sub-tree
            q = buildTree(&(*p)->left, a + 1); // operand in left

            // Build the right sub-tree
            q = buildTree(&(*p)->right, q + 1); // null in right

            return q;
        }
    }
}

// Function to print the infix expression for the tree
void printInorder(Node *p) // recursion
{
    if (p == NULL)
    {
        return;
    }
    else
    {
        printInorder(p->left);
        printf("%c ", p->data);
        printInorder(p->right);
    }
}

// Function to print the postfix expression for the tree
void printPostorder(Node *p)
{
    if (p == NULL)
    {
        return;
    }
    else
    {
        printPostorder(p->left);
        printPostorder(p->right);
        printf("%c ", p->data);
    }
}

// Driver code
int main()
{
    Node *s = NULL;
    char a[] = "*+ab-cd";//prefix
    buildTree(&s, a);
    printf("The Infix expression is:\n ");
    printInorder(s);
    printf("\n");
    printf("The Postfix expression is:\n ");
    printPostorder(s);
    return 0;
}
