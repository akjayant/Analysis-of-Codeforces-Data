#include <cstdio>
#include <cstring>
#include <algorithm>

#define maxn 100005

using namespace std;

int n, a[maxn], ans, sum1, sum2;

inline int read()
{
    char ch = getchar();
    int ret = 0, f = 1;
    while (ch > '9' || ch < '0')
    {
        if (ch == '-')
            f = -f;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
        ret = ret * 10 + ch - '0', ch = getchar();
    return ret * f;
}

int main()
{
    n = read();
    for (int i = 1; i <= n; ++i)
    {
        a[i] = read();
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= (n >> 1); ++i)
    {
        sum1 += a[i];
    }
    for (int i = (n >> 1) + 1; i <= n; ++i)
    {
        sum2 += a[i];
    }
    printf("%I64d", 1ll * sum1 * sum1 + 1ll * sum2 * sum2);
    return 0;
}