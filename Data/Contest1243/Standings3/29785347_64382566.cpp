#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair <ll, ll> ii;
typedef pair <ll, ii> iii;

const ll N = 1e6 + 5;
const ll INF = 1e9 + 7;

ll n, m, kq = 0, dem[N], d[N];

set <ll> a[N];

int main() {
    //freopen("1243D.INP", "r", stdin);
    //freopen("1243D.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    while (m--) {
        ll x, y; cin >> x >> y;
        a[x].insert(y); a[y].insert(x);
        dem[x]++; dem[y]++;
    }
    //********************
    ll minn = INF, r = 0;
    for (ll i = 1; i <= n; i++)
        if (minn > dem[i]) {
            minn = dem[i];
            r = i;
        }
    multiset <ll> S; S.clear();
    for (ll i = 1; i <= n; i++) if (i != r) S.insert(i);
    priority_queue <ii, vector <ii>, greater <ii> > Q;
    Q.push(ii(0, r));
    fill(d + 1, d + n + 1, INF); d[r] = 0;
    while (not Q.empty()) {
        ll u = Q.top().second, du = Q.top().first;
        Q.pop();
        if (du != d[u]) continue;
        kq += d[u]; d[u] = 0;
        vector <ll> V; V.clear();
        for (auto v : S) if (a[u].find(v) == a[u].end() && d[v] > 0) {
            d[v] = 0;
            Q.push(ii(d[v], v));
            V.push_back(v);
        }
        for (auto it : V) if (S.find(it) != S.end()) S.erase(S.find(it));
        for (auto v : a[u]) if (d[v] > 1) {
            d[v] = 1;
            Q.push(ii(d[v], v));
        }
    }
    //********************
    cout << kq;
    return 0;
}
