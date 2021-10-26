#pragma once
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class card
{
    friend class people;

private:
    int data;
    card *next;
    card(int x)
    {
        data = x;
        next = NULL;
    }

public:
    card *buildDeck(int m)
    {
        card *first_card = new card(1);
        card *cur = first_card;
        for (int i = 2; i <= m + 1; i++)
        {
            card *newC = new card(i);
            cur->next = newC;
            cur = cur->next;
        }
        return first_card;
    }
    void printDeck(card *head)
    {
        card *cur = head;
        while (cur != NULL)
        {
            cout << cur->data << "->";
            cur = cur->next;
        }
        cout << "NULL" << endl;
    }
    void inNPos(int n, int x);
    void delNPos(int n);
};

class people
{
private:
    int id;
    people *next;

public:
    card card;
    people *buildPlayers(int n);
};
