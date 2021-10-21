//3 per 6
#include <bits/stdc++.h>
using namespace std;

typedef struct _Node
{
    int id;
    struct _Node *next;
} Node;

Node *first;
Node *bomb;

Node *createList(int n)
{
    Node *head = new Node();
    Node *cur = head;
    head->next = head;
    for (int i = 2; i <= n; i++)
    {
        Node *newN = new Node();
        newN->next = head;
        cur->next = newN;
        cur = newN;
    }
    return head;
}
int length()
{
    int l = 0;
    Node *cur = bomb;
    do
    {
        l++;
        cur = cur->next;

    } while (cur != bomb);
    return l;
}
void printList()
{
    Node *cur = bomb;
    do
    {
        if (cur->next == bomb)
        {
            cout << cur->id;
            cout << endl;
            break;
        }
        cout << cur->id << " ";
        cur = cur->next;
    } while (cur != bomb);
}
Node *delNPos(int n, Node *b)
{
    Node *prev, *cur = b;
    while (n--)
    {
        prev = cur;
        cur = cur->next;
    }
    prev->next = cur->next;
    b = cur->next;
    free(cur);
    return b;
}
void insertNpos(int id)
{
    Node *newN = new Node();
    newN->id = id;
    newN->next = bomb->next;
    bomb->next = newN;
}
int main()
{
    int n;
    int i, j;
    cin >> n;
    first = createList(n);
    Node *cur = first;
    while (n--)
    {
        cin >> cur->id;
        cur = cur->next;
    }
    bomb = first;
    while (cin >> i >> j)
    {
        //i=1 bomb
        if (i == 1)
        {
            bomb = delNPos(j, bomb);
        }
        //i=2 new player join
        else if (i == 2)
        {
            insertNpos(j);
        }
        else if (bomb->next == bomb)
            break;
        else
            break;
    }
    printList();
}