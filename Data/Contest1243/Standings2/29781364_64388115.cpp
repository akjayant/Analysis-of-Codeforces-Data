#include <bits/stdc++.h>
using namespace std;

#define taskname "TEST"
typedef long long ll;
typedef long double ld;
typedef pair <int, int> ii;

const int INF = 1e9 + 7;
const int N = 1e5 + 5;

int n, m, res = 0, cnt[N], d[N];
set <int> a[N];

void inp() {
    cin >> n >> m;
}
void solve() {
    while (m--) {
        ll x, y; cin >> x >> y;
        a[x].insert(y); a[y].insert(x);
        cnt[x]++; cnt[y]++;
    }
    ll minn = INF, r = 0;
    for (ll i = 1; i <= n; i++)
        if (minn > cnt[i]) {
            minn = cnt[i];
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
        res += d[u];
        d[u] = 0;
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
}
void out() {
    cout << res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
  //  freopen(taskname".INP", "r", stdin);
  //  freopen(taskname".OUT", "w", stdout);
    inp();
    solve();
    out();
}
