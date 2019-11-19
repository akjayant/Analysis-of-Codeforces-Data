#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 100005;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;

ll row[maxn][2];

ll qpow(ll a, int b) {
    ll c = 1;
    while (b) {
        if (b & 1) c *= a, c %= mod;

        b /= 2;
        a *= a; a %= mod;
    }
    return c;
}

ll column[maxn][2];

int main() {

    int n, m; scanf("%d%d", &n, &m);
    row[1][0] = 2, row[1][1] = 0;
    for (int i = 2; i <= m; i++) {
        row[i][0] = (row[i - 1][0] + row[i - 1][1]) % mod;
        row[i][1] = row[i - 1][0];
    }

//    ll tmp = (row[m][0] + row[m][1] - 2) % mod;
//
//    ll ans = (qpow(2, n) + tmp) % mod;
//    printf("%lld\n", ans);

    ll tmp = (row[m][0] + row[m][1] - 2) % mod;
    column[1][0] = 2, column[1][1] = 0;
    for (int i = 2; i <= n; i++) {
        column[i][0] = (column[i - 1][0] + column[i - 1][1]) % mod;
        column[i][1] = column[i - 1][0];
    }

    printf("%lld\n", (column[n][0] + column[n][1] + tmp) % mod);

    return 0;
}