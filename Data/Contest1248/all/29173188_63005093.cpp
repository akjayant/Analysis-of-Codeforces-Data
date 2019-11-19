#include <bits/stdc++.h>
#define rep(i, x, y) for (int i = x; i <= y; i++)
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7, N = 1e5 + 10;
ll n, m, ans, f[N][2][2];

ll solve(ll n, ll m) {
    f[1][0][0] = f[1][0][1] = 1;
    f[2][1][0] = f[2][1][1] = 1;
    rep(i, 2, m) {
        f[i][0][0] = (f[i - 1][1][1] + f[i - 1][0][1]) % mod;
        f[i][0][1] = (f[i - 1][1][0] + f[i - 1][0][0]) % mod;
        if (i > 2) {
            f[i][1][0] = (f[i - 2][1][1] + f[i - 2][0][1]) % mod;
            f[i][1][1] = (f[i - 2][1][0] + f[i - 2][0][0]) % mod;
        }
    }
    ll ret = 0;
    rep(i, 0, 1) rep(j, 0, 1) ret = (ret + f[m][i][j]) % mod;
    return ret;
}

int main() {
    cin >> n >> m;
    printf("%lld\n", (solve(n, m) + solve(m, n) - 2 + mod) % mod);
    return 0;
}
