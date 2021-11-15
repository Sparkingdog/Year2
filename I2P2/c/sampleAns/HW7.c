//Construct tree by inorder and postorder
#include <stdio.h>
#include <stdlib.h>

typedef struct _NODE
{
    int number;
    struct _NODE *ptr_to_right_node;
    struct _NODE *ptr_to_left_node;
} Node;

int findIndex(int *inorder, int start, int end, int val)
{
    for (int i = start; i <= end; i++)
    {
        if (inorder[i] == val)
            return i;
    }
    return -1;
}

Node *newNode(int num)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->number = num;
    node->ptr_to_left_node = node->ptr_to_right_node = NULL;
    return node;
}

Node *buildTree(int *inorder, int *postorder, int start, int end, int *pre_idx)
{
    if (start > end)
        return NULL;
    Node *self = newNode(postorder[*pre_idx]);
    (*pre_idx)--;
    int index = findIndex(inorder, start, end, self->number);
    self->ptr_to_right_node = buildTree(inorder, postorder, index + 1, end, pre_idx);
    self->ptr_to_left_node = buildTree(inorder, postorder, start, index - 1, pre_idx);
    return self;
}

void showPreorder(Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->number);
        showPreorder(root->ptr_to_left_node);
        showPreorder(root->ptr_to_right_node);
    }
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
        int pre_idx = n - 1;
        int inorder[100], postorder[100];
        for (int i = 0; i < n; i++)
            scanf("%d", &inorder[i]);
        for (int i = 0; i < n; i++)
            scanf("%d", &postorder[i]);
        Node *root = buildTree(inorder, postorder, 0, n - 1, &pre_idx);
        printf("testcase%d: ", id++);
        showPreorder(root);
        printf("\n");
        freeTree(root);
    }
    return 0;
}

//Thanos' Dilemma
#include <stdio.h>
#include <string.h>

#define ll long long
#define MOD 1000000007

typedef struct _MAT
{
    ll d[3][3];
} Mat;

Mat I2;
void init() { I2.d[0][0] = 13, I2.d[1][0] = 12, I2.d[2][0] = 1; }

Mat mul(Mat A, Mat B)
{
    Mat res;
    memset(res.d, 0, sizeof(res));
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 3; k++)
                res.d[i][k] = (res.d[i][k] + A.d[i][j] * B.d[j][k]) % MOD;
    return res;
}

Mat fpw(Mat x, ll y)
{
    Mat res = I2;
    y = y - 3;
    for (; y; y /= 2, x = mul(x, x))
        if (y & 1)
            res = mul(x, res);
    return res;
}

int main(void)
{

    init();
    int t;
    scanf("%d", &t);
    Mat mat;
    mat.d[0][0] = mat.d[0][2] = mat.d[1][0] = mat.d[2][1] = 1;
    mat.d[1][1] = mat.d[1][2] = mat.d[2][0] = mat.d[2][2] = 0;
    mat.d[0][1] = 2;
    while (t--)
    {
        ll x;
        scanf("%lld", &x);
        if (x == 1)
            printf("%d\n", 1);
        else if (x == 2)
            printf("%d\n", 12);
        else if (x == 3)
            printf("%d\n", 13);
        else
        {
            Mat ans = fpw(mat, x);
            printf("%lld\n", ans.d[0][0]);
        }
    }
    return 0;
}

//Go Down Chicken
#include <stdio.h>
#include <stdlib.h>
#define MOD 1000000007
#define ll long long

typedef struct _Node
{
    ll ways;
    ll round;
} Id;

ll fpw(ll x, ll y)
{
    ll res = 1 % MOD;
    for (; y; y /= 2, x = ((x % MOD) * (x % MOD)) % MOD)
        if (y & 1)
            res = ((res % MOD) * (x % MOD)) % MOD;
    return res;
}

int cmpfunc(const void *a, const void *b)
{
    return (((Id *)a)->ways - ((Id *)b)->ways);
}

ll BST(Id game[], int start, int end, int val)
{
    int ans = 0;
    while (start < end)
    {
        int mid = (start + end) / 2;
        if (game[mid].ways >= val)
        {
            ans = mid;
            end = mid;
        }
        else
        {
            start = mid + 1;
        }
    }

    if (game[ans].ways == val)
        return game[ans].round;
    else
        return 0;
}

int main(void)
{

    int n, q;
    while (scanf("%d%d", &n, &q) != EOF)
    {
        Id game[n];
        ll num;
        for (int i = 0; i < n; i++)
        {
            scanf("%lld(/`A`)/ ~I__I", &num);
            if (num % 2 == 0)
            {
                game[i].ways = fpw(2, num >> 1);
                game[i].round = i + 1;
            }
            else
            {
                game[i].ways = 0;
                game[i].round = i + 1;
            }
        }

        qsort(game, n, sizeof(Id), cmpfunc);

        while (q--)
        {
            int x;
            scanf("%d", &x);
            if (BST(game, 0, n, x))
                printf("%lld\n", BST(game, 0, n, x));
            else
                printf("Go Down Chicken 404\n");
        }
    }
    return 0;
}

//too many treasures
#include <stdio.h>

int main(void)
{

    int n, q;
    scanf("%d%d", &n, &q);

    long long prefix[n + 1];
    long long val = 0;
    prefix[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        long long treasure;
        scanf("%lld", &treasure);

        if (treasure > 0)
        {
            val = val + treasure;
            prefix[i] = val;
        }
        else
        {
            val = val + 0;
            prefix[i] = val;
        }
    }
    int l, r, m;
    while (q--)
    {
        scanf("%d%d%d", &l, &r, &m);
        long long ans = prefix[l + m - 1] - prefix[l - 1];
        printf("%lld\n", ans);
    }

    return 0;
}
