#include <bits/stdc++.h>
using namespace std;

class Chain
{
private:
    int id;

public:
    Chain();
    class Node
    {
    private:
        int data;
        Node *next;

    public:
        Node()
        {
            next = NULL;
        }
        Node(int x)
        {
            data=x;
            next = NULL;
        }
        Node *buildCardChain(int m)
        {
            Node *head = new Node(1);
            if(m==1)
            {
            return head;
            }
            Node *cur = head;
            for (int i = 2; i <= m; i++)
            {
                Node *tmp = new Node(i);
                cur->next = tmp;
                cur = cur->next;
            }
            return head;
        }
    };
};