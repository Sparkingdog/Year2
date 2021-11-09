// 4_1
// check pattern
#include <stdio.h>
#include <string.h>
#define Max(x, y) ((x > y) ? x : y)
#define Min(x, y) ((x < y) ? x : y)
char s[1001], p[1001];
int slen, plen, q;

int check(int index)
{
    for (int j = 0; j < plen; j++)
    {
        if (s[index + j] != p[j])
            return 0;
    }
    return 1;
}

int main()
{
    while (~scanf("%s%s", s, p))
    {
        int prefix[1087] = {0}, ans = 0;
        slen = strlen(s);
        plen = strlen(p);
        for (int i = 0; i < slen - (plen - 1); i++)
        {
            prefix[i + 1] = check(i) + prefix[i];
        }
        scanf("%d", &q);
        while (q--)
        {
            int l, r;
            scanf("%d%d", &l, &r);
        }
    }
}