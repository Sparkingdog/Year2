#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include "stack.h"
using namespace std;

typedef struct node
{
    int data;
    struct node *l;
    struct node *r;
} Node;
class f
{
public:
    int getMaxPathSum;
    int getWeightSum;
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
        if ((*root)->l == NULL && (*root)->r == NULL) //leaf
        {
            free(*root);
            return;
        }
        DeleteLeaf(&(*root)->l);
        DeleteLeaf(&(*root)->r);
        return;
    }
    // function to return the index of close parenthesis
    int findIndex(string str, int si, int ei)
    {
        if (si > ei)
            return -1;

        //stack
        charStack s;

        for (int i = si; i <= ei; i++)
        {

            // if open parenthesis, push it
            if (str[i] == '(')
                s.push(str[i]);

            // if close parenthesis
            else if (str[i] == ')')
            {
                if (s.peek() == '(')
                {
                    s.pop();

                    // if stack is empty, this is
                    // the required index
                    if (s.isEmpty())
                        return i;
                }
            }
        }
        // if not found return -1
        return -1;
    }

    // function to construct tree from string
    Node *treeFromString(string str, int si, int ei)
    {
        // Base case
        if (si > ei)
            return NULL;

        // new root
        Node *root = newN(str[si] - '0');
        int index = -1;

        // if next char is '(' find the index of
        // its complement ')'
        if (si + 1 <= ei && str[si + 1] == '(')
            index = findIndex(str, si + 1, ei);

        // if index found
        if (index != -1)
        {

            // call for left subtree
            root->l = treeFromString(str, si + 2, index - 1);

            // call for right subtree
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
    void BinaryTower(Node *root)
    {
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
    void KingdomUnitedPath(Node *root)
    {
    }
    void resetState()
    {
        getMaxPathSum = 0;
        getWeightSum = 0;
    }

private:
};

int main()
{
    f func;
    string s;
    char command[20];
    cin >> s;
    s.erase(0, 1);
    s.pop_back();
    Node *root = func.treeFromString(s, 0, s.length() - 1);
    while (cin >> command)
    {
        if (!strcmp(command, "Traverse")) //! Done
            func.Traverse(root);
        else if (!strcmp(command, "DeleteLeaf")) //! AlmostDone?
            func.DeleteLeaf(&root);
        else if (!strcmp(command, "WeightSum")) //! Done
        {
            func.WeightSum(root);
            cout << func.getWeightSum << endl;
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
        else if (!strcmp(command, "BinaryTower")) //TODO
            func.BinaryTower(root);
        else if (!strcmp(command, "MaximumPathSum")) //! Done
        {
            func.MaximumPathSum(root, 0);
            cout << func.getMaxPathSum << endl;
        }
        else if (!strcmp(command, "KingdomUnitedPath")) //TODO
            func.KingdomUnitedPath(root);
        else //! quit
            break;
    }
}