#include <bits/stdc++.h>
#include "stack.h"
// error
bool isOP(char s) { return (s == '+' || s == '-' || s == '*' || s == '/'); }
int main()
{
    Stack stk;
    char s[10000];
    int ans;
    cin >> s;
    char *ptr = s;
    while (isdigit(*ptr))
    {
        stk.push(*ptr);
        ptr++;
    }
    while (isOP(*ptr))
    {
        int num1 = stk.peek();
        stk.pop();
        int num2 = stk.peek();
        stk.pop();
        switch (*ptr)
        {
        case '+':
            stk.push(num1 + num2);
            ptr++;
            break;
        case '-':
            stk.push(num1 - num2);
            ptr++;
            break;
        case '*':
            stk.push(num1 * num2);
            ptr++;
            break;
        case '/':
            stk.push(num1 / num2);
            ptr++;
            break;
        default:
            *ptr++;
            break;
        }
    }
    ans = stk.peek();
    cout << "postfix ans is:" << ans;
}