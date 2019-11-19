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

int n;
ll col[3][100005];
int ans[100005];
vector<int> adj[100005];
ll dp[100005][4][4];
int st = -1, ed = -1;

vector<int> tmp;
ll solve(int u, int p1, int p2, int prv) {
    ll &ret = dp[u][p1][p2];
    if (~ret) return ret;
    ret = LL_INF;
    if (p1 != 0 && p2 != 0) {
        if (u == ed) ret = min(ret, col[0][u]);
        for (auto v : adj[u]) {
            if (v == prv) continue;
            ret = min(ret, solve(v, 0, p1, u) + col[0][u]);
        }
    }
    if (p1 != 1 && p2 != 1) {
        if (u == ed) ret = min(ret, col[1][u]);
        for (auto v : adj[u]) {
            if (v == prv) continue;
            ret = min(ret, solve(v, 1, p1, u) + col[1][u]);
        }
    }
    if (p1 != 2 && p2 != 2) {
        if (u == ed) ret = min(ret, col[2][u]);
        for (auto v : adj[u]) {
            if (v == prv) continue;
            ret = min(ret, solve(v, 2, p1, u) + col[2][u]);
        }
    }
    return ret;
}

void trace(int u, int p1, int p2, int prv) {
    ll &ret = dp[u][p1][p2];
    if (p1 != 0 && p2 != 0) {
        if (u == ed && ret == col[0][u]) {
            ans[u] = 0;
            return;
        }
        for (auto v : adj[u]) {
            if (v == prv) continue;
            if (ret == solve(v, 0, p1, u) + col[0][u]) {
                ans[u] = 0;
                trace(v, 0, p1, u);
                return;
            }
        }
    }
    if (p1 != 1 && p2 != 1) {
        if (u == ed && ret == col[1][u]) {
            ans[u] = 1;
            return;
        }
        for (auto v : adj[u]) {
            if (v == prv) continue;
            if (ret == solve(v, 1, p1, u) + col[1][u]) {
                ans[u] = 1;
                trace(v, 1, p1, u);
                return;
            }
        }
    }
    if (p1 != 2 && p2 != 2) {
        if (u == ed && ret == col[2][u]) {
            ans[u] = 2;
            return;
        }
        for (auto v : adj[u]) {
            if (v == prv) continue;
            if (ret == solve(v, 2, p1, u) + col[2][u]) {
                ans[u] = 2;
                trace(v, 2, p1, u);
                return;
            }
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < 3; ++i)
        for (int j = 1; j <= n; ++j)
            scanf("%lld", &col[i][j]);
    for (int i = 1, u, v; i < n; ++i) {
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
        if (sz(adj[u]) > 2)
            return !printf("-1\n");
        if (sz(adj[v]) > 2)
            return !printf("-1\n");
    }
    for (int i = 1; i <= n; ++i)
        if (sz(adj[i]) == 1) {
            if (st == -1) st = i;
            ed = i;
        }
    memset(dp, -1, sizeof dp);
    cout << solve(st, 3, 3, -1) << endl;
    trace(st, 3, 3, -1);
    for (int i = 1; i <= n; ++i)
        printf("%d%c", ans[i]+1, " \n"[i==n]);
    return 0;
}
