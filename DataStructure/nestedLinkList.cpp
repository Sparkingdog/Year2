#include <bits/stdc++.h>
#include "nestedLinkList.h"
using namespace std;

chain *first;
chain c;
int n, m, k;
int jokerIdx[101];
int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++)
    {
        cin >> jokerIdx[i]; //read joker index
    }

    first = c.createchain(n); //create player link (circular linked list)

    chain *a = first;
    do
    {
        a->card = c.createCardList(m);
        for (int i = 1; i <= k; i++)
        {
            chain *tmp = a;
            tmp->joker(jokerIdx[i], tmp);
            tmp = tmp->next;
        }
        a = a->next;

    } while (a->next != first);
    chain *b = first;
    do
    {
        cout << "Player " << b->getID() << " :";
        b = b->next;
        c.printList();
    } while (b->next != first);
}