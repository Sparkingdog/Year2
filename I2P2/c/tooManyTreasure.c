#include <stdio.h>
#include <stdlib.h>
int sum_LtoR(int *arr, int l, int r)
{
    int res = 0;
    res = arr[r] - arr[l - 1];

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
    int arr[100000];
    int ans, ans2, range;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
        if (arr[i] < 0)
            arr[i] = 0;
        arr[i] += arr[i - 1];
    }
    while (q--)
    {
        scanf("%d%d%d", &l, &r, &m);
        ans = sum_LtoR(arr, l, l + m - 1); //1-4
        printf("%d\n", ans);
    }
}
/* 5 5
97836 12032 3029 -51025 -73177
5 5 1
1 4 3
1 2 1
4 4 1 */