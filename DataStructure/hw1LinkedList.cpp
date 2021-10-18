#include <iostream>
#include <bits/stdc++.h>
#include "hw1LinkedList.h"
using namespace std;

cardLinkedList c;
peopleLinkedList p;
int main()
{
    int N, M, K;
    int a, b;
    //  N player M cards K joker cards
    cin >> N >> M >> K;
    p.createCircularLinkedList(N);
    for (int i = 1; i <= M; i++)
    {
        c.insertBack(i);
    }
    while (cin >> a, b) // draw  a'th card from next place on b'th place
    {
        if (a == -1 && b == -1)
            break;
    }
    c.printList();
    return 0;
}