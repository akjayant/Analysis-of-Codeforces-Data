#include <bits/stdc++.h>
#define FOR(i, l, r) for(int i = (int)l; i <= (int)r; ++i)
#define REP(i, r) for(int i = (int)0; i < (int)r; ++i)
#define FORD(i, l, r) for(int i = (int)l; i >= (int)r; --i)
#define X first
#define Y second

using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;
const int Nmax = 1e5 + 112;;
const ll MOD = 1e9 + 7;

int n, lab[Nmax];
ll c[Nmax], k[Nmax], ans;
ii p[Nmax];
vector<ll> sup;
vector<ii> res;

struct edge {
    ll w, u, v;
};
vector<edge> e;

bool cmp(edge a, edge b) {
    return a.w < b.w;
}

int findlab(int u) { return lab[u] <= 0 ? u : lab[u] = findlab(lab[u]); }

void uni(int u, int v) {
    if (lab[u] < lab[v]) {
        lab[v] = u;
    } else {
        if (lab[u] == lab[v]) --lab[v];
        lab[u] = v;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifdef yt
        freopen("in.inp", "r", stdin);
    #endif // yt
    cin >> n;
    FOR(i, 1, n) {
        cin >> p[i].X >> p[i].Y;
    }
    FOR(i, 1, n) {
        cin >> c[i];
        e.push_back({c[i], 0, i});
    }
    FOR(i, 1, n) {
        cin >> k[i];
    }
    FOR(i, 1, n) FOR(j, i + 1, n) {
        e.push_back({(k[i] + k[j]) * (abs(p[i].X - p[j].X) + abs(p[i].Y -  p[j].Y)), i, j});
    }
    sort(e.begin(), e.end(), cmp);
    REP(i, e.size()) {
        ll u = e[i].u, v = e[i].v, w = e[i].w;
        int s = findlab(u), t = findlab(v);
        if (s != t) {
            uni(s, t);
            ans += w;
            if (u == 0) sup.push_back(v);
            else res.push_back({u, v});
        }
    }
    cout << ans << '\n';
    cout << sup.size() << '\n';
    for(int x: sup) cout << x << ' ';
    cout << '\n';
    cout << res.size() << '\n';
    for(auto x: res) cout << x.X << ' ' << x.Y << '\n';
}
