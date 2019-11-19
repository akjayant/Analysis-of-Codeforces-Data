#include <cstdio>
#include <cstring>
#include <algorithm>

#define int long long

#define maxn 100005

using namespace std;

int n, m, T, a[maxn], ans, sum1, cnt1[2], cnt2[2], sum2;

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

signed main()
{
T = read();
    while (T--)
    {
        n = read();
        cnt1[0] = cnt1[1] = cnt2[0] = cnt2[1] = 0;
        for (int i = 1; i <= n; ++i)
            cnt1[read() & 1]++;
        m = read();
        for (int i = 1; i <= m; ++i)
            cnt2[read() & 1]++;
        printf("%I64d\n", cnt1[0] * cnt2[0] + cnt1[1] * cnt2[1]);
    }
    return 0;
}