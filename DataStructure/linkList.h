#pragma once
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class _NodeLink;
typedef class _Node
{
private:
    int data;
    _Node *next;

public:
    _Node()
    {
        data = 0;
        next = NULL;
    }
    _Node(int x)
    {
        data = x;
        next = NULL;
    }
    friend class _NodeLink;
} Node;

typedef class _NodeLink // singular linked list
{
private:
    Node *first;

public:
    void pushBack(int x)
    {
        Node *newNode = new Node(x);
        if (first == NULL)
        {
            first = newNode;
            return;
        }
        Node *cur = first;
        while (cur->next != NULL)
        {
            cur = cur->next;
        }
        cur->next = newNode;
    }
    void printList()
    {
        Node *cur = first;
        while (cur != NULL)
        {
            cout << cur->data;
            cur = cur->next;
        }
        cout << endl;
    }
    void freeList(Node *head)
    {
        Node *cur = head;
        while (cur->next != NULL)
        {
            Node *tmp = cur;
            cur = cur->next;
            free(cur);
        }
    }
} NodeLink;
