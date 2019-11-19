#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define ff first
#define ss second
#define sz(vv) (int) vv.size()
#define all(a) a.begin(), a.end()
#define lb lower_bound
#define ub upper_bound
#define _ << " " <<

#define int ll

int p[37001];
int r[37001];

struct edge {
    ll a, b, w;
    edge() {};
    edge(ll a, ll b, ll w): a(a), b(b), w(w) {}
};

bool operator < (edge x, edge y) {
    return x.w < y.w;
}

vector<edge> g;

int color(int v) {
    if (p[v] == v) {
        return v;
    }
    return p[v] = color(p[v]);
}

void unite(int a, int b) {
    a = color(a);
    b = color(b);
    if (a == b) {
        return;
    }
    if (r[a] < r[b]) {
        swap(a, b);
    }
    p[b] = a;
    r[a] += r[b];
}


void solve() {
    for (int i = 0; i < 6120; ++i) {
        p[i] = i;
        r[i] = 1;
    }
    int n;
    cin >> n;
    //cout << "OK0" << endl;
    vector<pair<int, int> > vertex(n);
    for (int i = 0; i < n; ++i) {
        cin >> vertex[i].ff >> vertex[i].ss;
    }
    //cout << "OK1" _ n << endl;
    vector<int> c(n);
    vector<int> k(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    //cout << "OK2" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> k[i];
    }
    int a, b, w;
    for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
        a = i;
        b = j;
        w = (abs(vertex[i].ff - vertex[j].ff) + abs(vertex[i].ss - vertex[j].ss)) * (k[i] + k[j]);
        g.push_back(edge(a, b, w));
    }}
    for (int i = 0; i < n; ++i) {
        g.push_back(edge(i, 5000, c[i]));
    }
    sort(g.begin(), g.end());
    ll res = 0;
    vector<int> v;
    vector<pair<int, int>> e;
    int x, y;
    for (int i = 0; i < g.size(); ++i) {
        //cout << "OKKK" << endl;
        a = g[i].a;
        a = color(a);
        b = g[i].b;
        b = color(b);
        //cout << a << " " << b  << " " << i<< endl;
        if (a != b) {
            unite(a, b);
            res += g[i].w;
            if (g[i].b == 5000) {
                v.push_back(g[i].a + 1);
            }
            else {
                e.push_back({g[i].a + 1, g[i].b + 1});
            }
        }
    }
    cout << res << endl;
    cout << v.size() << endl;
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    } cout << endl;
    cout << e.size() << endl;
    for (int i = 0; i < e.size(); ++i) {
        cout << e[i].ff _ e[i].ss << "\n";
    }
}

signed main() {
///#define TASK ""
#if !defined(LOCAL) && defined(TASK)
    freopen(TASK".in", "r", stdin);
    freopen(TASK".out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tests = 1;
    ///cin >> tests;
    while (tests--) {
        solve();
    }
    return 0;
}
