#pragma once
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class NodeLink;
class Node;

typedef class Node
{
private:
    int data;
    Node *next;

public:
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
    friend class NodeLink;
} Node;

typedef class NodeLink // singular linked list
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
    void pushFront(int x)
    {
        Node *newNode = new Node(x);
        if (first == NULL)
        {
            first = newNode;
            return;
        }
        Node *cur = first;
        first = newNode;
        first->next = cur;
    }
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
    void delNPos(int n)
    {
        Node *cur = first;
        Node *prev;
        if (n == 1)
        {
            prev = first;
            first = first->next;
            free(prev);
            return;
        }
        while (--n && cur->next != NULL)
        {
            prev = cur;
            cur = cur->next;
        }
        prev->next = cur->next;
        free(cur);
    }
    void insertNPos(int n, int x)
    {
        Node *cur = first;
        if (n == 1)
        {
            pushFront(x);
            return;
        }
        for (int i = 2; (i < n) && cur->next != NULL; i++)
        {
            cur = cur->next;
        }
        Node *newN = new Node(x);
        newN->next = cur->next;
        cur->next = newN;
    }
} NodeLink;
