#include <stdio.h>
#include <string.h>
#define ll long long
#define MOD 1000000007

typedef struct _MAT
{
    ll d[2][2];
} Mat;
Mat mul(Mat A, Mat B)
{
    Mat res;
    memset(res.d, 0, sizeof(res));
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
                res.d[i][k] = (res.d[i][k] + A.d[i][j] * B.d[j][k]) % MOD;
    return res;
}
Mat I2;

void init() { I2.d[0][0] = I2.d[1][1] = 1; }
Mat fpw(Mat x, ll y)
{
    Mat res = I2;
    for (; y; y /= 2, x = mul(x, x))
        if (y & 1)
            res = mul(res, x);
    return res;
}
Mat fpw_recursive(Mat x, ll y)
{
    if (y == 0)
        return I2;
    Mat tmp = fpw_recursive(x, y / 2);
    if (y & 1)
        return mul(mul(tmp, tmp), x);
    else
        return mul(tmp, tmp);
}

int main()
{
    init();
    Mat mat;
    mat.d[0][0] = mat.d[0][1] = mat.d[1][0] = 1;
    mat.d[1][1] = 0;
    ll n;
    while (~scanf("%lld", &n))
    {
        Mat ans = fpw(mat, n);
        printf("%lld\n", ans.d[1][0]);
    }
    return 0;
}