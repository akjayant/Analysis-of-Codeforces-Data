#include <bits/stdc++.h>
using namespace std;

const int maxn = 100100;
const int MOD = 1e9 + 7;

long long f[maxn];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    f[1] = 2;
    f[2] = 4;
    for (int i = 0; i <= max(n, m); i++)
    {
        f[i + 3] = (f[i + 1] + f[i + 2]) % MOD;
    }
    printf("%lld\n", (f[n] + f[m] - 2 + MOD) % MOD);
    return 0;
}
