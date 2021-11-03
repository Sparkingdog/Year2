#include <bits/stdc++.h>
#include <ctype.h>
#include <stack>
using std::stack;
using namespace std;

typedef struct _mat
{
    char c;
    int x;
    int y;
} Mat;
stack<char> st;
stack<int> n_st;
int matSize(Mat a, Mat b) //a*b
{
    if (a.y == b.x)
    {
        return (a.x * b.y);
    }
    return -1e9;
}
Mat calc(char a, char b, Mat m[])
{
    matSize(m[(a - 'A')], m[(b - 'A')]);
    Mat c;
    c.x = m[(a - 'A')].x;
    c.y = m[(b - 'A')].y;
    return c;
}
int main()
{
    Mat m[2000];
    int optop = 0, numtop = 0, i = 0, matstack[50], opstack[30];
    char s[100001];
    int t, q;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> m[i].c >> m[i].x >> m[i].y;
    }

    while (q--)
    {
        cin >> s;
        //
        char c;
        for (int i = 0; (c = s[i]) != '\0'; i++)
        {
            if (isalpha(c))
            {
                st.push(c);
            }
            else if (c == ')')
            {
                char b = st.pop();
                char a = st.pop();
                st.push(calc(a, b, m));
            }
        }

        //
    }