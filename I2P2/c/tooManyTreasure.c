#include <stdio.h>
#include <stdlib.h>
int maxTreasure(int *arr, int l, int r, int m)
{
    int res;
    do
    {
        res += arr[l++];
    } while (m--);

    if (res < 0)
    {
        return 0;
    }
    else
    {
        return res;
    }
}
int main()
{
    int n, q;
    int l, r, m;
    int arr[1000001];
    int prefixsum[1000001];
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
        prefixsum[i] += arr[i];
    }
    while (q--)
    {
        scanf("%d%d%d", &l, &r, &m);
        printf("%d\n", maxTreasure(arr, l, r, m));
    }
}
