#include <stack>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> st;
    stack<int> buffer;
    int n;
    cin >> n;
    int m = n;
    int x;
    while (n--)
    {
        cin >> x;
        st.push(x);
    }
    while (m--)
    {
        for (int i = 0; i < m; i++)
        {
            int top = st.top();
            buffer.push(top);
            st.pop();
        }
    }
}