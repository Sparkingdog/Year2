#include <bits/stdc++.h>
using namespace std;

typedef struct deck
{
    int data;
    struct deck *next;
    deck(int x)
    {
        data = x;
        next = NULL;
    }
} deck;

typedef struct people
{
    int id;
    struct people *next;
    deck *d;
    deck *buildDeck(int m)
    {
        int id = 1;
        deck *first = new deck(id++);
        deck *cur = first;
        while (--m)
        {
            deck *tmp = new deck(id++);
            cur->next = tmp;
            cur = cur->next;
        }
        return first;
    }

    people(int num, int cards) // m cards
    {
        id = num;
        d = buildDeck(cards);
    }
} people;

people *buildPlayers(int n, int m)
{
    int id = 1;
    people *first = new people(id++, m);
    people *cur = first;
    while (--n)
    {
        people *tmp = new people(id++, m);
        cur->next = tmp;
        tmp->next = first;
        cur = cur->next;
    }
    return first;
}

void printDeck(deck *first)
{
    deck *cur = first;
    while (cur != NULL)
    {
        cout << cur->data << "->";
        cur = cur->next;
    }
    printf("NULL\n");
}

int delNpos(deck **first, int n)
{
    int del;
    deck *cur = *first;
    deck *prev;
    if (n == 1)
    {
        prev = cur;
        *first = (*first)->next;
        del = prev->data;
        free(prev);
        return del;
    }
    while (--n && cur->next != NULL)
    {
        prev = cur;
        cur = cur->next;
    }
    prev->next = cur->next;
    del = cur->data;
    free(cur);
    return del;
}
void insNpos(deck **first, int n, int x)
{
    deck *cur = *first;
    if (n == 1)
    {
        deck *newD = new deck(x);
        *first = newD;
        (*first)->next = cur;
        return;
    }
    for (int i = 2; (i < n) && cur->next != NULL; i++)
    {
        cur = cur->next;
    }
    deck *newD = new deck(x);
    newD->next = cur->next;
    cur->next = newD;
}

void drawNextCard(people *player, int idxDraw, int idxPlace)
{
    int del = delNpos(&player->next->d, idxDraw);
    insNpos(&player->d, idxPlace, del);
}

int main()
{
    people *players; // pointer to first player
    int a, b;
    int N, M, K;
    int joker;
    //  N player M cards K joker cards
    cin >> N >> M >> K;
    players = buildPlayers(N, M);
    people *cur = players;
    /*  while (K--) // insert joker
     {
         cin >> joker;
         cur = players;
         while (N--) // check if id == joker
         {
             if (cur->id == joker)
             {
                 cur->d->data = -999; // joker
                 break;
             }
             cur = cur->next;
         }
     } */
    people *ptr = players;
    while (cin >> a >> b)
    {
        if (a == -1 && b == -1)
            break;
        else
        {
            drawNextCard(ptr, a, b);
        }
        ptr = ptr->next;
    }
    cur = players;
    do // point to first player
    {
        cout << "player " << cur->id << ":";
        printDeck(cur->d);
        cur = cur->next;
    } while (cur != players); // traverse through all player
    return 0;
}