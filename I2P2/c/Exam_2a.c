#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define ll long long
ll int a, b, n;
ll int m;
ll int q, l;
ll int L, R;
ll int dec;
ll int S;

ll fpw(ll x, ll y, ll m)
{
    ll res = 1 % m;
    for (; y; y /= 2, x = (x * x) % m)
        if (y & 1)
            res = (res * x) % m;
    return res;
}

int convert(int num)
{
    int decimal = 0, i = 0, rem;
    while (num != 0)
    {
        rem = num % 10;
        num /= 10;
        decimal += rem * pow(2, i);
        ++i;
    }
    return decimal;
}
int main()
{
    scanf("%d %d %d ", &a, &b, &n);
    scanf("%d", &m);
    scanf("%d%d", &q, &l);
    S = fpw(2, a, pow(2, b));

    // while (q--)
    // {
    //     scanf("%d%d", &L, &R);
    // }
    printf("%lld", S);
    printf("\n");
}