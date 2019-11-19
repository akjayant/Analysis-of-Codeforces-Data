#include <bits/stdc++.h>
 
#define ll long long
#define ull unsigned ll
#define vi vector<ll>
#define vvi vector<vi>
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define ld long double
#define pii pair<ll, ll>
#define mt make_tuple
#define mn(a, b) a = min(a, b)
#define mx(a, b) a = max(a, b)
 
using namespace std;

const ll INF = (ll)2e9;
const ll inf = (ll)2e18;
const ld eps = (ld)1e-8;
const ll mod = (ll)1e9 + 7;
const ll MAXN = (ll)100010;
const ll MAXC = (ll)1e6 + 1;
const ll MAXE = (ll)2000;
const ll MAXLOG = 19;
const ll maxlen = (ll)1e5;
const ll asci = (ll)256;
const ll block = 320;
//
/*#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<
ll,
null_type,
less<ll>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;*/
 
template <class T>
istream& operator >>(istream &in, vector<T> &arr){
     for (T &cnt : arr) {
        in >> cnt;
    }
    return in;
};

struct dsu{
    vi p, sz; int n;

    dsu(int _n) {
        n = _n;
        p.resize(n);
        sz.assign(n, 1);
        for (int i = 0; i < n; ++i) p[i] = i;
    }

    int get(int v) {
        if (p[v] == v) return v;
        return (p[v] = get(p[v]));
    }

    bool unite(int v, int u) {
        v = get(v);
        u = get(u);
        if (v == u) return 0;
        if (sz[v] > sz[u]) {
            p[u] = v;
            sz[v] += sz[u];
        } else {
            p[v] = u;
            sz[u] += sz[v];
        }
        return 1;
    }
};

vi graph[MAXN];

void solve() {
    int n, m; cin >> n >> m;
        vi cnt(n);
        vi used(n);
        dsu snm(n);
        for (int i = 0; i < m; ++i) {
            int v, u; cin >> v >> u;
            v--, u--;
            graph[v].push_back(u);
            graph[u].push_back(v);
            cnt[v]++; cnt[u]++;
        }
        int j = 0;
        vi one(n);
        vi check;
        for (int i = 0; i < n; ++i) {
            if (cnt[i] < cnt[j]) j = i;
        }
        for (int u : graph[j]) {
            one[u] = 1;
            check.push_back(u);
        }
        for (int u = 0; u < n; ++u) {
            if (!one[u]) snm.unite(j, u);
        }
        for (int v : check) {
            one.assign(n, 0);
            for (int u : graph[v]) one[u] = 1;
            for (int u = 0; u < n; ++u) if (!one[u]) snm.unite(v, u);
        }
        int ans = 0;
        for (int v = 0; v < n; ++v) {
            for (int u : graph[v]) {
                ans += snm.unite(v, u);
            }
        }
        cout << ans;
}
 
int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#endif
    cout.precision(50);
    solve();
 
    return 0;
}