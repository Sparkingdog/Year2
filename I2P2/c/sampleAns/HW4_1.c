#include <stdio.h>
#include <string.h>
#define Max(x, y) ((x) > (y) ? (x) : (y))
#define Min(x, y) ((x) < (y) ? (x) : (y))
char S[1001], p[1001];
int slen, plen, q;
int check(int idex)
{
    for (int j = 0; j < plen; j++)
        if (S[idex + j] != p[j])
            return 0;
    return 1;
}

int main()
{
    while (~scanf("%s%s", S, p))
    {
        int prefix[1087] = {0}, ans = 0;
        slen = strlen(S);
        plen = strlen(p);
        for (int i = 0; i < slen - (plen - 1); i++)
            prefix[i + 1] = check(i) + prefix[i];

        scanf("%d", &q);
        while (q--)
        {
            int l, r;
            scanf("%d%d", &l, &r);
            int h = r - plen + 1, b = l - 1;
            int temp = (h <= b) ? 0 : (prefix[h] - prefix[b]);
            ans = Max(ans, temp);
        }
        printf("%d\n", ans);
    }
}