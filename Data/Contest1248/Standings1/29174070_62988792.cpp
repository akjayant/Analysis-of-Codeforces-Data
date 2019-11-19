#include <cstdio>

const int Maxn = 100010;
const int Mod = 1e9 + 7;
int n, m, F[Maxn];

int main()
{
    scanf("%d%d", &n, &m);
    F[1] = 1;
    F[2] = 2;
    for (int i = 3; i <= n || i <= m; ++i)
        F[i] = (F[i - 1] + F[i - 2]) % Mod;
    long long Ans = F[n] + F[m] - 1;
    printf("%lld\n", Ans * 2 % Mod);
    return 0;
}