#include <iostream>
#include <bits/stdc++.h>
#include "hw1LinkedList.h"
using namespace std;

cardLinkedList l;
int main()
{
    int N, M, K;
    //  N player M cards K joker cards
    cin >> N >> M >> K;
    for (int i = 0; i < M; i++)
    {
        l.insertBack(i);
    }
    l.printList();
    //   while (K--)
    //     cin >> N; // index of person who has joker
    return 0;
}