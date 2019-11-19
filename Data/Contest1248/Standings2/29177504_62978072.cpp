#include <bits/stdc++.h>
using namespace std;

const int maxn = 100100;
int p[2];
int q[2];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, m;
        p[0] = p[1] = q[0] = q[1] = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            long long temp;
            scanf("%lld", &temp);
            p[temp % 2]++;
        }
        scanf("%d", &m);
        for (int i = 0; i < m; i++)
        {
            long long temp;
            scanf("%lld", &temp);
            q[temp % 2]++;
        }
        printf("%lld\n", 1ll * p[0] * q[0] + 1ll * p[1] * q[1]);
    }
    return 0;
}
