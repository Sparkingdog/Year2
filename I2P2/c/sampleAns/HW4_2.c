#include <stdio.h>
#define ll long long

ll fpw(ll x, ll y, ll m)
{
    ll res = 1 % m;
    for (; y; y /= 2, x = (x * x) % m)
        if (y & 1)
            res = (res * x) % m;
    return res;
}
ll fpw_recursive(ll x, ll y, ll m)
{
    if (y == 0)
        return 1 % m;
    ll tmp = fpw_recursive(x, y / 2, m);
    if (y & 1)
        return ((tmp * tmp) % m * x) % m;
    else
        return (tmp * tmp) % m;
}

int main()
{
    ll x, y, m;
    scanf("%lld%lld%lld", &x, &y, &m);
    printf("%lld\n", fpw(x % m, y, m));
    return 0;
}