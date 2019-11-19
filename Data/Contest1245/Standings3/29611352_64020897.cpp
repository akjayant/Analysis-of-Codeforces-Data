/**
    *Makacha
**/
#include <bits/stdc++.h>
using namespace std;

template <typename T> inline void read (T &x) { bool b = 0; char c; while (!isdigit (c = getchar()) && c != '-');
if (c == '-') c = getchar(), b = 1; x = c - 48; while (isdigit(c = getchar())) x = (x << 3) + (x << 1) + c - 48; if (b) x = -x; }
template <typename T> inline void wrip(T x) { if (x > 9) wrip(x / 10); putchar(x%10 + 48); }
template <typename T> inline void write(T x) { if (x < 0) putchar('-'), x = -x; wrip(x);}
void reads(string &s) { char c; while (!isalpha(c = getchar())); s = c; while (isalpha(c = getchar())) s += c; }
typedef const int csint;

#define fi first
#define se second
#define mp make_pair
typedef long long ll;
typedef double ld;

const ld pi = acos(-1);
const int mod = 1e9 + 7;
const ll inf = 1e18;
const int N = 2011;
typedef pair <int, int> ii;
int n, cnt, x[N], y[N], pa[N];
ll res, c[N], k[N];
struct stc{
    ll cost;
    int u, v;
    stc() {
        u = v = cost = 0;
    }
    stc(ll _cost, int _u, int _v) {
        cost = _cost;
        u = _u;
        v = _v;
    }
};
vector <stc> ds;
vector <ii> edge;
vector <int> node;
bool cmp(stc a, stc b) {
    return a.cost < b.cost;
}
int root(int u) {
    return (pa[u] == 0) ? u : (pa[u] = root(pa[u]));
}
bool Dsu(int u, int v) {
    u = root(u);
    v = root(v);
    if (u == v)
        return false;
    pa[v] = u;
    return true;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifdef makacha
        freopen("m.inp", "r", stdin);
        freopen("m.out", "w", stdout);
    #endif // makacha
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> x[i] >> y[i];
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    for (int i = 1; i <= n; i++)
        cin >> k[i];
    for (int i = 1; i <= n; i++)
        ds.push_back(stc(c[i], n + 1, i));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            if (i == j)
                continue;
            ll cost = (k[i] + k[j]) * (abs(x[i] - x[j]) + abs(y[i] - y[j]));
            ds.push_back(stc(cost, i, j));
        }
    sort(ds.begin(), ds.end(), cmp);
    for (int i = 0; i < ds.size(); i++) {
        int u = ds[i].u,
            v = ds[i].v;
        if (Dsu(u, v)) {
            res += ds[i].cost;
            if (u == n + 1)
                node.push_back(v);
            else
                edge.push_back(mp(u, v));
        }
    }
    cout << res << '\n';
    cout << node.size() << '\n';
    for (int i = 0; i < node.size(); i++)
        cout << node[i] << ' ';
    cout << '\n' << edge.size() << '\n';
    for (int i = 0; i < edge.size(); i++)
        cout << edge[i].fi << ' ' << edge[i].se << '\n';
}
