#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

typedef long long ll;
using namespace std;
const int INF = 2147483647;
const int INF2 = 0x3f3f3f3f;
const ll INF64 = 1e18;
const double INFD = 1e30;
const double EPS = 1e-6;
const double PI = 3.14159265;
const ll MOD = 1e9 + 7;

template <typename T>
inline T read() {
    T X = 0, w = 0;
    char ch = 0;
    while (!isdigit(ch)) {
        w |= ch == '-';
        ch = getchar();
    }
    while (isdigit(ch)) X = (X << 3) + (X << 1) + (ch ^ 48), ch = getchar();
    return w ? -X : X;
}

const int MAXN = 100005;
int n, m, k;
int CASE;
int quickM(ll x, ll p, int mod) {
    if (mod == 0) return 1;
    x %= mod;
    ll ans = 1;
    while (p) {
        if (p & 1) ans = ans * x % mod;
        x = x * x % mod;
        p >>= 1;
    }
    return ans;
}
ll dp[MAXN][2][3];
int main() {
#ifdef LOCALLL
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    memset(dp, 0, sizeof(dp));
    dp[1][0][0] = dp[1][1][0] = 1;
    for (int i = 1; i <= m; i++) {
        dp[i][0][0] = (dp[i][0][0] + dp[i - 1][1][0] + dp[i - 1][1][1]) % MOD;
        dp[i][0][1] = (dp[i][0][1] + dp[i - 1][0][0]) % MOD;
        dp[i][1][0] = (dp[i][1][0] + dp[i - 1][0][0] + dp[i - 1][0][1]) % MOD;
        dp[i][1][1] = (dp[i][1][1] + dp[i - 1][1][0]) % MOD;
    }
    ll ans = dp[m][0][0] + dp[m][0][1] + dp[m][1][0] + dp[m][1][1];
    ans = ((ans - 2 % MOD) + MOD) % MOD;
    memset(dp, 0, sizeof(dp));
    dp[1][0][0] = dp[1][1][0] = 1;
    ll sub = 0;
    for (int i = 1; i <= n; i++) {
        dp[i][0][0] = (dp[i][0][0] + dp[i - 1][1][0] + dp[i - 1][1][1]) % MOD;
        dp[i][0][1] = (dp[i][0][1] + dp[i - 1][0][0]) % MOD;
        dp[i][1][0] = (dp[i][1][0] + dp[i - 1][0][0] + dp[i - 1][0][1]) % MOD;
        dp[i][1][1] = (dp[i][1][1] + dp[i - 1][1][0]) % MOD;
    }
    sub = dp[n][0][0] + dp[n][0][1] + dp[n][1][0] + dp[n][1][1];
    sub %= MOD;
    ans = (ans + sub) % MOD;
    printf("%lld", ans);
    return 0;
}