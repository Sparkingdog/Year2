/* C++ program to implement basic stack
   operations */
// stack with array
#pragma once
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
typedef class charStack
{
    char top;

public:
    char a[MAX]; // Maximum size of charStack

    charStack() { top = -1; }
    bool push(char x);
    char pop();
    char peek();
    bool isEmpty();
} charStack;

bool charStack::push(char x)
{
    if (top >= (MAX - 1))
    {
        cout << "charStack Overflow";
        return false;
    }
    else
    {
        a[++top] = x;
        return true;
    }
}

char charStack::pop()
{
    if (top < 0)
    {
        cout << "charStack Underflow";
        return 0;
    }
    else
    {
        char x = a[top--];
        return x;
    }
}
char charStack::peek() // return the top value
{
    if (top < 0)
    {
        cout << "charStack is Empty";
        return 0;
    }
    else
    {
        char x = a[top];
        return x;
    }
}

bool charStack::isEmpty()
{
    return (top < 0);
}
typedef class numStack
{
    int top;

public:
    int a[MAX]; // Maximum size of numStack

    numStack() { top = -1; }
    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
} numStack;

bool numStack::push(int x)
{
    if (top >= (MAX - 1))
    {
        cout << "numStack Overflow";
        return false;
    }
    else
    {
        a[++top] = x;
        cout << x << " pushed into stack\n";
        return true;
    }
}

int numStack::pop()
{
    if (top < 0)
    {
        cout << "numStack Underflow";
        return 0;
    }
    else
    {
        int x = a[top--];
        return x;
    }
}
int numStack::peek() // return the top value
{
    if (top < 0)
    {
        cout << "numStack is Empty";
        return 0;
    }
    else
    {
        int x = a[top];
        return x;
    }
}

bool numStack::isEmpty()
{
    return (top < 0);
}
// Driver program to test above functions
/* int main()
{
    class numStack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.pop() << " Popped from stack\n";
    // print all elements in stack :
    cout << "Elements present in stack : ";
    while (!s.isEmpty())
    {
        // print top element in stack
        cout << s.peek() << " ";
        // remove top element in stack
        s.pop();
    }

    return 0;
} */