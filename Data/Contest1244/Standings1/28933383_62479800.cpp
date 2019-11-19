#include <bits/stdc++.h>

/*
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("-O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
*/

#define mp make_pair
#define ll long long
#define ld long double
#define pb push_back
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fs first
#define sc second
#define getfiles ifstream cin("input.txt"); ofstream cout("output.txt");
#define endl '\n'
#define con continue
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()

const ll INF = 2000000005;
const ll BIG_INF = 2000000000000000005;
const ll mod = 1000000007;
const ll P = 31;
const ld PI = 3.141592653589793238462643;
const double eps = 1e-9;

using namespace std;

vector< pair<ll, ll> > dir = {
    {
        -1, 0
    },
    {
        0, 1
    },
    {
        1, 0
    },
    {
        0, -1
    }
};

bool valid(ll x, ll y, ll n, ll m) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

mt19937 rng(1999999973);

const ll N = 100000 + 5;

ll c[3][N], deg[N], color[N], n, root, ans = BIG_INF;
vector<ll> g[N];

vector<ll> per, best_per;

ll dfs(ll v, ll p, ll pos, vector<ll> &perm) {
    ll res = c[perm[pos]][v];
    color[v] = perm[pos];
    for (ll i = 0; i < g[v].size(); i++) {
        ll to = g[v][i];
        if (to == p)
            continue;
        res += dfs(to, v, (pos + 1) % 3, perm);
    }
    return res;
}

signed main() {
    fast_io;

    cin >> n;

    for (ll i = 0; i < 3; i++) {
        for (ll j = 0; j < n; j++) {
            cin >> c[i][j];
        }
    }

    for (ll i = 0; i < n - 1; i++) {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
        deg[u]++;
        deg[v]++;

        if (deg[u] >= 3) {
            cout << -1;
            return 0;
        }
        if (deg[v] >= 3) {
            cout << -1;
            return 0;
        }
    }

    for (ll i = 0; i < n; i++) {
        if (deg[i] == 1) {
            root = i;
            break;
        }
    }

    per = best_per = {0, 1, 2};

    do {
        ll cost = dfs(root, -1, 0, per);
        if (cost < ans) {
            ans = cost;
            best_per = per;
        }
    } while(next_permutation(per.begin(), per.end()));

    dfs(root, -1, 0, best_per);
    cout << ans << endl;
    for (ll i = 0; i < n; i++)
        cout << color[i] + 1 << " ";

    return 0;
}
