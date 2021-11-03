#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
typedef struct _Node
{
    struct _Node *l, *r;
    int type; // 0:op,1:val,2:var
    char ch;  // opr or variable
    int val;  // val
} Node;

int getVal(Node *root) { return root->val; }
char getOp(Node *root) { return root->ch; }
void *getNext(char *c)
{
    while (isspace)
    {
        c++;
    }
}

bool isOp(char s) { return (s == '+' || s == '-' || s == '*' || s == '/'); }
bool isVal(char s) { return (isdigit(s)); }
bool isVar(char s) { return (isalpha(s)); }
void printInOrder(Node *root)
{
    while (root)
    {
        printInOrder(root->l);
        printf("%d", root->val);
        printInOrder(root->r);
    }
}
Node *buildTree(Node **root)
{
    *root = (Node *)malloc(sizeof(Node));
    char s[10000];
    scanf("%s", s);
    char *ptr = s;
    if (isOP(*ptr))
    {
        (*root)->type = 0;
        (*root)->ch = s;
        // build Tree recursively
        buildTree(&((*root)->l));
        buildTree(&((*root)->r));
    }
    else if (isVal(*ptr))
    {
        (*root)->type = 1;
        (*root)->val = atoi(*ptr);
        (*root)->l = (*root)->r = NULL;
    }
    else if (isVar(*ptr))
    {
        (*root)->type = 2;
        (*root)->ch = *ptr;
        (*root)->l = (*root)->r = NULL;
    }
    getNext(ptr);
    return;
}
int callByOp(int l, int r, char op) // + - * /
{
    switch (op)
    {
    case '+':
        return l + r;
        break;
    case '-':
        return l - r;
        break;
    case '*':
        return l * r;
        break;
    case '/':
        return l / r;
        break;
    default:
        return -1;
        break;
    }
}
int calculate(Node *root)
{
    switch (root->type)
    {
    case 0: // operator
        int left = calculate(root->l);
        int right = calculate(root->r);
        return callByOp(left, right, root->ch);
        break;
    case 1: // value
        return root->val;
        break;
    case 2: // variables
        return getVal(root->ch);
        break;
    default:
        break;
    }
}
int main()
{
    Node *tree = NULL;
    int ar[3];
    int var[3];
    scanf("%d%d%d", &ar[0], &ar[1], &ar[2]);
    printf("\n%d\n", calculate(tree));
}
