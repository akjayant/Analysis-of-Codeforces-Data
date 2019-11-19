#include<bits/stdc++.h>
#define TASK "ABC"
#define BASIC \
		freopen(TASK".inp", "r", stdin); \
		freopen(TASK".out", "w", stdout);
#define BASE ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
#define maxn 2003

using namespace std;
typedef long long ll;

ll n;
ll x[maxn], y[maxn], c[maxn], k[maxn], d[maxn], tem[maxn], vis[maxn * maxn];
pair < ll, pair < ll, ll > > e[maxn * maxn];

ll root(ll u){
    return u == d[u] ? u : d[u] = root(d[u]);
}

int main(){
     BASE
    cin >> n;
    for (ll i = 0; i < n; ++i)
        cin >> x[i] >> y[i];

    ll ans = 0;
    for (ll i = 0; i < n; ++i){
        cin >> c[i];
        d[i] = i;
    }
    for (ll i = 0; i < n; ++i)
        cin >> k[i];

    int ne = 0;
    for (ll i = 0; i < n; ++i)
        for (ll j = i + 1; j < n; ++j)
            e[ne++] = {(k[i] + k[j]) * (abs(x[i] - x[j]) + abs(y[i] - y[j])), {i, j}};


    for (int i = 0; i < n; ++i)
        e[ne++] = {c[i], {n, i}};
    d[n] = n;

    sort(e, e + ne);

    int se = 0;
    for (ll i = 0; i < ne; ++i){
        ll u = e[i].second.first, v = e[i].second.second, w = e[i].first;

        if (u == v) continue;
        ll ru = root(u), rv = root(v);
        if (ru == rv) continue;
        if (u == n || v == n) se++;
        vis[i] = 1;
        ans += w;
        d[ru] = rv;
    }

    cout << ans << '\n';

    cout << se << '\n';

    for (int i = 0; i < ne; ++i)
        if (vis[i] && (e[i].second.first == n || e[i].second.second == n)) cout << e[i].second.first + e[i].second.second - n + 1 << ' ';
    cout << '\n';

    cout << n - se << '\n';
    for (ll i = 0; i < n * n; ++i)
        if (vis[i] && e[i].second.first != n && e[i].second.second != n)
            cout << e[i].second.first + 1 << ' ' << e[i].second.second + 1 << '\n';


    return 0;
}
