#include<bits/stdc++.h>
#define TASK "ABC"
#define BASIC \
		freopen(TASK".inp", "r", stdin); \
		freopen(TASK".out", "w", stdout);
#define BASE ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
#define maxn 100005

using namespace std;
typedef long long ll;

ll n;
ll col[maxn][3];
vector < ll > g[maxn];
ll deg[maxn];
ll a[maxn], ans[maxn];
ll d[maxn][3][3];

int main(){
    BASE
    cin >> n;
    for (ll j = 0; j < 3; ++j)
    for (ll i = 1; i <= n; ++i)
        cin >> col[i][j];

    for (ll i = 1; i < n; ++i){
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u] ++; deg[v] ++;
    }
    memset(d, 0x3f, sizeof d);
    ll root = 0;
    for (ll i = 1; i <= n; ++i){
        if (deg[i] == 1) root = i;
        if (deg[i] > 2) return cout << -1, 0;
    }
    a[1] = root;
    for (ll i = 1; i <= n; ++i)
        for (auto j : g[a[i]])
            if (j != a[i - 1]) a[i + 1] = j;

    for (ll i = 0; i < 3; ++i)
    for (ll j = 0; j < 3; ++j)
        if (i != j)
        d[a[1]][i][j] = col[a[1]][i],
        d[a[2]][i][j] = col[a[2]][i] + col[a[1]][j];

    for (ll u = 3; u <= n; ++u)
    for (ll i = 0; i < 3; ++i)
    for (ll j = 0; j < 3; ++j)
        if (i != j)
        d[a[u]][i][j] = d[a[u - 1]][j][3 - i - j] + col[a[u]][i];
    ll x = 0, y = 1;
    for (ll i = 0; i < 3; ++i)
    for (ll j = 0; j < 3; ++j)
        if (i != j)
        if (d[a[n]][i][j] < d[a[n]][x][y]) x = i, y = j;

    cout << d[a[n]][x][y] << '\n';
    for (ll i = 1; i <= n; ++i)
        if (n % 3 == i % 3) ans[a[i]] = x;
        else if ((n - 1) % 3 == i % 3) ans[a[i]] = y;
        else ans[a[i]] = 3 - x- y;
    for (ll i = 1; i <= n; ++i)
        cout << ans[i] + 1 << ' ';
    return 0;
}
