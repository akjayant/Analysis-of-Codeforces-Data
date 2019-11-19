#include <bits/stdc++.h>
using namespace std;
#define pb  push_back
#define ll  long long
#define vi  vector<ll >
#define vvi vector<vi >
#define all(x) x.begin(), x.end()

ll  inf = 1e17;
int n, A, B;
vvi g, c;
vi  u, z, h, col;

ll f(int a, int b) {
    vi co(3);
    co[0] = a;
    co[1] = b;
    co[2] = 3 - a - b;
    for (int i = 0; i < n; ++i)
        col[z[i]] = co[i % 3];
    ll res = 0;
    for (int i = 0; i < n; ++i)
        res += c[col[i]][i];
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    c.assign(3, vi(n));
    for (int t = 0; t < 3; ++t)
        for (int i = 0; i < n; ++i)
            cin >> c[t][i];
    g.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b; --a; --b;
        g[a].pb(b); g[b].pb(a);
    }
    h.assign(n + 5, 0);
    for (int i = 0; i < n; ++i)
        ++h[g[i].size()];
    if (!(h[1] == 2 && h[2] == n - 2)) {
        cout << -1;
        return 0;
    }
    int v = 0;
    while (g[v].size() != 1) ++v;
    z.assign(n, v);
    u.assign(n, 0); u[v] = 1;
    for (int e = 1; e < n; ++e) {
        v = z[e - 1];
        for (int i = 0; i < g[v].size(); ++i) {
            int to = g[v][i];
            if (u[to] == 0) {
                z[e] = to;
                u[to] = 1;
            }
        }
    }
    col.resize(n);
    ll res = inf;
    for (int a = 0; a < 3; ++a) {
        for (int b = 0; b < 3; ++b) {
            if (b == a) continue;
            ll cur = f(a, b);
            if (res > cur) {
                res = cur;
                A = a; B = b;
            }
        }
    }
    res = f(A, B);
    cout << res << "\n";
    for (int i = 0; i < n; ++i)
        cout << 1 + col[i] << " ";

    return 0;
}
