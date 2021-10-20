/* A C++ code to traverse a linked list */
//https://www.simplilearn.com/tutorials/data-structure-tutorial/doubly-linked-list
#include <bits/stdc++.h>

using namespace std;

/* A class to create a node */

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

    /* creating newnode */

    Node *newnode = new Node();

    /* put in the data */

    newnode->data = newdata;

    /* since we are insert at the beginning of the list,

prev is always NULL */

    newnode->prev = NULL;

    /* link the next of newnode to the head */

    newnode->next = (*head);

    /* change prev of head node to newnode */

    if ((*head) != NULL)

        (*head)->prev = newnode;

    /* changing head */

    (*head) = newnode;
}

/* A c++ program to traverse the linked list */

void traverse(Node *node)

{

    while (node != NULL)

    {

        cout << node->data << " ";

        node = node->next;
    }
}

/* Function to reverse traverse a Linked List */

void revtraverse(Node **head)

{

    Node *tail = *head;

    // Traversing till tail of the linked list

    while (tail->next != NULL)
    {

        tail = tail->next;
    }

    // Traversing linked list from tail

    // and printing the node->data

    while (tail != *head)
    {

        cout << tail->data << " ";

        tail = tail->prev;
    }

    cout << tail->data << endl;
    ;
}

int main()

{

    /* Start with the empty list */

    Node *head = NULL;

    /* Let us create a linked list: 2->3->5->7 */

    push(&head, 7);

    push(&head, 5);

    push(&head, 3);

    push(&head, 2);

    cout << "Original Linked list" << endl;

    traverse(head);

    /* Reverse linked list */

    cout << "\nReversed Linked list" << endl;

    revtraverse(&head);

    return 0;
}