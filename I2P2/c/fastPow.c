#include <stdio.h>
#include <stdlib.h>

int fast_pow(int x, int n)
{ //x^n
    if (n == 1)
    {
        return x;
    }

    // 如果 n = 2k (偶數)
    // 則 x^n = (x^k) * (x^k)
    if (n % 2 == 0) //even
    {
        int xk = fast_pow(x, n / 2);
        return xk * xk;
    }
    //odd
    // 如果 n = 2k + 1 (奇數)
    // 則 x^n = x * (x^k) * (x^k)
    int xk = fast_pow(x, (n - 1) / 2);
    return x * xk * xk;
}

int PowerMod(int a, int b, int c)
{
    int ans = 1;
    a = a % c;
    while (b > 0)
    {
        if (b % 2 == 1)
            ans = (ans * a) % c;
        b = b / 2;
        a = (a * a) % c;
    }
    return ans;
}
int main()
{
    printf("%d", fast_pow(4, 13));
}