#include <cstdio>
#include <cstring>
#include <algorithm>

#define maxn 100005

using namespace std;

const int TT = (int)1e9 + 7;
int n, m, f[maxn], g[maxn], ans;

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
    n = read(), m = read();
    if (n < m)
        swap(n, m);
    f[1] = 2, f[2] = 2;
    for (int i = 3; i <= n + 1; ++i)
        f[i] = (f[i - 1] + f[i - 2]) % TT;
    for (int i = 1; i <= m + 1; ++i)
        g[i] = (g[i - 1] + f[i]) % TT;
    printf("%d\n", (f[n + 1] + g[m - 1]) % TT);
    return 0;
}