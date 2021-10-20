//A c++ program to implement linked list
//https://www.simplilearn.com/tutorials/data-structure-tutorial/doubly-linked-list
#include <bits/stdc++.h>

using namespace std;

/* A class to create node */

class Node

{

public:
    int data;

    Node *next;

    Node *prev;
};

//A function to insert at the

//beginning of the list

void push(Node **head, int newdata)

{

    //create new node

    Node *newnode = new Node();

    /* put in the data */

    newnode->data = newdata;

    /* As we are adding at the beginning,

prev is always NULL */

    newnode->prev = NULL;

    /* link new node's next to head */

    newnode->next = (*head);

    /* change prev of head node to newnode */

    if ((*head) != NULL)

        (*head)->prev = newnode;

    /* changing head node */

    (*head) = newnode;
}

/* A c++ program to print the list */

void printlist(Node *head)

{

    while (head != NULL)

    {

        cout << head->data << " ";

        head = head->next;
    }
}

int main()

{

    /* We will start with an empty list */

    Node *head = NULL;

    /*lets create a linked list: 2->3->5->7 */

    push(&head, 7);

    push(&head, 5);

    push(&head, 3);

    push(&head, 2);

    cout << "Created Doubly Linked list:" << endl;

    printlist(head);

    return 0;
}