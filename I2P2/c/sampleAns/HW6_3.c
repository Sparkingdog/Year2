#include <stdio.h>
#include <stdlib.h>
int n, q;
int bridge[(int)2e6 + 1];
int BS(int x)
{
    int L = 0, R = n, ans = 0;
    while (L < R) //while l!=r
    {
        int M = (L + R) / 2; //middle index of array
        if (bridge[M] > x)
            R = M;
        else
            ans = M, L = M + 1;
    }
    if (bridge[ans] == x)
        return ans + 1;
    else
        return 0;
}
int main()
{
    while (~scanf("%d%d", &n, &q))
    {
        for (int i = 0; i < n; i++)
            scanf("%d", &bridge[i]);

        while (q--)
        {
            int query;
            scanf("%d", &query);
            int ans = BS(query); //binary search
            if (ans)             //found
                printf("%d\n", ans);
            else
                printf("Break your bridge!\n");
        }
    }
}