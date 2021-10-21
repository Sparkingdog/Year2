#include <stdio.h>

float x;

int main()
{
    while (~scanf("%f", &x))
    {
        int ans = *(int *)(&x);
        for (int i = 31; i >= 0; i--)
            printf("%d", (ans & (1 << i)) ? 1 : 0);
        puts("");
    }
    return 0;
}