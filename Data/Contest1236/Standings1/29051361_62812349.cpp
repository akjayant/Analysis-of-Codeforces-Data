#include <bits/stdc++.h>
#define FOR(i, l, r) for(ll i = (ll)l; i <= (ll)r; ++i)
#define REP(i, r) for(ll i = (ll)0; i < (ll)r; ++i)
#define FORD(i, l, r) for(ll i = (ll)l; i >= (ll)r; --i)
#define X first
#define Y second

using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
const ll Nmax = 1e5 + 112;
const ll inf = 1e9 + 112;

ll n, m, k, ans, U, D, L, R;
vector<ll> forbidX[Nmax], forbidY[Nmax];
deque<ll> r[Nmax], c[Nmax];
map<ii, bool> mp;

void solve(ll u, ll v, ll dir) {
    if (u < U || u > D || v < L ||v > R) return;
//    cout << u << ' ' << v << ' ' << dir << '\n';
    if (dir == 0) {
        ll mn = inf;
        while(r[u].size() && r[u].back() > v) {
            mn = min(mn, r[u].back() - 1);
            r[u].pop_back();
        }
        mn = min(mn, R - 1);
        if (mn == v && !(u == 1 && v == 1 && dir == 0)) return;
//        if (mn <= L || mn >= R || mn <= U || mn >= D) return;
        U = max(U, u);
        R = mn;
        ans += mn - v;
        if (mp[{u + 1, mn}]) return;
        return solve(u, mn, 1);
    } else if (dir == 1) {
        ll mn = inf;
        while(c[v].size() && c[v].back() > u) {
            mn = min(mn, c[v].back() - 1);
            c[v].pop_back();
        }
        mn = min(mn, D - 1);
        if (mn == u && !(u == 1 && v == 1 && dir == 0)) return;
//        if (mn <= L || mn >= R || mn <= U || mn >= D) return;
        R = min(R, v);
        D = mn;
        ans += mn - u;
        if (mp[{mn, v - 1}]) return;
        return solve(mn, v, 2);
    } else if (dir == 2) {
        ll mx = -1;
        while(r[u].size() && r[u].front() < v) {
            mx = max(mx, r[u].front() + 1);
            r[u].pop_front();
        }
        mx = max(mx, L + 1);
        if (mx == v && !(u == 1 && v == 1 && dir == 0)) return;
//        if (mx <= L || mx >= R || mx <= U || mx >= D) return;
        D = min(D, u);
        L = mx;
        ans += v - mx;
        if (mp[{u - 1, mx}]) return;
        return solve(u, mx, 3);
    } else if (dir == 3) {
        ll mx = -1;
        while(c[v].size() && c[v].front() < u) {
            mx = max(mx, c[v].front() + 1);
            c[v].pop_front();
        }
        mx = max(mx, U + 1);
        if (mx == u && !(u == 1 && v == 1 && dir == 0)) return;
//        if (mx <= L || mx >= R || mx <= U || mx >= D) return;
        L = max(L, v);
        U = mx;
        ans += u - mx;
        if (mp[{mx, v + 1}]) return;
        return solve(mx, v, 0);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifdef yt
        freopen("in.inp", "r", stdin);
    #endif
    cin >> n >> m >> k;
    FOR(i, 1, k) {
        ll u, v; cin >> u >> v;
        forbidX[u].push_back(v);
        forbidY[v].push_back(u);
        mp[{u, v}] = true;
    }
    FOR(i, 1, n) {
        sort(forbidX[i].begin(), forbidX[i].end());
        for(ll x: forbidX[i]) r[i].push_back(x);
    }
    FOR(j, 1, m) {
        sort(forbidY[j].begin(), forbidY[j].end());
        for(ll x: forbidY[j]) c[j].push_back(x);
    }
    U = 0, D = n + 1, L = 0, R = m + 1;
    solve(1, 1, 0);
//    cout << ans + 1 << '\n';
    if (ans + 1 == n * m - k) cout << "yes";
    else cout << "no";
}
