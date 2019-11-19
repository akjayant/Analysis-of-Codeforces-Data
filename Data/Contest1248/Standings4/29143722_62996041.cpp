#include <bits/stdc++.h>

#define int long long

#define in(x) scanf("%lld", &x)

using namespace std;

const int maxn = 1e5 + 10;

signed main()
{
    int t;
    in(t);

    while (t--)
    {
        int n;
        in(n);

        int p[2] = {0, 0};
        for (int i = 0, u; i < n; i++)
            in(u), p[u % 2]++;

        int m;
        in(m);

        int q[2] = {0, 0};
        for (int i = 0, u; i < m; i++)
            in(u), q[u % 2]++;

        printf("%lld\n", q[0] * p[0] + q[1] * p[1]);
    }

    return 0;
}