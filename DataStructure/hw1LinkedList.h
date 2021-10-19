#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#pragma once

class cardLinkedList;
class peopleLinkedList;
//
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
    void insertBack(int x) // pushBack
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
    void printList()
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
    bool hasJoker()
    {
        card *cur = first;
        while (cur != NULL)
        {
            if (cur->data == -1) // joker
                return true;
            cur = cur->next;
        }
        return false;
    }
};

class people // circular linked list
{
private:
    int id;
    card card;
    people *next;

public:
    people()
    {
        next = NULL;
    }
    friend class peopleLinkedList;
};

class peopleLinkedList // circular linked list
{
private:
    people *first;

public:
    people *createCircularLinkedList(int N)
    {
        first = new people();
        first->id = 1;
        first->next = first;
        people *cur = first;
        for (int i = 2; i <= N; i++)
        {
            people *newP = new people();
            newP->id = i;
            newP->next = first;
            cur->next = newP;
            cur = newP;
        }
        return first;
    }
    void takeAndInsert(int a, int b);
};