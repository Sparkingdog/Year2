typedef class charStack
{
    int top;

public:
    int a[MAX]; // Maximum size of charStack

    charStack() { top = -1; }
    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
} charStack;

bool charStack::push(int x)
{
    if (top >= (MAX - 1))
    {
        cout << "charStack Overflow";
        return false;
    }
    else
    {
        a[++top] = x;
        cout << x << " pushed into stack\n";
        return true;
    }
}

int charStack::pop()
{
    if (top < 0)
    {
        cout << "charStack Underflow";
        return 0;
    }
    else
    {
        int x = a[top--];
        return x;
    }
}
int charStack::peek() // return the top value
{
    if (top < 0)
    {
        cout << "charStack is Empty";
        return 0;
    }
    else
    {
        int x = a[top];
        return x;
    }
}

bool charStack::isEmpty()
{
    return (top < 0);
}