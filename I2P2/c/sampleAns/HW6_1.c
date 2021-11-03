#include <stdio.h>
#include <stdlib.h>
#define MAX_N 103

enum {VAL, ID, OP};
typedef struct _Node
{
    struct _Node *l, *r;
    int type;
    int val;
    char op_id;
} Node;
Node *new_Node(int type, int val, char op_id)
{
    Node *res = (Node*)malloc(sizeof(Node));
    res->l = res->r = NULL;
    res->type = type;
    res->val = val;
    res->op_id = op_id;
    return res;
}
char in[MAX_N];
int ids[3];

Node *build_tree()
{
    scanf("%s", in);
    Node *now;
    if('0'<=in[0] && in[0]<='9') now = new_Node(VAL, atoi(in), '\0');
    else if('x'<=in[0] && in[0]<='z') now = new_Node(ID, 0, in[0]);
    else now = new_Node(OP, 0, in[0]);
    if(now->type != OP) return now;
    now->l = build_tree();
    now->r = build_tree();
    return now;
}
int show_inorder(Node *now)
{
    int l, r;
    switch(now->type)
    {
        case VAL:
            printf("%d", now->val);
            return now->val;
        case ID:
            printf("%c", now->op_id);
            return ids[now->op_id-'x'];
        case OP:
            l = show_inorder(now->l);
            printf("%c", now->op_id);
            r = show_inorder(now->r);
            switch(now->op_id)
            {
                case '+': return l + r;
                case '-': return l - r;
                case '*': return l * r;
                case '/': return l / r;
                default: exit(1);
            }
        default: exit(1);
    }
}

int main()
{
    Node *root = build_tree();
    scanf("%d%d%d", &ids[0], &ids[1], &ids[2]);
    printf("\n%d\n", show_inorder(root));
    return 0;
}