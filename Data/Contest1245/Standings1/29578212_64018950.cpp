#include <bits/stdc++.h>
#define ll long long
using namespace std;

template <class T>
inline bool scan(T &ret){
    char c;
    int sgn;
    if (c = getchar(), c == EOF) return 0; //EOF
    while (c != '-' && (c < '0' || c > '9')) c = getchar();
    sgn = (c == '-') ? -1 : 1;
    ret = (c == '-') ? 0 : (c - '0');
    while (c = getchar(), c >= '0' && c <= '9') ret = ret * 10 + (c - '0');
    ret *= sgn;
    return 1;
}

const ll mod = 1e9+7;
const int maxn = 40;

ll qp(ll x, ll n) {
    ll res = 1; x %= mod;
    while (n > 0) {
        if (n & 1) res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}

ll dp[maxn][2][2];
int a[maxn], b[maxn];

void cal(int *xt, ll x) {
    int has = 0;
    while (x) {
        xt[has++] = x % 2;
        x /= 2;
    }
}

ll dfs(int pos, int o1, int o2) {
    if (pos < 0) return 1;
    ll &t = dp[pos][o1][o2];
    if (t != -1) return t;
    int up1 = o1 ? a[pos] : 1;
    int up2 = o2 ? b[pos] : 1;
    ll res = 0;
    for (int i = 0; i <= up1; ++i) {
        for (int j = 0; j <= up2; ++j) {
            if (i == 1 && j == 1) continue;
            res += dfs(pos - 1, o1 && i == up1, o2 && j == up2);
        }
    }
    return t = res;
}

ll solve(ll x, ll y) {
    memset(dp, -1ll, sizeof dp);
    for (int i = 0; i < 33; ++i) a[i] = b[i] = 0;
    cal(a, x);
    cal(b, y);
    return dfs(32, 1, 1);
}

int main(int argc, char *argv[]) {
    int T;
    scanf("%d", &T);
    ll x, y;
    for (int kase = 1; kase <= T; ++kase) {
        scanf("%lld%lld", &x, &y);
        ll res = solve(y, y) - 2 * solve(x - 1, y) + solve(x - 1, x - 1);
        printf("%lld\n", res);
    }
    return 0;
}