#include <bits/stdc++.h>
#include <string>
#define MAX 1000
using namespace std;

typedef struct node
{
    int data;
    struct node *l;
    struct node *r;
    bool build;
} Node;
typedef class charStack
{
    char top;

public:
    char a[MAX]; // Maximum size of charStack

    charStack() { top = -1; }
    bool push(char x);
    char pop();
    char peek();
    bool isEmpty();
} charStack;

bool charStack::push(char x)
{
    if (top >= (MAX - 1))
    {
        cout << "charStack Overflow";
        return false;
    }
    else
    {
        a[++top] = x;
        return true;
    }
}

char charStack::pop()
{
    if (top < 0)
    {
        cout << "charStack Underflow";
        return 0;
    }
    else
    {
        char x = a[top--];
        return x;
    }
}
char charStack::peek() // return the top value
{
    if (top < 0)
    {
        cout << "charStack is Empty";
        return 0;
    }
    else
    {
        char x = a[top];
        return x;
    }
}

bool charStack::isEmpty()
{
    return (top < 0);
}
class f
{
public:
    int getMaxPathSum = 0;
    int getWeightSum = 0;
    int tower = 0;
    int sumUnited = 0;
    Node *newN(int x)
    {
        Node *n = new Node();
        n->l = n->r = NULL;
        n->data = x;
        return n;
    }
    bool fold(Node *node1, Node *node2)
    {
        if (node1 == NULL && node2 == NULL)
            return true;
        if (node1 == NULL || node2 == NULL)
            return false;
        return fold(node1->l, node2->r) && fold(node1->r, node2->l);
    }
    bool Foldable(Node *node)
    {
        if (node == NULL)
            return true;
        return fold(node->l, node->r);
    }

    void inorder(Node *root)
    {
        if (root == NULL)
            return;
        inorder(root->l);
        cout << root->data << " ";
        inorder(root->r);
    }
    void preorder(Node *root)
    {
        if (root == NULL)
            return;
        cout << root->data << " ";
        preorder(root->l);
        preorder(root->r);
    }
    void postorder(Node *root)
    {
        if (root == NULL)
            return;
        postorder(root->l);
        postorder(root->r);
        cout << root->data << " ";
    }
    void Traverse(Node *root)
    {
        preorder(root);
        cout << endl;
        inorder(root);
        cout << endl;
        postorder(root);
        cout << endl;
    }
    void WeightSum(Node *root)
    {
        if (root == NULL)
            return;
        getWeightSum += root->data;
        WeightSum(root->l);
        WeightSum(root->r);
        return;
    }
    void DeleteLeaf(Node **root)
    {
        if ((*root) == NULL)
            return;
        if ((*root)->l == NULL && (*root)->r == NULL)
        {
            free(*root);
            return;
        }
        DeleteLeaf(&(*root)->l);
        DeleteLeaf(&(*root)->r);
        return;
    }
    Node *RemoveLeaves(Node *root)
    {
        if (root != NULL)
        {
            if (root->l == NULL && root->r == NULL)
            {
                free(root);
                return NULL;
            }
            else
            {
                root->l = RemoveLeaves(root->l);
                root->r = RemoveLeaves(root->r);
            }
        }
        return root;
    }

    int findIndex(string str, int si, int ei)
    {
        if (si > ei)
            return -1;

        charStack s;

        for (int i = si; i <= ei; i++)
        {

            if (str[i] == '(')
                s.push(str[i]);

            else if (str[i] == ')')
            {
                if (s.peek() == '(')
                {
                    s.pop();

                    if (s.isEmpty())
                        return i;
                }
            }
        }

        return -1;
    }

    Node *treeFromString(string str, int si, int ei)
    {
        if (si > ei)
            return NULL;

        Node *root = newN(str[si] - '0');
        int index = -1;

        if (si + 1 <= ei && str[si + 1] == '(')
            index = findIndex(str, si + 1, ei);

        if (index != -1)
        {

            root->l = treeFromString(str, si + 2, index - 1);

            root->r = treeFromString(str, index + 2, ei - 1);
        }
        return root;
    }
    void Invert(Node *root)
    {
        if (root == NULL)
            return;
        swap(root->l, root->r);
        Invert(root->l);
        Invert(root->r);
    }
    bool isLeaf(Node *now)
    {
        return (now->l == NULL && now->r == NULL);
    }
    void BinaryTower(Node *root)
    {
        //! best solution place on the node that have two child
        if (root == NULL)
            return;
        BinaryTower(root->l);
        BinaryTower(root->r);
        if ((root->l || root->r) && ((root->l->build == false) && (root->r->build == false)) && (root->build == false)) //! visited and not placed
        {
            root->build = true;
        }
        return;
    }
    void countTower(Node *root)
    {
        if (root == NULL)
            return;
        if (root->build)
        {
            tower++;
        }
        countTower(root->l);
        countTower(root->r);
    }

    void MaximumPathSum(Node *root, int sum)
    {
        if (root == NULL)
            return;

        if (root->l == NULL && root->r == NULL) // is leaf node
        {
            if (sum + root->data > getMaxPathSum)
            {
                getMaxPathSum = sum + root->data;
                return;
            }
        }
        MaximumPathSum(root->l, sum + root->data);
        MaximumPathSum(root->r, sum + root->data);
    }
    void KingdomUnitedPath(Node *root, int sum)
    {
        if (root == NULL)
            return;
        if (sum > sumUnited)
        {
            sumUnited = sum;
        }
        if (root->l || root->r)
        {
            if (root->data == root->l->data) //! can be KingdomUnitedPath
            {
                KingdomUnitedPath(root->l, sum += 1);
            }
            if (root->data == root->r->data) //! can be KingdomUnitedPath
            {
                KingdomUnitedPath(root->r, sum += 1);
            }
            KingdomUnitedPath(root->l, 0);
            KingdomUnitedPath(root->r, 0);
        }
    }
    int length(Node *node, int *ans)
    {
        if (node == NULL)
            return 0;

        // Recursive calls to check for subtrees
        int left = length(node->l, ans);
        int right = length(node->r, ans);

        // Variables to store maximum lengths in two directions
        int Leftmax = 0, Rightmax = 0;

        // If curr node and it's left child has same value
        if (node->l && node->l->data == node->data)
            Leftmax += left + 1;

        // If curr node and it's right child has same value
        if (node->r && node->r->data == node->data)
            Rightmax += right + 1;

        *ans = max(*ans, Leftmax + Rightmax);
        return max(*ans, Leftmax + Rightmax);
    }

    /* Driver function to find length of
   longest same value path*/
    int longestSameValuePath(Node *root)
    {
        int ans = 0;
        length(root, &ans);
        return ans;
    }

    void resetState()
    {
        getMaxPathSum = 0;
        getWeightSum = 0;
        tower = 0;
        sumUnited = 0;
    }

private:
};

int main()
{
    f func;
    string s;
    char command[20];
    while (cin >> s)
    {
        s.erase(0, 1);
        s.pop_back();
        Node *root = func.treeFromString(s, 0, s.length() - 1);
        while (cin >> command)
        {
            if (!strcmp(command, "Traverse")) //! Done
                func.Traverse(root);
            else if (!strcmp(command, "DeleteLeaf")) //! Done
                func.RemoveLeaves(root);
            else if (!strcmp(command, "WeightSum")) //! Done
            {
                func.WeightSum(root);
                cout << func.getWeightSum << endl;
                func.resetState();
            }
            else if (!strcmp(command, "Foldable")) //! Done
            {
                if (func.Foldable(root))
                    cout << "Yes" << endl;
                else
                    cout << "No" << endl;
            }
            else if (!strcmp(command, "Invert")) //! Done
                func.Invert(root);
            else if (!strcmp(command, "BinaryTower")) //
            {
                func.BinaryTower(root);
                func.countTower(root);
                cout << func.tower << endl;
                func.resetState();
            }
            else if (!strcmp(command, "MaximumPathSum")) //! Done
            {
                func.MaximumPathSum(root, 0);
                cout << func.getMaxPathSum << endl;
                func.resetState();
            }
            else if (!strcmp(command, "KingdomUnitedPath")) //
            {
                cout << func.longestSameValuePath(root) << endl;
                func.resetState();
            }
            else //! quit
            {
                cout << endl;
                break;
            }
        }
    }
}