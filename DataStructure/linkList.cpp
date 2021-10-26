#include <bits/stdc++.h>
#include <iostream>
#include "linkList.h"
using namespace std;

class NodeLink;
class Node;

NodeLink l;
int main()
{
    l.pushBack(2);
    l.pushBack(3);
    l.pushFront(1);
    // l.insertNPos(9, 88);
    l.delNPos(1);
    l.printList();
    return 0;
}