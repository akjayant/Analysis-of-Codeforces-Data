#include <algorithm>
#include <cstdio>
#include <cstring>

const int mod = 1'000'000'007;

int n, m, f[100010][4];
long long g[100010];
long long pow[100010];

int main() {
    scanf("%d%d", &n, &m);
    pow[0] = 1;
    for (int i = 1; i <= 100000; i++) pow[i] = pow[i - 1] * 2ll % mod;

    f[2][0] = f[2][1] = f[2][2] = f[2][3] = 1;
    for (int i = 3; i <= std::max(n, m); i++) {
        for (int last = 0; last < 4; last++) {
            for (int p = 0; p < 2; p++) {
                if (!(last == 0 && p == 0) && !(last == 3 && p == 1)) {
                    int next = ((last & 1) << 1) + p;
                    f[i][next] = ((long long)f[i][next] + f[i - 1][last]) % mod;
                }
            }
        }
    }
    g[0] = 1;
    g[1] = 2;
    g[2] = 4;
    for (int i = 3; i <= std::max(n, m); i++) {
        for (int j = 0; j < 4; j++) g[i] = (g[i] + f[i][j]) % mod;
    }

    printf("%lld\n", ((g[n] + mod - 2ll) + g[m]) % mod);
    return 0;
}
