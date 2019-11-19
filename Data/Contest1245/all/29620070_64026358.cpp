// 巨菜的ACMer-Happy233

#include <bits/stdc++.h>

using namespace std;

//-----
typedef double db;
typedef long long ll;
typedef unsigned int ui;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define fi first
#define se second
#define pw(x) (1ll << (x))
#define bt(x, k) (((x) >> k) & 1)
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define rep(i, l, r) for(int i=(l);i<(r);++i)
#define per(i, l, r) for(int i=(r)-1;i>=(l);--i)
#define mst(t, v, n) memset(t, v, sizeof(decltype(*(t))) * (n))
#define sf(x) scanf("%d", &(x))
#ifndef ACM_LOCAL
#pragma GCC optimize(2)
#define endl '\n'
#endif

const int N = 100005;
bool vis[N];
pii p[N];
int c[N], k[N], f[N];
ll cost[N];

void solve() {
    int n;
    while (cin >> n) {
        mst(vis, false, n);
        mst(cost, 0, n);
        rep(i, 0, n) {
            cin >> p[i].fi >> p[i].se;
        }
        rep(i, 0, n) cin >> c[i];
        rep(i, 0, n) cin >> k[i];
        priority_queue<pii, vector<pii>, greater<pii>> q;
        rep(i, 0, n) {
            q.push({c[i], i});
            cost[i] = c[i];
            f[i] = i;
        }
        while (!q.empty()) {
            int u = q.top().se;
            int cc = q.top().fi;
            q.pop();
            if (cc > cost[u]) continue;
            vis[u] = true;
            for (int i = 0; i < n; i++) {
                if (i == u) continue;
                ll dx = abs(p[i].fi - p[u].fi);
                ll dy = abs(p[i].se - p[u].se);
                ll ds = dx + dy;
                ll ks = k[i] + k[u];
                if (!vis[i] && ds * ks < cost[i]) {
                    cost[i] = ds * ks;
                    q.push({cost[i], i});
                    f[i] = u;
                }
            }
        }
        ll ans = accumulate(cost, cost + n, 0ll);
        cout << ans << endl;
        vector<int> cr;
        rep(i, 0, n) {
            if (f[i] == i)cr.push_back(i + 1);
        }
        cout << cr.size() << endl;
        rep(i, 0, sz(cr)) {
            cout << cr[i] << " \n"[i + 1 == sz(cr)];
        }
        cout << (n - cr.size()) << endl;
        rep(i, 0, n) {
            if (f[i] != i) {
                cout << f[i] + 1 << ' ' << i + 1 << endl;
            }
        }
    }
}

int main() {
#ifdef ACM_LOCAL
    freopen("./data/std.in", "r", stdin);
    // freopen("./data/std.out", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#endif

#ifdef ACM_LOCAL
    auto start = clock();
#endif
    int t = 1;
//    cin >> t;
    while (t--)
        solve();
#ifdef ACM_LOCAL
    auto end = clock();
    cerr << "Run Time: " << double(end - start) / CLOCKS_PER_SEC << "s" << endl;
#endif
    return 0;
}