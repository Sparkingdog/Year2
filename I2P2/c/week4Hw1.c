#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[1001], p[1001];
    int q;
    int l, r;
    while (~scanf("%s %s", s, p))
    {
        scanf("%d", &q);
        int sumprefix[1001] = {0};
        int ans = 0;
        int len = strlen(p);
        for (int i = 0; i < len + 1; i++)
        {
            if (s[i] == p[i] && !memcmp(p, s + i * sizeof(char), len))//
            {
                sumprefix[i + 1] = sumprefix[i] + 1;
            }
            else
            {
                if (i != 0)
                {
                    sumprefix[i + 1] = sumprefix[i];
                }
            }
        }
        while (q--)
        {
            scanf("%d %d", &l, &r);
        }
        printf("%d\n", ans);
    }
    return 0;
}