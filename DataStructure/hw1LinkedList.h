#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#pragma once

class cardLinkedList;
class card // singly linked list
{
private:
    int data;
    card *next;

public:
    card()
    {
        data = 0;
        next = NULL;
    }
    card(int x)
    {
        data = x;
        next = NULL;
    }
    friend class cardLinkedList;
};

class cardLinkedList // singly linked list
{
private:
    card *first;

public:
    void cardLinkedList::insertBack(int x) // pushBack
    {
        card *newNode = new card(x);
        if (first == NULL)
        {
            first = newNode;
            return;
        }
        card *cur = first;
        while (cur->next != NULL) // traverse to the back
        {
            cur = cur->next;
        }
        cur->next = newNode;
    }
    void cardLinkedList::printList()
    {
        if (first == NULL)
        {
            cout << endl;
            return;
        }
        card *cur = first;
        while (cur != NULL)
        {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << endl;
    }
};

class people // circular linked list
{
public:
    people();
    ~people();

private:
};