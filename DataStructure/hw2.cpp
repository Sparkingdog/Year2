#include <bits/stdc++.h>
#define max 200001
#define ll long
using namespace std;

class Stack
{
private:
    int top;

public:
    int a[max];
    Stack() { top = 0; }
    void push(ll x);
    int pop();
    int peek();
    bool isEmpty();
};

bool Stack::isEmpty()
{
    return (top < 1);
}
void Stack::push(ll x)
{
    if (top >= (max - 1))
        return;

    else
    {
        a[++top] = x;
    }
}
int Stack::pop()
{
    if (top < 1)
    {
        return 0;
    }
    else
    {
        int x = a[top--];
        return x;
    }
}
int Stack::peek()
{
    if (top < 1)
    {
        return 0;
    }
    else
    {
        int x = a[top];
        return x;
    }
}
int main()
{
    int n;
    ll s[max];
    ll x;
    int count;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (s[j] < s[i])
            {
                cout << j << " ";
                break;
            }
            if (j == 1 && i != n)
                cout << 0 << " ";
            else if (j == 1 && i == n)
                cout << 0;
        }
    }
    cout << endl;
    return 0;
}