#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define Max_N 103

enum
{
    val,
    id,
    op
};
typedef struct _Node
{
    struct _Node *l, *r;
    int type;
    int val;
    char op_id;
} Node;

Node *newN(int type, int val, char op_id)
{
    Node *res = (Node *)malloc(sizeof(Node));
    res->l = res->r = NULL;
    res->type = type;
    res->val = val;
    res->op_id = op_id;
    return res;
}
char in[Max_N];
int ids[3]; // xyz
Node *buildTree()
{
    scanf("%s", in);
    Node *now;
    if (isdigit(in[0]))
        now = newN(val, atoi(in), '\0');
    else if (isalpha(in[0]))
        now = newN(id, 0, in[0]);
    else
        now = newN(op, 0, in[0]);
    if (now->type != op)
        return now;
    now->l = buildTree();
    now->r = buildTree();
    return now;
}
void inOrder(Node *root)
{
    int l,r;
    switch (root->type)
    {
        case val:
        printf("%d",root->val);
        case id:
        printf("%c",root->op_id);
        return ids[root->op_id-'x'];
    }
}

int main()
{
    Node *root = buildTree();
    scanf("%d%d%d", &ids[0], &ids[1], &ids[2]);
    printf("\n%d\n", inOrder(root));
}