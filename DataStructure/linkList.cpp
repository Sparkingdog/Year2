#include <bits/stdc++.h>
#include <iostream>
#include "linkList.h"
using namespace std;

class NodeLink;
class Node;

NodeLink l;
int main()
{
    l.pushBack(1);
    l.pushBack(3);
    l.pushFront(9);
    l.pushFront(10);
    l.insertNPos(9, 88);
    //l.delNPos(10);
    l.printList();
    return 0;
}