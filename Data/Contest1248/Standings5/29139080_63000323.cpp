// !FromHere
#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_cxx;

typedef double db;
typedef long long ll;
typedef pair<db, db> pdd;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef unsigned long long ull;

#define F          first
#define S          second
#define pnl        printf("\n")
#define sz(x)      (int)x.size()
#define sf(x)      scanf("%d",&x)
#define pf(x)      printf("%d\n",x)
#define all(x)     x.begin(),x.end()
#define rall(x)    x.rbegin(),x.rend()
#define rep(i, n)  for(int i = 0; i < n; ++i)

const db eps = 1e-9;
const db pi = acos(-1);
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1000 * 1000 * 1000 + 7;

int n, m, N;
int dp[200005][3][3][3];
int fac[200005];

int solve(int i, int l1, int l2, int gd) {
    if (i == N) return gd;
    int &ret = dp[i][l1][l2][gd];
    if (~ret) return ret;
    ret = 0;
    // color me 0
    if (l1 != 0 || (l1 == 0 && l2 != 0)){
        ret += solve(i + 1, l2, 0, gd || l2 == 0);
        if (ret >= mod) ret -= mod;
    }
    // color me 1
    if (l1 != 1 || (l1 == 1 && l2 != 1)){
        ret += solve(i + 1, l2, 1, gd || l2 == 1);
        if (ret >= mod) ret -= mod;
    }
    return ret;
}

int main() {
    cin >> n >> m;
    memset(dp, -1, sizeof dp);
    if (min(n, m) == 1) {
        N = max(n, m);
        cout << solve(0, 2, 2, 1) << endl;
        return 0;
    }
    fac[0] = 1;
    for (int i = 1; i <= n + m; ++i) {
        fac[i] = (fac[i - 1] * 2LL) % mod;
    }
    if (n > m) swap(n ,m);
    N = m;
    ll ans = solve(0, 2, 2, 0);
    N = n;
    memset(dp, -1, sizeof dp);
    ans += solve(0, 2, 2, 1);
    if (ans >= mod) ans -= mod;
    cout << ans << endl;
    return 0;
}
