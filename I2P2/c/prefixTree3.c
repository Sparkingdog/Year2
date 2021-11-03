#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXEXPR 256
char expr[MAXEXPR];
int pos;
typedef enum
{
    VAR_A,  // 0
    VAR_B,  // 1
    VAR_C,  // 2
    VAR_D,  // 3
    OP_AND, // 4
    OP_OR,  // 5
    END     // 6
} TokenSet;
char sym[] = "ABCD&|()"; // 0,1,2,3,4,5,6
typedef struct _Node
{
    TokenSet data;
    struct _Node *left, *right;
} BTNode;
BTNode *EXPR();
BTNode *FACTOR();
/* create a node without any child.*/
BTNode *makeNode(char c) // make a leaf node
{
    int i;
    BTNode *node = (BTNode *)malloc(sizeof(BTNode));
    for (i = 0; (unsigned int)i < strlen(sym); i++) // search for token set
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
/* parsing expr = factor | expr op FACTOR
1.  Find a factor from the end of expression
2.  If there is an OP in front of the FACTOR
2.1 Let factor be OP's right child
2.2 Parse the remaining expression recursively and make it OP's left child
 */
BTNode *FACTOR() // Alphabet or parenthesis
{
    char c;
    BTNode *node = NULL;
    if (pos >= 0)
    {
        c = expr[pos--];
        if (c >= 'A' && c <= 'D')
        { // apply the rule FACTOR = VAR
          // make a new node for VAR
            node = makeNode(c);
        }
        else if (c == ')')
        { // apply the rule FACTOR = (EXPR)
            // get the node pointer from recusive call of EXPR()
            node = EXPR();
            if (expr[pos--] != '(')
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
// rules
BTNode *EXPR()
{
    char c;
    BTNode *node = NULL, *right = NULL;
    if (pos >= 0)
    { // if the expression has length > 1.
        // get the pointer to the right child from calling the function FACTOR()
        right = FACTOR();
        if (pos > 0)
        {
            c = expr[pos];
            if (c == '&' || c == '|')
            { // apply the rule EXPR = EXPR OP FACTOR
                // make a new node for the OP
                node = makeNode(c);
                // set the node's right child as ...
                node->right = right;
                pos--; // this step is important
                // set the node's left child from recursive call of EXPR()
                node->left = EXPR();
            }
            else
                node = right; // apply the rule EXPR = FACTOR
        }
        else
            node = right; // apply the rule EXPR = FACTOR
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
    pos = strlen(expr) - 1; // start from right to left
    BTNode *root = EXPR();  // build syntax tree
    printPrefix(root);      // print tree
    freeTree(root);         // free tree
    return 0;
}
// A&(B|C) infix to prefix
// give infix build syntax tree