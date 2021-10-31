#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXEXPR 256
char expr[MAXEXPR];
int pos;
typedef enum
{
    VAR_A,
    VAR_B,
    VAR_C,
    VAR_D,
    OP_AND,
    OP_OR,
    END
} TokenSet;
char sym[] = "ABCD&|()";
typedef struct _Node
{
    TokenSet data;
    struct _Node *left, *right;
} BTNode;
BTNode *EXPR();
BTNode *FACTOR();
/* create a node without any child.*/
BTNode *makeNode(char c)
{
    int i;
    BTNode *node = (BTNode *)malloc(sizeof(BTNode));
    for (i = 0; (unsigned int)i < strlen(sym); i++)
        if (c == sym[i])
            node->data = i;
    node->left = NULL;
    node->right = NULL;
    return node;
}
/* clean a tree.*/
void freeTree(BTNode *root)
{
    if (root != NULL)
    {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}
/* print a tree by pre-order. */
void printPrefix(BTNode *root)
{
    if (root != NULL)
    {
        printf("%c", sym[root->data]);
        printPrefix(root->left);
        printPrefix(root->right);
    }
}
/* FACTOR = VAR | (EXPR) */
BTNode *FACTOR()
{
    char c;
    BTNode *node = NULL;
    if (pos >= 0)
    {
        c = expr[pos--];
        if (c >= 'A' && c <= 'D')
        { // apply the rule FACTOR = VAR
            // make a new node for VAR
            ? ? ?
        }
        else if (c == ')')
        { // apply the rule FACTOR = (EXPR)
            // get the node pointer from recusive call of EXPR()
            ? ? ? if (expr[pos--] != '(')
            { // the left parenthesis is needed
                printf("Error: not matching parenthesis!\n");
                freeTree(node);
            }
        }
    }
    return node;
}
/* parse an infix expression and generate a syntax tree.
EXPR = FACTOR| EXPR OP FACTOR */
BTNode *EXPR()
{
    char c;
    BTNode *node = NULL, *right = NULL;
    if (pos >= 0)
    { // if the expression has length > 1.
        // get the pointer to the right child from calling the function
        FACTOR()
        right = ? ? ? if (pos > 0)
        {
            c = expr[pos];
            if (c == '&' || c == '|')
            { // apply the rule EXPR = EXPR OP FACTOR
                // make a new node for the OP
                node = ? ? ?
                           // set the node's right child as ...
                    node->right = ? ? ? pos--; // this step is important
                // set the node's left child from recursive call of EXPR()
                node->left = ? ? ?
            }
            else
                node = right; // apply the rule EXPR = FACTOR
        }
        else node = right; // apply the rule EXPR = FACTOR
    }
    return node;
}
int main(void)
{
    size_t len;
    fgets(expr, sizeof(expr), stdin);
    len = strlen(expr);
    if (len > 0 && expr[len - 1] == '\n')
    {
        --len;
        expr[len] = '\0';
    }
    pos = strlen(expr) - 1;
    BTNode *root = EXPR();
    printPrefix(root);
    freeTree(root);
    return 0;
}