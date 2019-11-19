#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second

using ll = long long;
using pii = pair <int, int>;

const int oo = INT_MAX;
const int SZ = 2e5 + 4;

int n;
int x[SZ], y[SZ];
ll c[SZ], k[SZ], sum;

void read() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        sum += c[i];
    }
    for (int j = 0; j < n; j++)
        cin >> k[j];
}

int p[SZ], god[SZ];
ll mn[SZ];

int get_p(int x) {
    if (p[x] == x) return x;
    p[x] = get_p(p[x]);
    return p[x];
}

ll unite(int a, int b) {
    a = get_p(a);
    b = get_p(b);

    if (a == b) return 0;

    p[a] = b;
    ll ret = max(mn[a], mn[b]);
    if (mn[a] < mn[b]) {
        mn[b] = mn[a];
        god[b] = god[a];
    }
    return ret;
}

ll get_cost(int a, int b) {
    a = get_p(a);
    b = get_p(b);
    if (a == b) return 0;
    return max(mn[a], mn[b]);
}

ll ans = 1ll * oo * oo;
ll res, ind;
vector <pair <ll, pair <int, int> > > ed;

void prep() {
    iota(p, p + n, 0);
    iota(god, god + n, 0);
    for (int i = 0; i < n; i++)
        mn[i] = c[i];
}

void solve() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            ll w = 1ll * (abs(x[i] - x[j]) + abs(y[i] - y[j])) * (k[i] + k[j]);
            ed.push_back({w, {i, j}});
        }
    sort(ed.begin(), ed.end());

    prep();

    ans = sum;
    ind = -1;

    for (int i = 0; i < ed.size(); i++) {
        auto e = ed[i];
        int ok = get_cost(e.S.F, e.S.S);
        if (ok > e.F) {
            res += e.F, sum -= ok;
            unite(e.S.F, e.S.S);
        }
        if (res + sum < ans) {
            ans = res + sum;
            ind = i;
        }
    }

    cout << ans << endl;
    prep();
    vector <pii> al;
    for (int i = 0; i <= ind; i++) {
        auto e = ed[i];
        int ok = get_cost(e.S.F, e.S.S);
        if (ok > e.F) {
            unite(e.S.F, e.S.S);
            al.push_back(e.S);
        }
    }
    vector <int> gs;
    for (int i = 0; i < n; i++) {
        if (p[i] == i) gs.push_back(god[i]);
    }
    cout << gs.size() << endl;
    for (auto t : gs)
        cout << t + 1 << ' ';
    cout << endl;

    cout << al.size() << endl;
    for (auto t : al)
        cout << t.F + 1 << ' ' << t.S + 1 << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    read();
    solve();
}
