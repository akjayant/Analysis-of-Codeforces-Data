#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define pdd pair<double, double>
#define pii pair<int, int>
//#define gcd __gcd

#ifdef LOCAL
#define DEBUG 1
#else
#define DEBUG 0
#endif
#define fast if (!DEBUG) {cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);}
#define debug if (DEBUG) cout
#define endl '\n'

typedef long long ll;
using namespace std;

const int N = 100001;
ll M = 0;

int n, c[N][4], s[N], cl[N];
vector<pair<ll, pair<int, int>>> ans_v;
vector<int> g[N];

ll dfs(int v, int p1, int p2, int i, ll r) {
    cl[v] = cl[p1] ^ cl[p2];
    debug << "DFS " << v << " " << cl[v] << endl;
    ll res = r + c[v][cl[v]];

    if (i == n) return res;

    for (int u : g[v]) {
        debug << "U " << u << endl;
        if (u != p1)
            return dfs(u, v, p1, i + 1, res);
    }
}

main() { fast;
    cin >> n;

    for (int i = 0; i < n; i++) cin >> c[i][1];
    for (int i = 0; i < n; i++) cin >> c[i][2];
    for (int i = 0; i < n; i++) cin >> c[i][3];

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[v].pb(u);
        g[u].pb(v);
        s[u]++; s[v]++;
    }

    int p1;
    for (int i = 0; i < n; i++) {
        if (s[i] > 2) {
            cout << -1;
            return 0;
        }

        if (s[i] == 1) p1 = i;
    }

    int p2 = g[p1][0];
    int p3 = (g[p2][0] == p1 ? g[p2][1] : g[p2][0]);

    cl[p1] = 1; cl[p2] = 2; ans_v.pb({dfs(p3, p2, p1, 3, c[p1][cl[p1]] + c[p2][cl[p2]]), {cl[p1], cl[p2]}});
    cl[p1] = 2; cl[p2] = 1; ans_v.pb({dfs(p3, p2, p1, 3, c[p1][cl[p1]] + c[p2][cl[p2]]), {cl[p1], cl[p2]}});
    cl[p1] = 1; cl[p2] = 3; ans_v.pb({dfs(p3, p2, p1, 3, c[p1][cl[p1]] + c[p2][cl[p2]]), {cl[p1], cl[p2]}});
    cl[p1] = 3; cl[p2] = 1; ans_v.pb({dfs(p3, p2, p1, 3, c[p1][cl[p1]] + c[p2][cl[p2]]), {cl[p1], cl[p2]}});
    cl[p1] = 2; cl[p2] = 3; ans_v.pb({dfs(p3, p2, p1, 3, c[p1][cl[p1]] + c[p2][cl[p2]]), {cl[p1], cl[p2]}});
    cl[p1] = 3; cl[p2] = 2; ans_v.pb({dfs(p3, p2, p1, 3, c[p1][cl[p1]] + c[p2][cl[p2]]), {cl[p1], cl[p2]}});

    sort(ans_v.begin(), ans_v.end());

    cl[p1] = ans_v[0].se.fi;
    cl[p2] = ans_v[0].se.se;
    cout << dfs(p3, p2, p1, 3, c[p1][cl[p1]] + c[p2][cl[p2]]) << endl;
    for (int i = 0; i < n; i++)
        cout << cl[i] << " ";
}
