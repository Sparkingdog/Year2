#include <stdio.h>
#define LL long long int
LL prefix[(int)2e6 + 1];
int n, q;
int main()
{
    while (~scanf("%d%d", &n, &q))
    {
        int a, b, ansa, ansb;
        LL ans = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld", &prefix[i]);
            prefix[i] += prefix[i - 1];
        }
        while (q--)
        {
            scanf("%d%d", &a, &b);
            if (a <= b)
            {
                if (ans < prefix[b] - prefix[a - 1])
                {
                    ansa = a;
                    ansb = b;
                    ans = prefix[b] - prefix[a - 1];
                }
            }
            else
            {
                if (ans < prefix[b] + prefix[n] - prefix[a - 1])
                {
                    ansa = a;
                    ansb = b;
                    ans = prefix[b] + prefix[n] - prefix[a - 1];
                }
            }
        }
        printf("Max_range: (%lld,%lld); Value: %lld\n", ansa, ansb, ans);
    }
}