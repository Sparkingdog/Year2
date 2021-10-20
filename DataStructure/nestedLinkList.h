#pragma once
#include <bits/stdc++.h>
using namespace std;

class chain
{
private:
    int id;

    class Node
    {
    public:
        int data;
        Node *next; //singly linked list
        Node()
        {
            data = 0;
            next = NULL;
        }
        Node(int x)
        {
            data = x;
            next = NULL;
        }
    };
    Node *first;

public:
    int getID()
    {
        return id;
    }
    chain *createchain(int n)
    {
        chain *head = new chain();
        chain *cur = head;
        head->id = 1;
        head->next = head;
        for (int i = 2; i <= n + 1; i++)
        {
            chain *newP = new chain();
            newP->id = i;
            newP->next = head;
            cur->next = newP;
            cur = newP;
        }
        return head;
    }
    Node *createCardList(int m)
    {
        int id = 1;
        first = new Node(id++);
        Node *cur = first;
        for (int i = 2; i <= m; i++)
        {
            Node *newN = new Node(id++);
            cur->next = newN;
            cur = cur->next;
        }
        return first;
    }
    void inNPos(int x, int n);
    int delNPos(int n); //pass to inNPos
    void printList()
    {
        Node *cur = first;
        while (cur != NULL)
        {
            cout << cur->data << "->";
            cur = cur->next;
        }
        cout << "null" << endl;
    }
    void joker(int idx, chain *x)
    {
        Node *cur = card;
        if (idx == x->id)
            cur->data = -999;
    }
    Node *card;
    chain *next;
};